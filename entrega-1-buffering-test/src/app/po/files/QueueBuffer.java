package app.po.files;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;

import bplus.exceptions.KeyNotFoundException;
import api.po.files.Buffer;

public class QueueBuffer<KEY,VALUE> implements Buffer<KEY,VALUE> {

	
	private Map<KEY,VALUE> map = new HashMap<KEY,VALUE>(); 
	private LinkedList<KEY> list = new LinkedList<KEY>();
	private int maxSize;

	public QueueBuffer(int maxSize) {
		this.maxSize = maxSize;
	}
	
	public VALUE get(KEY key) throws KeyNotFoundException {
		VALUE value = map.get(key);
		
		if (value == null) 
			throw new KeyNotFoundException();
		else
			return value;
	}

	public void put(KEY key, VALUE value) {
		if (list.size() >= this.maxSize ) {
			// desalojar un elemento de la lista
			KEY removedKey = this.list.removeFirst();
			map.remove(removedKey);
		}

		list.add(key);
		map.put(key, value);

	}

}
