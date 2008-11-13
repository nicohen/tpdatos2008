package app.dao.documents;

import java.io.File;
import java.io.FileFilter;

import org.apache.log4j.Logger;

import processor.IndexedDocumentChecker;
import utils.Constants;
import api.dao.documents.DocumentsDictionary;
import app.po.files.RelativeFile;
import app.po.files.SecuentialFile;
import app.po.persistors.DocumentDataPersistor;
import app.po.persistors.DocumentInfoPersistor;
import dto.DocumentDto;
import exceptions.BusinessException;
import exceptions.DataAccessException;
import exceptions.PersistanceException;

public class DocumentsDictionaryImp implements DocumentsDictionary {
	
	RelativeFile<DocumentDto> relativeFile = null;
	SecuentialFile<String> nameFile;
	public DocumentsDictionaryImp( String relativeFileName, String namesFileName) throws DataAccessException {

		relativeFile = new RelativeFile<DocumentDto>(relativeFileName,new DocumentInfoPersistor());
		nameFile=new SecuentialFile<String>(namesFileName,new DocumentDataPersistor());
	}
	
	@Override
	public DocumentDto getDocument(Integer id) throws BusinessException {
		try {
			DocumentDto dDto = relativeFile.get(id);
			dDto.setDocumentId(id);
			dDto.setFileName(nameFile.getVariable(id,dDto.getOffset(),dDto.getFileNameLength()+1));
			return dDto; 
		} catch(DataAccessException e) {
			throw new BusinessException("Error obteniendo documento para el [ID:"+id+"]",e);
		}
	}

	@Override
	public Integer insertDocument(DocumentDto document) throws BusinessException {
		try {
			//agrego el string de nombre al archivo secuencial
			document.setOffset(nameFile.add(document.getFileName()));
			return relativeFile.add(document);
		} catch (DataAccessException e) {
			throw new BusinessException("Error inicializando RelativeFile de documentos indexados",e);
		} catch (PersistanceException e) {
			throw new BusinessException("Error inicializando RelativeFile de documentos indexados",e);
		}
	}

	@Override
	public IndexedDocumentChecker getDocuments() throws BusinessException {
		IndexedDocumentChecker checker = new IndexedDocumentChecker();

			DocumentDto document = null;
			
			for(int i=0;i<relativeFile.getSize();i++) {
				document=this.getDocument(i);
				checker.addDocument(document.getDocumentId(), document.getFileName());
			}

		
		return checker;
	}
	
	public static void moveFileToIndexedFolder(File file) {

		Logger log = Logger.getLogger(DocumentsDictionaryImp.class);
		
		// Destination directory
	    File dir = new File(Constants.FOLDER_INDEXED);
	    
	    // Crea el directorio en caso de que no exista
	    if (!dir.isDirectory()) {
	    	dir.mkdir();
	    }
	    
	    // Move file to new directory
	    boolean success = file.renameTo(new File(dir, file.getName()));
	    
	    if (!success) {
	    	log.error("Error moviendo ["+file.getName()+"] a la carpeta de indexados");
	    } else {
	    	log.debug("Se ha movido el archivo ["+file.getName()+"] a la carpeta de indexados");
	    }

	}
	
	public static File[] prepareNewDocuments(String documentsPath) throws DataAccessException {
	    File dir = new File(documentsPath);
	    
	    String[] children = dir.list();
	    if (children == null) {
	    	throw new DataAccessException("Directorio inexistente ["+dir.getPath()+"]");
	    }
	    
	    // Este filtro solamente retorna archivos
	    FileFilter fileFilter = new FileFilter() {
	        public boolean accept(File file) {
	            return file.isFile();
	        }
	    };
	    
	    return dir.listFiles(fileFilter);
	}

	
}
