package test.files;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;


public class test {
	public static void main(String[] args) throws IOException {
		File file = new File("c:/lala/lala.txt");
		File fileDir = new File("c:/lala");
		 
		if (!fileDir.isDirectory()) {
			fileDir.mkdir();
			file.createNewFile();
		} else {
			if (!file.exists()) {
				file.createNewFile();
			}
		}
		
		OutputStream dos = new DataOutputStream(new FileOutputStream(file));
		
		byte[] bytes = new byte[12];
		bytes[0] = 'n';
		bytes[1] = 'i';
		bytes[2] = 'c';
		bytes[3] = 'o';
		bytes[4] = ' ';
		bytes[5] = 'c';
		bytes[6] = 'o';
		bytes[7] = 'h';
		bytes[8] = 'e';
		bytes[9] = 'n';
		bytes[10] = ' ';
		bytes[11] = 15;

		InputStream dis = new DataInputStream(new FileInputStream(file));

		dos.write(bytes);
//		int b = 0;
//	    while( (b=dis.read(bytes)) != -1 ) {
//	    	dos.write(bytes, 0, b);
//	    }

		String frase ="";

		int a=0;
		while((a=dis.read())!=-1) {
			frase+=(char)a+" ";
		}
		System.out.println(frase);

		dos.close();
		dis.close();
		
	}
}

