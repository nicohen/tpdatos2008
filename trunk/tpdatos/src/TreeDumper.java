import utils.Constants;
import api.bo.BPlusTree.BPlusTreeBo;
import app.bo.bplus.BPlusTreeBoImp;
import exceptions.DataAccessException;


public class TreeDumper {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			BPlusTreeBo bo= new BPlusTreeBoImp(Constants.BPLUS_FILE_PATH,0);
			bo.dump();
		} catch (DataAccessException e) {
			System.out.println("/n Error al intentar mostra el Arbol.");
		}
	}

}
