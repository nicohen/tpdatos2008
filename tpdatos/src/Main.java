import org.apache.log4j.Logger;

import utils.Constants;
import api.DefaultQueryEngine;
import api.DocumentsIndexer;
import api.IQueryEngine;
import api.SignatureFileQueryEngine;




public class Main {

	/**
	 * @param args
	 * @throws Exception 
	 */
	
	public static IQueryEngine create( String indexType ) throws Exception {
		
		if (indexType.equals("signaturefile" ) ) {
			return new SignatureFileQueryEngine(Constants.SIGNATURE_SIZE,"");
				
		} else if (indexType.equals("indiceinvertido" ) ) {
			return new DefaultQueryEngine(2048,"");
			
		} else {
			throw new Exception("Engine desconocido o no soportado");
		}

	}
	
	public static void main(String[] args) throws Exception {
		
		String option = "--indexer";
		String indexType="signaturefile";
		
		try {
			if ( args.length > 0) {
				option = args[0];
				
				if (option.equals("--indexer" ) ) {
					indexType=args[1];
					IQueryEngine engine = create (indexType);
					
					DocumentsIndexer indexer=new DocumentsIndexer(engine);
					indexer.indexPath( Constants.FOLDER_DOCUMENTS );
					
				} else if (option.equals("--tree-dumper")) {
					TreeDumper.main(args);
				} else if ( option.equals("--search")) {
					indexType=args[1];
					IQueryEngine engine = create (indexType);
	
					SearchEngine searchEngine = new SearchEngine(engine);
					searchEngine.main(args);
				} else if ( option.equals("--queryparser-test")) {
					new test.query.ParserTest().interactiveTest();
				} else {
					System.out.println("Opcion invalida (" + option+ ")");
				}
			} else {
				System.out.println("Debe elegir una opcion ( --indexer o --search)");
			}
		} catch(Exception e) {
			Logger log=	Logger.getLogger("ARCHIVO");
			log.error("Error en operacion de indexacion o busqueda",e);
		}
		
	}
}
