package app.po.files;

import java.util.LinkedList;
import java.util.Queue;

import bplus.exceptions.KeyNotFoundException;
import api.po.files.Buffer;

public class QueueBuffer<KEY,VALUE> implements Buffer<KEY,VALUE> {

	private class Pair<KEY,VALUE> {
		public KEY key;
		public VALUE value;
		public Pair(KEY key, VALUE value) {
			this.key = key;
			this.value = value;
		}
	}
	
	private LinkedList<Pair<KEY,VALUE>> list;
	private int maxSize;

	public QueueBuffer(int maxSize) {
		this.maxSize = maxSize;
		this.list = new LinkedList<Pair<KEY,VALUE>>();
	}
	
	public VALUE get(KEY key) throws KeyNotFoundException {
		
		for (Pair<KEY,VALUE> pair : list ) {
			if ( pair.key.equals(key) ) {
				return pair.value;
			}
		}
		
		throw new KeyNotFoundException();
	}

	public void put(KEY key, VALUE value) {
		if (list.size() >= this.maxSize ) {
			// desalojar un elemento de la lista
			this.list.removeFirst();
		}

		list.add( new Pair<KEY,VALUE>(key,value));

	}

}
