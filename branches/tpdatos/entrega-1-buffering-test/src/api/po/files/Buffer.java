package api.po.files;

import bplus.exceptions.KeyNotFoundException;


public interface Buffer<KEY,VALUE> {
	
	VALUE get( KEY key ) throws KeyNotFoundException;
	void put( KEY key, VALUE value);
	
	// DEBUGGING, compara elementos internos para ver
	// si esta bien
	void compare(KEY key, VALUE value);
	
}
