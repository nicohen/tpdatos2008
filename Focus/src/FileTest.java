import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.RandomAccessFile;

public class FileTest {

	public static void main(String[] args) {
		create();
		read();
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
