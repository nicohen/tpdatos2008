package api;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

import dto.DocumentDto;

import processor.stemming.StemmingProcessor;
import processor.stopwords.StopwordsProcessor;
import processor.utils.DigesterUtils;
import utils.Constants;
import api.query.parser.Parser;
import api.query.tree.Query;
import app.query.QueryWord;
import app.query.parser.QueryNotParser;
import app.query.parser.QueryParser;
import app.query.parser.QueryWordParser;
import app.query.parser.exception.ParserException;
import app.query.tree.QueryNot;
import exceptions.BusinessException;


public abstract class AbstractQueryEngine implements IQueryEngine {

	private QueryParser queryParser;
	
	class DefaultQueryWord extends QueryWord {

		public DefaultQueryWord(String str) {
			super(str);
		}

		public Iterator<Integer> iterator() {
			try {
				return AbstractQueryEngine.this.queryWord( this.getWord() );
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
		
		public DefaultQueryWordParser(String basePath)  {
			try {
				this.sp = new StemmingProcessor(basePath+Constants.FILE_STEMMING);
				//Inicializo diccionario de stopwords
				this.sw = new StopwordsProcessor(basePath+Constants.FILE_STOPWORDS);
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
			return AbstractQueryEngine.this.getDocumentsCount() ;
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
	
	public AbstractQueryEngine(String basePath) {
		queryParser = new QueryParser();
		queryParser.addCustomParser(new DefaultQueryNotParser(queryParser) );
		queryParser.addCustomParser(new DefaultQueryWordParser(basePath));
	}
	
	protected abstract int getDocumentsCount(); 
	protected abstract Iterator<Integer> queryWord(String word) throws BusinessException; 
	
	protected abstract DocumentDto getDocument(Integer id ) throws BusinessException;
	
	public List<DocumentDto> executeQuery(String consulta) throws BusinessException {
		return executeQuery(consulta,0,0x7fffffff);
	}

	public List<DocumentDto> executeQuery(String consulta, int offset, int limit) throws BusinessException {
		try {
			Query query = queryParser.parse(consulta);
			
			List<DocumentDto> listaRet=new ArrayList<DocumentDto>();
			Iterator<Integer> documentos = query.iterator();
			
			for (int i=0; i<offset; i++) documentos.next();
			
			int count = 0;
			while (documentos.hasNext() && count < limit ) { 
				Integer docId = documentos.next();
				DocumentDto dtoAux=getDocument(docId);
				dtoAux.setDocumentId(docId);
				listaRet.add(dtoAux);
				
				count ++;
			}
			
			return listaRet;
		} catch (ParserException e) {
			throw new BusinessException("Error al parsear la query", e);
		}
	}
	
	class QueryIterator implements Iterator<DocumentDto> {

		private Iterator<Integer> docsid;
		private boolean hasNext;
		private DocumentDto next;
		
		public QueryIterator( Iterator<Integer> docsid ) {
			this.docsid = docsid;
			this.hasNext = false;
			searchNext();
			
		}
		
		public boolean hasNext() {
			return hasNext;
		}

		public DocumentDto next() {
			return next;
		}

		public void remove() {
			// TODO Auto-generated method stub
			
		}
		
		private void searchNext() {
			while (true) {
				if (docsid.hasNext() ) {
					this.hasNext = true;
					Integer docid = docsid.next();
					try {
						next = AbstractQueryEngine.this.getDocument(docid);
						break;
					} catch (BusinessException e) {
					}
					
				} else {
					this.hasNext = false;
					break;
				}
			}
		}
				
	}
	
	public Iterator<DocumentDto> iteratorQuery(String consulta) throws BusinessException {
		try {
			Query query = queryParser.parse(consulta);
			Iterator<Integer> documentos = query.iterator();

			return new QueryIterator(documentos);
		} catch (ParserException e) {
			throw new BusinessException("Error al parsear la query", e);
		}
		
	}
	
	public int countQuery( String consulta ) throws BusinessException {
		Query query;
		try {
			query = queryParser.parse(consulta);
			Iterator<Integer> documentos = query.iterator();
		
			int count = 0;
		
			while (documentos.hasNext()) { 
				count ++;
			}
		
			return count;
		} catch (ParserException e) {
			throw new BusinessException("Error al parsear la query", e);
		}
	}
	
	
	
	
	
}
