import api.SignatureFileQueryEngine;
import utils.Constants;




public class Main {

	/**
	 * @param args
	 * @throws Exception 
	 */
	public static void main(String[] args) throws Exception {
		
		String option = "--indexer";
		if ( args.length > 0) {
			option = args[0];
	
			if (option.equals("--indexer" ) ) {
				DocumentsIndexer indexer = 
					new DocumentsIndexer(new SignatureFileQueryEngine());
				indexer.indexPath( Constants.FOLDER_DOCUMENTS );
			} else if (option.equals("--tree-dumper")) {
				TreeDumper.main(args);
			} else if ( option.equals("--search")) {
				SearchEngine.main(args);
			} else {
				System.out.println("Opcion invalida (" + option+ ")");
			}
		} else {
			System.out.println("Debe elegir una opcion ( --indexer o --search)");
		}
		
	}
}
