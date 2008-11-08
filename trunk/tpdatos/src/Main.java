import api.Index;
import api.QueryEngine;
import api.SignatureFileQueryEngine;
import app.bo.IndexImp;
import app.dao.documents.DocumentsDictionaryImp;
import utils.Constants;




public class Main {

	/**
	 * @param args
	 * @throws Exception 
	 */
	public static void main(String[] args) throws Exception {
		
		String option = "--indexer";
		String indexType="signature";
		
		if ( args.length > 0) {
			option = args[0];
			indexType=args[1];
			if (option.equals("--indexer" ) ) {
				if (indexType.equals("signaturefile" ) ) {
				DocumentsIndexer indexer = 
					new DocumentsIndexer(new SignatureFileQueryEngine());
				indexer.indexPath( Constants.FOLDER_DOCUMENTS );
				}
				else if (indexType.equals("indiceinvertido" ) ) {
				IndexImp index=new IndexImp(Constants.INDEX_FILE_PATH,Constants.INDEX_FILE_SIZE);
				DocumentsDictionaryImp dicc=new DocumentsDictionaryImp();
				DocumentsIndexer indexer=new DocumentsIndexer(new QueryEngine(index,dicc));
				indexer.indexPath( Constants.FOLDER_DOCUMENTS );
						
				}
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
