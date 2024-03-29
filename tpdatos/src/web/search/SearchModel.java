package web.search;

import java.io.File;
import java.util.Iterator;

import javax.servlet.ServletContext;

import processor.stopwords.StopwordsProcessor;
import utils.Constants;
import api.DefaultQueryEngine;
import api.IQueryEngine;
import api.SignatureFileQueryEngine;
import dto.DocumentDto;
import exceptions.BusinessException;

public class SearchModel {

	private String searchWord;
	private IQueryEngine engine;
	private long searchTime;
	private String searchEngine;
	private String basePath;
	private String contextPath;
	
	
	public String getSearchEngine() {
		return searchEngine;
	}

	public void setSearchEngine(String searchEngine) {
		this.searchEngine = searchEngine;
	}

	public long getSearchTime() {
		return searchTime;
	}

	public void setSearchTime(long searchTime) {
		this.searchTime = searchTime;
	}

	public SearchModel(ServletContext servletContext, String word, String searchEngine) throws BusinessException {
		if(searchEngine!=null && !"".equals(searchEngine)) {
			try {
				this.engine = create(searchEngine,servletContext.getRealPath(File.separator) + File.separator );
			} catch(Exception e) {
				throw new BusinessException("Error creando la engine para obtener documentos",e);
			}
		}
		this.searchWord = word;
		this.searchEngine = searchEngine;
		this.basePath = servletContext.getRealPath(File.separator) + File.separator;
		this.contextPath = servletContext.getContextPath() + File.separator ;
	}

	public String getContextPath() {
		return contextPath;
	}

	public String getSearchWord() {
		return searchWord==null?"":searchWord;
	}

	public void setSearchWord(String word) {
		this.searchWord = word;
	}
	
	public Iterator<DocumentDto> iteratorQuery(String consulta) throws BusinessException {
		if(consulta!=null && !"".equals(consulta)) {
			long c1 = System.currentTimeMillis();

			//Inicializo diccionario de stopwords
			StopwordsProcessor sw = new StopwordsProcessor(basePath+Constants.FILE_STOPWORDS);
			//Inicializo diccionario de stemming
			if(!sw.isStopword(consulta)) {
			} else {
				System.out.println("El termino ingresado ["+consulta+"] es un stopword, ingreselo nuevamente");
				return null;
			}
			
			//Muestro los documentos en los que aparece
			Iterator<DocumentDto> results = engine.iteratorQuery(consulta);
			setSearchTime(System.currentTimeMillis()-c1);
			
			return results;
		} else {
			return null;
		}
		
	}
	
	public static IQueryEngine create( String indexType, String basePath ) throws Exception {
		
		if (indexType.equals("signaturefile" ) ) {
			return new SignatureFileQueryEngine(Constants.SIGNATURE_SIZE,basePath);
				
		} else if (indexType.equals("indiceinvertido" ) ) {
			return new DefaultQueryEngine(2048,basePath);
			
		} else {
			throw new Exception("Engine desconocido o no soportado");
		}

	}

	public IQueryEngine getEngine() {
		return engine;
	}

	public void setEngine(IQueryEngine engine) {
		this.engine = engine;
	}

	public void setBasePath(String basePath) {
		this.basePath = basePath;
	}

	public String getBasePath() {
		return basePath;
	}

}
