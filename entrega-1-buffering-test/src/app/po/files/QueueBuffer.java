package app.po.files;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;

import exceptions.PersistanceException;

import bplus.exceptions.KeyNotFoundException;
import api.po.files.Buffer;
import api.po.persistors.Persistor;

public class QueueBuffer<KEY,VALUE> implements Buffer<KEY,VALUE> {

	
	private Map<KEY,byte[]> map = new HashMap<KEY,byte[]>(); 
	private LinkedList<KEY> list = new LinkedList<KEY>();
	private int maxSize;
	private Persistor<VALUE> persistor ;

	public QueueBuffer(int maxSize, Persistor<VALUE> persistor) {
		this.maxSize = maxSize;
		this.persistor = persistor;
	}
	
	public VALUE get(KEY key) throws KeyNotFoundException {
		
		byte[] array = map.get(key);
		
		if (array == null) {
			throw new KeyNotFoundException();
		}

		ByteArrayInputStream input = new ByteArrayInputStream( array );
		DataInputStream inputStream = new DataInputStream(input);
		VALUE value;
		
		try {
			value = persistor.read(inputStream);
		} catch (PersistanceException e) {
			throw new KeyNotFoundException();
		}
		
		return value;
	}

	public void put(KEY key, VALUE value) {
		if (list.size() >= this.maxSize ) {
			// desalojar un elemento de la lista
			KEY removedKey = this.list.removeFirst();
			map.remove(removedKey);
		}

		// se elimina la clave ahora, ya que su valor
		// ya no es valido, si no puede insertar
		// despues, es mejor que no considere la
		// clave vieja
		map.remove(key);
		try {
			
			// si no puede escribirlo, no se inserta

			ByteArrayOutputStream output = new ByteArrayOutputStream();
			DataOutputStream stream = new DataOutputStream(output);
			
			persistor.write(value, stream);
			byte[] array = output.toByteArray();
			map.put(key, array);
			list.add(key);
			
			
		} catch (PersistanceException e) {
			// si no se inserta, hay que eliminar todas
			// las ocurrencias de la key en el mapa 
		}
		

	}

}
