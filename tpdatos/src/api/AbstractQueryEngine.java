package api;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

import processor.stemming.StemmingProcessor;
import processor.stopwords.StopwordsProcessor;
import processor.utils.DigesterUtils;
import utils.Constants;
import api.query.parser.Parser;
import api.query.tree.Query;
import app.query.QueryWord;
import app.query.parser.QueryNotParser;
import app.query.parser.QueryWordParser;
import app.query.tree.QueryNot;
import exceptions.BusinessException;


public abstract class AbstractQueryEngine implements IQueryEngine {

	
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
	
	protected abstract int getDocumentsCount(); 
	protected abstract Iterator<Integer> queryWord(String word) throws BusinessException; 
	
	
	
}