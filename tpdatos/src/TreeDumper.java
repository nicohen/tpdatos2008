import api.bo.BPlusTree.BPlusTreeBo;
import app.bo.bplus.BPlusTreeBoImp;
import exceptions.DataAccessException;


public class TreeDumper {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			BPlusTreeBo bo= new BPlusTreeBoImp(args[0],128);
			bo.dump();
		} catch (DataAccessException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
}

}
