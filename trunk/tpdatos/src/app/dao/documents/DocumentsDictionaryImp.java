package app.dao.documents;

import java.io.File;
import java.io.FileFilter;
import processor.IndexedDocumentChecker;
import utils.Constants;
import api.dao.documents.DocumentsDictionary;
import app.po.files.RelativeFile;
import app.po.files.SecuencialFile;
import app.po.persistors.DocumentDataPersistor;
import app.po.persistors.DocumentInfoPersistor;
import dto.DocumentDto;
import exceptions.BusinessException;
import exceptions.DataAccessException;
import exceptions.PersistanceException;

public class DocumentsDictionaryImp implements DocumentsDictionary {
	
	RelativeFile<DocumentDto> relativeFile = null;
	RelativeFile<String> dataFile;
	public DocumentsDictionaryImp() throws DataAccessException {

		relativeFile = new RelativeFile<DocumentDto>("indexed_documents.bin",new DocumentInfoPersistor());
		dataFile=new RelativeFile<String>("document_names.txt",new DocumentDataPersistor());
	}
	
	@Override
	public DocumentDto getDocument(Integer id) throws BusinessException {
		try {
			DocumentDto dDto = relativeFile.get(id);
			dDto.setFileName(dataFile.get(id));
			return dDto; 
		} catch(DataAccessException e) {
			throw new BusinessException("",e);
		}
	}

	@Override
	public Integer insertDocument(DocumentDto document) throws BusinessException {
		try {
			//agrego el string de nombre al archivo secuencial
			document.setOffset(dataFile.add(document.getFileName()));
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

		try {
			DocumentDto document = null;
			for(int i=0;i<relativeFile.getSize();i++) {
				document=relativeFile.get(i++);
				document.setFileName(dataFile.get(i));
				checker.addDocument(document.getDocumentId(), document.getFileName());
			}

		} catch (DataAccessException e) {
			throw new BusinessException("Error inicializando RelativeFile de documentos indexados",e);
		}
		return checker;
	}
	
	public static void moveFileToIndexedFolder(File file) {
	    // Destination directory
	    File dir = new File(Constants.FOLDER_INDEXED);
	    
	    // Move file to new directory
	    boolean success = file.renameTo(new File(dir, file.getName()));
	    if (!success) {
	    	System.out.println("Error moviendo ["+file.getName()+"] a la carpeta de indexados");
	    } else {
	    	System.out.println("Se ha movido el archivo ["+file.getName()+"] a la carpeta de indexados");
	    }

	}
	
	public static File[] prepareNewDocuments(String documentsPath) {
	    File dir = new File(documentsPath);
	    
	    String[] children = dir.list();
	    if (children == null) {
	    	System.out.println("Directorio inexistente ["+dir.getPath()+"]");
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
