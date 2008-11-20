package api;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

import processor.IndexedDocumentChecker;
import api.dao.documents.DocumentsDictionary;
import api.query.tree.Query;
import app.query.QueryWord;
import app.query.parser.QueryParser;
import app.query.parser.QueryWordParser;
import app.query.parser.exception.ParserException;
import app.query.tree.AbstractQuery;
import dto.DocumentDto;
import exceptions.BusinessException;

public class QueryEngine implements IQueryEngine {

	private Index indice;
	private DocumentsDictionary dicc;
	private QueryParser queryParser;
	
	class NewDocumentInsert implements DocumentInsert {
		private Integer docid;
		private Index index;
		
		public NewDocumentInsert ( Integer docid, Index index ) {
			this.docid = docid;
			this.index = index;
		}
		
		public void insertWord(String word) throws BusinessException {
			index.insertWord(word, docid);
		}

		public void flush() {
			// Nada por hacer.			
		}
		
	}
	
	class DefaultQueryWord extends QueryWord {

		public DefaultQueryWord(String str) {
			super(str);
		}
		public Iterator<Integer> execute() {
			try {
				return QueryEngine.this.queryWord( this.getWord() );
			} catch (BusinessException e) {
			}
			List<Integer> lista=new ArrayList<Integer>();
			return lista.iterator();
		}
		
	}
	
	class DefaultQueryWordParser extends QueryWordParser {

		@Override
		public QueryWord create(String word) {
			return new DefaultQueryWord(word);
		}
		
	}
	
	private Iterator<Integer> queryWord( String word ) throws BusinessException {
		return indice.getDocuments(word).iterator();
				
	}
	

	protected QueryEngine(Index index,DocumentsDictionary dictionary){
		dicc=dictionary;
		indice=index;
		
		queryParser = new QueryParser();
		queryParser.addCustomParser(new DefaultQueryWordParser() );
		
	}
	
	public List<DocumentDto> executeQuery(String consulta) throws BusinessException{
		
		try {
			Query query = queryParser.parse(consulta);
			
			List<DocumentDto> listaRet=new ArrayList<DocumentDto>();
			Iterator<Integer> documentos = query.execute();
			
			while (documentos.hasNext() ) { 
				Integer docId = documentos.next();
				DocumentDto dtoAux=dicc.getDocument(docId);
				dtoAux.setDocumentId(docId);
				listaRet.add(dtoAux);
			}
			
			return listaRet;
		} catch (ParserException e) {
			throw new BusinessException("Error al parsear la query", e);
		}
		
	}
	

//	public int countExecuteQuery(String consulta ) throws BusinessException {
//		List<DocumentDto> listaRet=new ArrayList<DocumentDto>();
//		
//		for(Integer docId : indice.getDocuments(consulta)) {
//			listaRet.add(dicc.getDocument(docId));
//		}
//
//		return listaRet.size();
//	}
	
	public DocumentInsert prepareDocumentInsert( String documento ) throws BusinessException{
		// insertar el documento en el diccionario
		
		Integer id = dicc.insertDocument(new DocumentDto(documento) );
		return new NewDocumentInsert(id, indice );
	}
	
	public IndexedDocumentChecker getDocuments() throws BusinessException {
		return dicc.getDocuments();
	}
	
	public DocumentDto getDocumentFromId( Integer id ) throws BusinessException {
		return dicc.getDocument(id);
	}
	
	protected Index getIndex() {
		return indice;
	}
	
}
