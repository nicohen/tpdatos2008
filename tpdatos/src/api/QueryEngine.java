package api;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

import processor.IndexedDocumentChecker;
import processor.stemming.StemmingProcessor;
import processor.stopwords.StopwordsProcessor;
import processor.utils.DigesterUtils;
import utils.Constants;
import api.dao.documents.DocumentsDictionary;
import api.query.parser.Parser;
import api.query.tree.Query;
import app.query.QueryWord;
import app.query.parser.QueryParser;
import app.query.parser.QueryNotParser;
import app.query.parser.QueryWordParser;
import app.query.parser.exception.ParserException;
import app.query.tree.QueryNot;
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

		public Iterator<Integer> iterator() {
			try {
				return QueryEngine.this.queryWord( this.getWord() );
			} catch (BusinessException e) {
					// TODO: tratar mejor la excepcion
			}
			List<Integer> lista=new ArrayList<Integer>();
			return lista.iterator();
		}
		
	}
	
	class DefaultQueryWordParser extends QueryWordParser {

		private StemmingProcessor sp;
		private StopwordsProcessor sw;
		
		public DefaultQueryWordParser()  {
			try {
				this.sp = new StemmingProcessor(Constants.FILE_STEMMING);
				//Inicializo diccionario de stopwords
				this.sw = new StopwordsProcessor(Constants.FILE_STOPWORDS);
			} catch (BusinessException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		@Override
		public QueryWord create(String unProcessedWord) {
			
			// procesar la palabra con DigesterUtils
			String word = DigesterUtils.formatText(unProcessedWord).trim();
			
			if (sw != null) {
				if ( sw.isStopword(word )) {
					// FIXME: que hacer si es un stopword ??
				}
			}
			
			if (sp != null) {
				// TODO: controlar este error
				word = sp.stem(word);
			}
			
			return new DefaultQueryWord(word);
		}
		
	}
	
	class DefaultQueryNot extends QueryNot {

		public DefaultQueryNot(Query subQuery) {
			super(subQuery);
		}

		@Override
		public int getDocumentsCount() {
			return QueryEngine.this.getDocumentsCount() ;
		}
		
	}
	
	class DefaultQueryNotParser extends QueryNotParser {

		public DefaultQueryNotParser(Parser recur) {
			super(recur);
		}

		@Override
		protected Query createQueryNot(Query consulta) {
			return new DefaultQueryNot(consulta);
		}
		
	}
	
	private Iterator<Integer> queryWord( String word ) throws BusinessException {
		return indice.getDocuments(word).iterator();
				
	}


	protected QueryEngine(Index index,DocumentsDictionary dictionary){
		dicc=dictionary;
		indice=index;
		
		queryParser = new QueryParser();
		queryParser.addCustomParser(new DefaultQueryNotParser(queryParser) );
		queryParser.addCustomParser(new DefaultQueryWordParser() );
		
	}
	
	private int getDocumentsCount() {
		try {
			return dicc.getDocumentsCount();
		} catch (BusinessException e) {
			// TODO Auto-generated catch block
			return 0;
		}
	}
	
	public List<DocumentDto> executeQuery(String consulta) throws BusinessException{
		
		try {
			Query query = queryParser.parse(consulta);
			
			List<DocumentDto> listaRet=new ArrayList<DocumentDto>();
			Iterator<Integer> documentos = query.iterator();
			
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
