package api;

import api.bo.spider.ISpiderBo;
import api.dao.spider.ISpiderDao;
import app.bo.spider.SpiderBo;
import app.dao.spider.SpiderDao;

public class ObjectFactory {

	public ObjectFactory() {}
	
	@SuppressWarnings("unchecked")
	public static Object getObject(Class interfaz) {

		if (interfaz.equals(ISpiderBo.class)) {
			return SpiderBo.class;
		} else if (interfaz.equals(ISpiderDao.class)) {
			return SpiderDao.class;
		}
		
		return null;
	}
	
}
