import java.io.IOException;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

import exceptions.BusinessException;
import exceptions.DataAccessException;


public class Main {

	/**
	 * @param args
	 * @throws Exception 
	 */
	public static void main(String[] args) throws Exception {
		
		String option = "--indexer";
		if ( args.length < 0) {
			option = args[0];
		}

		if (option.equals("--indexer" ) ) {
			DocumentsIndexer.main(args);
		} else if (option.equals("--tree-dumper")) {
			TreeDumper.main(args);
		} else if ( option.equals("--search")) {
			SearchEngine.main(args);
		} else {
			System.out.println("Opcion invalida");
		}
		
	}
}
