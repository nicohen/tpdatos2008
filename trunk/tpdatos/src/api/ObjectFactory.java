package api;

import java.util.HashMap;

import app.po.persistors.BytePersistor;
import app.po.persistors.IntegerPersistor;

public class ObjectFactory {

	private ObjectFactory() {}
	private static HashMap<Class, Object> objects= new HashMap<Class, Object>();
	
	@SuppressWarnings("unchecked")
	//TODO: completar la lista de clases de la objectFactory
	public static Object getObject(Class interfaz) {
		Object object= objects.get(interfaz);
		if (object==null){
			if (BytePersistor.class.equals(interfaz)){
				object= new BytePersistor();
			}else if(IntegerPersistor.class.equals(interfaz)){
				object= new IntegerPersistor();
			}
			objects.put(interfaz, object);
		}
		return object;
	}
	
}
