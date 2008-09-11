package test;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.RandomAccessFile;

import api.po.files.File;
import app.po.files.SecuencialFile;
import app.po.persistors.BytePersistor;

import exceptions.DataAccessException;

public class FileTest {

	public static void main(String[] args) throws DataAccessException{
		//create();
		//read();
		BytePersistor persistor= new BytePersistor();

			File<Byte> file= new SecuencialFile<Byte>("c:/datos.bin",persistor);
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
	}
	
	private static void create(){
		try {
			RandomAccessFile file= new RandomAccessFile("c:/pablo.bin","rw");
			byte[] name= {'P','a','b','l','o'};
			file.write(name);
			file.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	private static void read(){
		try {
			RandomAccessFile file= new RandomAccessFile("c:/pablo.bin","rw");
			file.seek(1);
			System.out.print((char)file.readByte());
			file.seek(4);
			System.out.print((char)file.readByte());
			file.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
