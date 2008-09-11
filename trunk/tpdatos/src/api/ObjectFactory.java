package api;

import java.util.HashMap;

public class ObjectFactory {

	private ObjectFactory() {}
	private static HashMap<Class, Object> objects= new HashMap<Class, Object>();
	
	@SuppressWarnings("unchecked")
	public static Object getObject(Class interfaz) {
		objects.get(interfaz);
		return null;
	}
	
}
