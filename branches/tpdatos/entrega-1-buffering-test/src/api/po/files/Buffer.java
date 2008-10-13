package api.po.files;

import bplus.exceptions.KeyNotFoundException;


public interface Buffer<KEY,VALUE> {
	
	VALUE get( KEY key ) throws KeyNotFoundException;
	void put( KEY key, VALUE value);
	
}
