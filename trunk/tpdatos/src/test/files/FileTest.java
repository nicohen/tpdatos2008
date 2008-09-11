package test.files;
import api.po.files.File;
import app.po.files.SecuencialFile;
import app.po.persistors.BytePersistor;
import exceptions.DataAccessException;

public class FileTest {

	public static void main(String[] args) throws DataAccessException{
		//create();
		//read();
		BytePersistor persistor= new BytePersistor();

			File<Byte> file= new SecuencialFile<Byte>("datos.bin",persistor);
			file.add(new Byte((byte)7));
			file.add(new Byte((byte)8));
			file.add(new Byte((byte)9));
			file.add(new Byte((byte)10));
			Byte aux= file.get(0);
			if (aux.equals(new Byte((byte)7))){
				System.out.println("1 comparacion correcta");
			}else{
				System.out.println("1 comparacion fallo");
			}
			aux= file.get(3);
			if (aux.equals(new Byte((byte)10))){
				System.out.println("2 comparacion correcta");
			}else{
				System.out.println("2 comparacion fallo");
			}
			aux= file.get(2);
			if (aux.equals(new Byte((byte)9))){
				System.out.println("3 comparacion correcta");
			}else{
				System.out.println("3 comparacion fallo");
			}
			aux= file.get(1);
			if (aux.equals(new Byte((byte)8))){
				System.out.println("4 comparacion correcta");
			}else{
				System.out.println("4 comparacion fallo");
			}
			file.remove(1);
			aux= file.get(1);
			if (aux==null){
				System.out.println("5 comparacion correcta");
			}else{
				System.out.println("5 comparacion fallo");
			}			
			file.add(new Byte((byte)15));
			aux= file.get(1);
			if (aux.equals(new Byte((byte)15))){
				System.out.println("6 comparacion correcta");
			}else{
				System.out.println("6 comparacion fallo");
			}			
	}
}