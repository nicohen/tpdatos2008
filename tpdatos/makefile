CLASSPATHS=src:lib/htmlparser.jar:lib/servlet-api.jar:lib/junit-4.5.jar:lib/log4j-1.2.15.jar

JFLAGS = -g -classpath $(CLASSPATHS)
JC = javac


CLASSES = ./src/linkedblocks/keys/DocumentIndexKey.java ./src/linkedblocks/utils/KeyCodificationUtils.java ./src/linkedblocks/LinkedBlocksManager.java ./src/linkedblocks/VariableLinkedBlocksManager.java ./src/linkedblocks/codification/GammaDistancesBlock.java ./src/bplus/nodes/AbstractBPlusNode.java ./src/bplus/nodes/BPlusLeafNode.java ./src/bplus/nodes/BPlusIndexNode.java ./src/bplus/nodes/BPlusNode.java ./src/bplus/keys/BPlusNodeKey.java ./src/bplus/keys/BPlusElementKey.java ./src/bplus/MockBPlusTreeFacade.java ./src/bplus/exceptions/BPlusException.java ./src/bplus/exceptions/BPlusNodeException.java ./src/bplus/exceptions/KeyNotFoundException.java ./src/bplus/exceptions/NodeNotFoundException.java ./src/bplus/exceptions/NodeOverflowException.java ./src/bplus/BPlusTreeFacade.java ./src/bplus/elements/BPlusLeafElement.java ./src/bplus/elements/BPlusElement.java ./src/bplus/elements/BPlusIndexElement.java ./src/bplus/elements/BPlusAbstractElement.java ./src/bplus/NodeHandler.java ./src/dto/SuffixDto.java ./src/dto/DocumentDto.java ./src/dto/LinkedBlock.java ./src/dto/StopwordsPipelineDto.java ./src/dto/WordDto.java ./src/utils/Constants.java ./src/utils/statistics/StatisticsGeneratorSingleton.java ./src/utils/statistics/StatisticsGenerator.java ./src/utils/statistics/Statistics.java ./src/exceptions/BusinessException.java ./src/exceptions/DataAccessException.java ./src/exceptions/PipelineOverflowException.java ./src/exceptions/PersistanceException.java ./src/SearchEngine.java ./src/api/po/files/Stack.java ./src/api/po/files/File.java ./src/api/po/persistors/Persistor.java ./src/api/po/persistors/SizeUtils.java ./src/api/po/persistors/DistancesBlock.java ./src/api/dao/documents/DocumentsDictionary.java ./src/api/dao/BPlusTree/BPlusNodeDao.java ./src/api/MockQueryEngine.java ./src/api/QueryEngine.java ./src/api/bo/BPlusTree/BPlusNodeBo.java ./src/api/bo/BPlusTree/BPlusTreeBo.java ./src/api/DocumentInsert.java ./src/api/ObjectFactory.java ./src/api/Index.java ./src/api/DefaultQueryEngine.java ./src/processor/IndexedDocumentChecker.java ./src/processor/stemming/StemmingProcessor.java ./src/processor/stopwords/StopwordsProcessor.java ./src/processor/utils/HtmlUtils.java ./src/processor/utils/DigesterUtils.java ./src/ControllerServlet.java ./src/app/po/files/AbstractFile.java ./src/app/po/files/SecuencialFile.java ./src/app/po/files/RelativeFile.java ./src/app/po/files/StreamFile.java ./src/app/po/files/SecuentialFile.java ./src/app/po/files/StackFile.java ./src/app/po/persistors/DocumentDataPersistor.java ./src/app/po/persistors/BPlusNodePersistor.java ./src/app/po/persistors/LinkedBlockIntPersistor.java ./src/app/po/persistors/LinkedBlockByteArrayPersistor.java ./src/app/po/persistors/BPlusElementPersistor.java ./src/app/po/persistors/VariableStringPersistor.java ./src/app/po/persistors/StringPersistor.java ./src/app/po/persistors/SimpleStringPersistor.java ./src/app/po/persistors/AbstractPersistor.java ./src/app/po/persistors/DocumentInfoPersistor.java ./src/app/po/persistors/MaxSizeAbstractPersistor.java ./src/app/po/persistors/IntegerPersistor.java ./src/app/po/persistors/BytePersistor.java ./src/app/dao/bplus/BPlusNodeDaoImp.java ./src/app/dao/bplus/BPlusNodeDaoTest.java ./src/app/dao/documents/DocumentsDictionaryImp.java ./src/app/bo/MockIndex.java ./src/app/bo/MockDocumentsDictionary.java ./src/app/bo/bplus/BPlusTreeBoImp.java ./src/app/bo/bplus/BPlusTreeBoTest.java ./src/app/bo/bplus/AbstractBPlusTreeBo.java ./src/app/bo/IndexImp.java ./src/test/index/TestDocumentsDictionary.java ./src/test/index/TestMockIndex.java ./src/test/index/TestDocumentsDictionaryImp.java ./src/test/index/TestQueryEngineMocks.java ./src/test/index/TestIndexImp.java ./src/test/index/TestQueryEngine.java ./src/test/index/TestMockDocumentsDictionary.java ./src/test/index/TestDefaultQueryEngine.java ./src/test/index/TestIndex.java ./src/test/files/RelativelFileTest.java ./src/test/files/test.java ./src/test/files/SecuentialFileTest.java ./src/test/files/FileTest.java ./src/test/files/StackFileTest.java ./src/test/persistors/TestIntegerPersistor.java ./src/test/persistors/TestPersistor.java ./src/test/persistors/TestBPlusNodePersistor.java ./src/test/persistors/TestBytePersistor.java ./src/test/persistors/TestStringPersistor.java ./src/test/bplus/BPlusNodeTestUtils.java ./src/test/bplus/TestBPlusTreeBo.java ./src/test/bplus/TestBPlusTreeBoImp.java ./src/test/bplus/TestBPlusTreeBoImpDaoTest.java ./src/test/bplus/MapTest.java ./src/test/bplus/TestBPlusNodeDao.java ./src/test/bplus/BPlusTreeBoDaoTest.java ./src/test/bplus/TestBPlusNodeDaoTest.java ./src/test/bplus/TestBPlusNodeDaoImp.java ./src/test/bplus/TestBPlusTreeBoTest.java ./src/test/utils/KeyCodificationTest.java ./src/test/processor/TestStemmerProcessor.java ./src/DocumentsIndexer.java ./src/TreeDumper.java

default: classes
classes: ./bin/linkedblocks/keys/DocumentIndexKey.class ./bin/linkedblocks/utils/KeyCodificationUtils.class ./bin/linkedblocks/LinkedBlocksManager.class ./bin/linkedblocks/VariableLinkedBlocksManager.class ./bin/linkedblocks/codification/GammaDistancesBlock.class ./bin/bplus/nodes/AbstractBPlusNode.class ./bin/bplus/nodes/BPlusLeafNode.class ./bin/bplus/nodes/BPlusIndexNode.class ./bin/bplus/nodes/BPlusNode.class ./bin/bplus/keys/BPlusNodeKey.class ./bin/bplus/keys/BPlusElementKey.class ./bin/bplus/MockBPlusTreeFacade.class ./bin/bplus/exceptions/BPlusException.class ./bin/bplus/exceptions/BPlusNodeException.class ./bin/bplus/exceptions/KeyNotFoundException.class ./bin/bplus/exceptions/NodeNotFoundException.class ./bin/bplus/exceptions/NodeOverflowException.class ./bin/bplus/BPlusTreeFacade.class ./bin/bplus/elements/BPlusLeafElement.class ./bin/bplus/elements/BPlusElement.class ./bin/bplus/elements/BPlusIndexElement.class ./bin/bplus/elements/BPlusAbstractElement.class ./bin/bplus/NodeHandler.class ./bin/dto/SuffixDto.class ./bin/dto/DocumentDto.class ./bin/dto/LinkedBlock.class ./bin/dto/StopwordsPipelineDto.class ./bin/dto/WordDto.class ./bin/utils/Constants.class ./bin/utils/statistics/StatisticsGeneratorSingleton.class ./bin/utils/statistics/StatisticsGenerator.class ./bin/utils/statistics/Statistics.class ./bin/exceptions/BusinessException.class ./bin/exceptions/DataAccessException.class ./bin/exceptions/PipelineOverflowException.class ./bin/exceptions/PersistanceException.class ./bin/SearchEngine.class ./bin/api/po/files/Stack.class ./bin/api/po/files/File.class ./bin/api/po/persistors/Persistor.class ./bin/api/po/persistors/SizeUtils.class ./bin/api/po/persistors/DistancesBlock.class ./bin/api/dao/documents/DocumentsDictionary.class ./bin/api/dao/BPlusTree/BPlusNodeDao.class ./bin/api/MockQueryEngine.class ./bin/api/QueryEngine.class ./bin/api/bo/BPlusTree/BPlusNodeBo.class ./bin/api/bo/BPlusTree/BPlusTreeBo.class ./bin/api/DocumentInsert.class ./bin/api/ObjectFactory.class ./bin/api/Index.class ./bin/api/DefaultQueryEngine.class ./bin/processor/IndexedDocumentChecker.class ./bin/processor/stemming/StemmingProcessor.class ./bin/processor/stopwords/StopwordsProcessor.class ./bin/processor/utils/HtmlUtils.class ./bin/processor/utils/DigesterUtils.class ./bin/ControllerServlet.class ./bin/app/po/files/AbstractFile.class ./bin/app/po/files/SecuencialFile.class ./bin/app/po/files/RelativeFile.class ./bin/app/po/files/StreamFile.class ./bin/app/po/files/SecuentialFile.class ./bin/app/po/files/StackFile.class ./bin/app/po/persistors/DocumentDataPersistor.class ./bin/app/po/persistors/BPlusNodePersistor.class ./bin/app/po/persistors/LinkedBlockIntPersistor.class ./bin/app/po/persistors/LinkedBlockByteArrayPersistor.class ./bin/app/po/persistors/BPlusElementPersistor.class ./bin/app/po/persistors/VariableStringPersistor.class ./bin/app/po/persistors/StringPersistor.class ./bin/app/po/persistors/SimpleStringPersistor.class ./bin/app/po/persistors/AbstractPersistor.class ./bin/app/po/persistors/DocumentInfoPersistor.class ./bin/app/po/persistors/MaxSizeAbstractPersistor.class ./bin/app/po/persistors/IntegerPersistor.class ./bin/app/po/persistors/BytePersistor.class ./bin/app/dao/bplus/BPlusNodeDaoImp.class ./bin/app/dao/bplus/BPlusNodeDaoTest.class ./bin/app/dao/documents/DocumentsDictionaryImp.class ./bin/app/bo/MockIndex.class ./bin/app/bo/MockDocumentsDictionary.class ./bin/app/bo/bplus/BPlusTreeBoImp.class ./bin/app/bo/bplus/BPlusTreeBoTest.class ./bin/app/bo/bplus/AbstractBPlusTreeBo.class ./bin/app/bo/IndexImp.class ./bin/test/index/TestDocumentsDictionary.class ./bin/test/index/TestMockIndex.class ./bin/test/index/TestDocumentsDictionaryImp.class ./bin/test/index/TestQueryEngineMocks.class ./bin/test/index/TestIndexImp.class ./bin/test/index/TestQueryEngine.class ./bin/test/index/TestMockDocumentsDictionary.class ./bin/test/index/TestDefaultQueryEngine.class ./bin/test/index/TestIndex.class ./bin/test/files/RelativelFileTest.class ./bin/test/files/test.class ./bin/test/files/SecuentialFileTest.class ./bin/test/files/FileTest.class ./bin/test/files/StackFileTest.class ./bin/test/persistors/TestIntegerPersistor.class ./bin/test/persistors/TestPersistor.class ./bin/test/persistors/TestBPlusNodePersistor.class ./bin/test/persistors/TestBytePersistor.class ./bin/test/persistors/TestStringPersistor.class ./bin/test/bplus/BPlusNodeTestUtils.class ./bin/test/bplus/TestBPlusTreeBo.class ./bin/test/bplus/TestBPlusTreeBoImp.class ./bin/test/bplus/TestBPlusTreeBoImpDaoTest.class ./bin/test/bplus/MapTest.class ./bin/test/bplus/TestBPlusNodeDao.class ./bin/test/bplus/BPlusTreeBoDaoTest.class ./bin/test/bplus/TestBPlusNodeDaoTest.class ./bin/test/bplus/TestBPlusNodeDaoImp.class ./bin/test/bplus/TestBPlusTreeBoTest.class ./bin/test/utils/KeyCodificationTest.class ./bin/test/processor/TestStemmerProcessor.class ./bin/DocumentsIndexer.class ./bin/TreeDumper.class
clean:
	   rm $(CLASSES:.java=.class)

bin/linkedblocks/keys/DocumentIndexKey.class: src/linkedblocks/keys/DocumentIndexKey.java
		$(JC) $(JFLAGS) src/linkedblocks/keys/DocumentIndexKey.java && mv src/linkedblocks/keys/DocumentIndexKey.class bin/linkedblocks/keys/DocumentIndexKey.class 
bin/linkedblocks/utils/KeyCodificationUtils.class: src/linkedblocks/utils/KeyCodificationUtils.java
		$(JC) $(JFLAGS) src/linkedblocks/utils/KeyCodificationUtils.java && mv src/linkedblocks/utils/KeyCodificationUtils.class bin/linkedblocks/utils/KeyCodificationUtils.class 
bin/linkedblocks/LinkedBlocksManager.class: src/linkedblocks/LinkedBlocksManager.java
		$(JC) $(JFLAGS) src/linkedblocks/LinkedBlocksManager.java && mv src/linkedblocks/LinkedBlocksManager.class bin/linkedblocks/LinkedBlocksManager.class 
bin/linkedblocks/VariableLinkedBlocksManager.class: src/linkedblocks/VariableLinkedBlocksManager.java
		$(JC) $(JFLAGS) src/linkedblocks/VariableLinkedBlocksManager.java && mv src/linkedblocks/VariableLinkedBlocksManager.class bin/linkedblocks/VariableLinkedBlocksManager.class 
bin/linkedblocks/codification/GammaDistancesBlock.class: src/linkedblocks/codification/GammaDistancesBlock.java
		$(JC) $(JFLAGS) src/linkedblocks/codification/GammaDistancesBlock.java && mv src/linkedblocks/codification/GammaDistancesBlock.class bin/linkedblocks/codification/GammaDistancesBlock.class 
bin/bplus/nodes/AbstractBPlusNode.class: src/bplus/nodes/AbstractBPlusNode.java
		$(JC) $(JFLAGS) src/bplus/nodes/AbstractBPlusNode.java && mv src/bplus/nodes/AbstractBPlusNode.class bin/bplus/nodes/AbstractBPlusNode.class 
bin/bplus/nodes/BPlusLeafNode.class: src/bplus/nodes/BPlusLeafNode.java
		$(JC) $(JFLAGS) src/bplus/nodes/BPlusLeafNode.java && mv src/bplus/nodes/BPlusLeafNode.class bin/bplus/nodes/BPlusLeafNode.class 
bin/bplus/nodes/BPlusIndexNode.class: src/bplus/nodes/BPlusIndexNode.java
		$(JC) $(JFLAGS) src/bplus/nodes/BPlusIndexNode.java && mv src/bplus/nodes/BPlusIndexNode.class bin/bplus/nodes/BPlusIndexNode.class 
bin/bplus/nodes/BPlusNode.class: src/bplus/nodes/BPlusNode.java
		$(JC) $(JFLAGS) src/bplus/nodes/BPlusNode.java && mv src/bplus/nodes/BPlusNode.class bin/bplus/nodes/BPlusNode.class 
bin/bplus/keys/BPlusNodeKey.class: src/bplus/keys/BPlusNodeKey.java
		$(JC) $(JFLAGS) src/bplus/keys/BPlusNodeKey.java && mv src/bplus/keys/BPlusNodeKey.class bin/bplus/keys/BPlusNodeKey.class 
bin/bplus/keys/BPlusElementKey.class: src/bplus/keys/BPlusElementKey.java
		$(JC) $(JFLAGS) src/bplus/keys/BPlusElementKey.java && mv src/bplus/keys/BPlusElementKey.class bin/bplus/keys/BPlusElementKey.class 
bin/bplus/MockBPlusTreeFacade.class: src/bplus/MockBPlusTreeFacade.java
		$(JC) $(JFLAGS) src/bplus/MockBPlusTreeFacade.java && mv src/bplus/MockBPlusTreeFacade.class bin/bplus/MockBPlusTreeFacade.class 
bin/bplus/exceptions/BPlusException.class: src/bplus/exceptions/BPlusException.java
		$(JC) $(JFLAGS) src/bplus/exceptions/BPlusException.java && mv src/bplus/exceptions/BPlusException.class bin/bplus/exceptions/BPlusException.class 
bin/bplus/exceptions/BPlusNodeException.class: src/bplus/exceptions/BPlusNodeException.java
		$(JC) $(JFLAGS) src/bplus/exceptions/BPlusNodeException.java && mv src/bplus/exceptions/BPlusNodeException.class bin/bplus/exceptions/BPlusNodeException.class 
bin/bplus/exceptions/KeyNotFoundException.class: src/bplus/exceptions/KeyNotFoundException.java
		$(JC) $(JFLAGS) src/bplus/exceptions/KeyNotFoundException.java && mv src/bplus/exceptions/KeyNotFoundException.class bin/bplus/exceptions/KeyNotFoundException.class 
bin/bplus/exceptions/NodeNotFoundException.class: src/bplus/exceptions/NodeNotFoundException.java
		$(JC) $(JFLAGS) src/bplus/exceptions/NodeNotFoundException.java && mv src/bplus/exceptions/NodeNotFoundException.class bin/bplus/exceptions/NodeNotFoundException.class 
bin/bplus/exceptions/NodeOverflowException.class: src/bplus/exceptions/NodeOverflowException.java
		$(JC) $(JFLAGS) src/bplus/exceptions/NodeOverflowException.java && mv src/bplus/exceptions/NodeOverflowException.class bin/bplus/exceptions/NodeOverflowException.class 
bin/bplus/BPlusTreeFacade.class: src/bplus/BPlusTreeFacade.java
		$(JC) $(JFLAGS) src/bplus/BPlusTreeFacade.java && mv src/bplus/BPlusTreeFacade.class bin/bplus/BPlusTreeFacade.class 
bin/bplus/elements/BPlusLeafElement.class: src/bplus/elements/BPlusLeafElement.java
		$(JC) $(JFLAGS) src/bplus/elements/BPlusLeafElement.java && mv src/bplus/elements/BPlusLeafElement.class bin/bplus/elements/BPlusLeafElement.class 
bin/bplus/elements/BPlusElement.class: src/bplus/elements/BPlusElement.java
		$(JC) $(JFLAGS) src/bplus/elements/BPlusElement.java && mv src/bplus/elements/BPlusElement.class bin/bplus/elements/BPlusElement.class 
bin/bplus/elements/BPlusIndexElement.class: src/bplus/elements/BPlusIndexElement.java
		$(JC) $(JFLAGS) src/bplus/elements/BPlusIndexElement.java && mv src/bplus/elements/BPlusIndexElement.class bin/bplus/elements/BPlusIndexElement.class 
bin/bplus/elements/BPlusAbstractElement.class: src/bplus/elements/BPlusAbstractElement.java
		$(JC) $(JFLAGS) src/bplus/elements/BPlusAbstractElement.java && mv src/bplus/elements/BPlusAbstractElement.class bin/bplus/elements/BPlusAbstractElement.class 
bin/bplus/NodeHandler.class: src/bplus/NodeHandler.java
		$(JC) $(JFLAGS) src/bplus/NodeHandler.java && mv src/bplus/NodeHandler.class bin/bplus/NodeHandler.class 
bin/dto/SuffixDto.class: src/dto/SuffixDto.java
		$(JC) $(JFLAGS) src/dto/SuffixDto.java && mv src/dto/SuffixDto.class bin/dto/SuffixDto.class 
bin/dto/DocumentDto.class: src/dto/DocumentDto.java
		$(JC) $(JFLAGS) src/dto/DocumentDto.java && mv src/dto/DocumentDto.class bin/dto/DocumentDto.class 
bin/dto/LinkedBlock.class: src/dto/LinkedBlock.java
		$(JC) $(JFLAGS) src/dto/LinkedBlock.java && mv src/dto/LinkedBlock.class bin/dto/LinkedBlock.class 
bin/dto/StopwordsPipelineDto.class: src/dto/StopwordsPipelineDto.java
		$(JC) $(JFLAGS) src/dto/StopwordsPipelineDto.java && mv src/dto/StopwordsPipelineDto.class bin/dto/StopwordsPipelineDto.class 
bin/dto/WordDto.class: src/dto/WordDto.java
		$(JC) $(JFLAGS) src/dto/WordDto.java && mv src/dto/WordDto.class bin/dto/WordDto.class 
bin/utils/Constants.class: src/utils/Constants.java
		$(JC) $(JFLAGS) src/utils/Constants.java && mv src/utils/Constants.class bin/utils/Constants.class 
bin/utils/statistics/StatisticsGeneratorSingleton.class: src/utils/statistics/StatisticsGeneratorSingleton.java
		$(JC) $(JFLAGS) src/utils/statistics/StatisticsGeneratorSingleton.java && mv src/utils/statistics/StatisticsGeneratorSingleton.class bin/utils/statistics/StatisticsGeneratorSingleton.class 
bin/utils/statistics/StatisticsGenerator.class: src/utils/statistics/StatisticsGenerator.java
		$(JC) $(JFLAGS) src/utils/statistics/StatisticsGenerator.java && mv src/utils/statistics/StatisticsGenerator.class bin/utils/statistics/StatisticsGenerator.class 
bin/utils/statistics/Statistics.class: src/utils/statistics/Statistics.java
		$(JC) $(JFLAGS) src/utils/statistics/Statistics.java && mv src/utils/statistics/Statistics.class bin/utils/statistics/Statistics.class 
bin/exceptions/BusinessException.class: src/exceptions/BusinessException.java
		$(JC) $(JFLAGS) src/exceptions/BusinessException.java && mv src/exceptions/BusinessException.class bin/exceptions/BusinessException.class 
bin/exceptions/DataAccessException.class: src/exceptions/DataAccessException.java
		$(JC) $(JFLAGS) src/exceptions/DataAccessException.java && mv src/exceptions/DataAccessException.class bin/exceptions/DataAccessException.class 
bin/exceptions/PipelineOverflowException.class: src/exceptions/PipelineOverflowException.java
		$(JC) $(JFLAGS) src/exceptions/PipelineOverflowException.java && mv src/exceptions/PipelineOverflowException.class bin/exceptions/PipelineOverflowException.class 
bin/exceptions/PersistanceException.class: src/exceptions/PersistanceException.java
		$(JC) $(JFLAGS) src/exceptions/PersistanceException.java && mv src/exceptions/PersistanceException.class bin/exceptions/PersistanceException.class 
bin/SearchEngine.class: src/SearchEngine.java
		$(JC) $(JFLAGS) src/SearchEngine.java && mv src/SearchEngine.class bin/SearchEngine.class 
bin/api/po/files/Stack.class: src/api/po/files/Stack.java
		$(JC) $(JFLAGS) src/api/po/files/Stack.java && mv src/api/po/files/Stack.class bin/api/po/files/Stack.class 
bin/api/po/files/File.class: src/api/po/files/File.java
		$(JC) $(JFLAGS) src/api/po/files/File.java && mv src/api/po/files/File.class bin/api/po/files/File.class 
bin/api/po/persistors/Persistor.class: src/api/po/persistors/Persistor.java
		$(JC) $(JFLAGS) src/api/po/persistors/Persistor.java && mv src/api/po/persistors/Persistor.class bin/api/po/persistors/Persistor.class 
bin/api/po/persistors/SizeUtils.class: src/api/po/persistors/SizeUtils.java
		$(JC) $(JFLAGS) src/api/po/persistors/SizeUtils.java && mv src/api/po/persistors/SizeUtils.class bin/api/po/persistors/SizeUtils.class 
bin/api/po/persistors/DistancesBlock.class: src/api/po/persistors/DistancesBlock.java
		$(JC) $(JFLAGS) src/api/po/persistors/DistancesBlock.java && mv src/api/po/persistors/DistancesBlock.class bin/api/po/persistors/DistancesBlock.class 
bin/api/dao/documents/DocumentsDictionary.class: src/api/dao/documents/DocumentsDictionary.java
		$(JC) $(JFLAGS) src/api/dao/documents/DocumentsDictionary.java && mv src/api/dao/documents/DocumentsDictionary.class bin/api/dao/documents/DocumentsDictionary.class 
bin/api/dao/BPlusTree/BPlusNodeDao.class: src/api/dao/BPlusTree/BPlusNodeDao.java
		$(JC) $(JFLAGS) src/api/dao/BPlusTree/BPlusNodeDao.java && mv src/api/dao/BPlusTree/BPlusNodeDao.class bin/api/dao/BPlusTree/BPlusNodeDao.class 
bin/api/MockQueryEngine.class: src/api/MockQueryEngine.java
		$(JC) $(JFLAGS) src/api/MockQueryEngine.java && mv src/api/MockQueryEngine.class bin/api/MockQueryEngine.class 
bin/api/QueryEngine.class: src/api/QueryEngine.java
		$(JC) $(JFLAGS) src/api/QueryEngine.java && mv src/api/QueryEngine.class bin/api/QueryEngine.class 
bin/api/bo/BPlusTree/BPlusNodeBo.class: src/api/bo/BPlusTree/BPlusNodeBo.java
		$(JC) $(JFLAGS) src/api/bo/BPlusTree/BPlusNodeBo.java && mv src/api/bo/BPlusTree/BPlusNodeBo.class bin/api/bo/BPlusTree/BPlusNodeBo.class 
bin/api/bo/BPlusTree/BPlusTreeBo.class: src/api/bo/BPlusTree/BPlusTreeBo.java
		$(JC) $(JFLAGS) src/api/bo/BPlusTree/BPlusTreeBo.java && mv src/api/bo/BPlusTree/BPlusTreeBo.class bin/api/bo/BPlusTree/BPlusTreeBo.class 
bin/api/DocumentInsert.class: src/api/DocumentInsert.java
		$(JC) $(JFLAGS) src/api/DocumentInsert.java && mv src/api/DocumentInsert.class bin/api/DocumentInsert.class 
bin/api/ObjectFactory.class: src/api/ObjectFactory.java
		$(JC) $(JFLAGS) src/api/ObjectFactory.java && mv src/api/ObjectFactory.class bin/api/ObjectFactory.class 
bin/api/Index.class: src/api/Index.java
		$(JC) $(JFLAGS) src/api/Index.java && mv src/api/Index.class bin/api/Index.class 
bin/api/DefaultQueryEngine.class: src/api/DefaultQueryEngine.java
		$(JC) $(JFLAGS) src/api/DefaultQueryEngine.java && mv src/api/DefaultQueryEngine.class bin/api/DefaultQueryEngine.class 
bin/processor/IndexedDocumentChecker.class: src/processor/IndexedDocumentChecker.java
		$(JC) $(JFLAGS) src/processor/IndexedDocumentChecker.java && mv src/processor/IndexedDocumentChecker.class bin/processor/IndexedDocumentChecker.class 
bin/processor/stemming/StemmingProcessor.class: src/processor/stemming/StemmingProcessor.java
		$(JC) $(JFLAGS) src/processor/stemming/StemmingProcessor.java && mv src/processor/stemming/StemmingProcessor.class bin/processor/stemming/StemmingProcessor.class 
bin/processor/stopwords/StopwordsProcessor.class: src/processor/stopwords/StopwordsProcessor.java
		$(JC) $(JFLAGS) src/processor/stopwords/StopwordsProcessor.java && mv src/processor/stopwords/StopwordsProcessor.class bin/processor/stopwords/StopwordsProcessor.class 
bin/processor/utils/HtmlUtils.class: src/processor/utils/HtmlUtils.java
		$(JC) $(JFLAGS) src/processor/utils/HtmlUtils.java && mv src/processor/utils/HtmlUtils.class bin/processor/utils/HtmlUtils.class 
bin/processor/utils/DigesterUtils.class: src/processor/utils/DigesterUtils.java
		$(JC) $(JFLAGS) src/processor/utils/DigesterUtils.java && mv src/processor/utils/DigesterUtils.class bin/processor/utils/DigesterUtils.class 
bin/ControllerServlet.class: src/ControllerServlet.java
		$(JC) $(JFLAGS) src/ControllerServlet.java && mv src/ControllerServlet.class bin/ControllerServlet.class 
bin/app/po/files/AbstractFile.class: src/app/po/files/AbstractFile.java
		$(JC) $(JFLAGS) src/app/po/files/AbstractFile.java && mv src/app/po/files/AbstractFile.class bin/app/po/files/AbstractFile.class 
bin/app/po/files/SecuencialFile.class: src/app/po/files/SecuencialFile.java
		$(JC) $(JFLAGS) src/app/po/files/SecuencialFile.java && mv src/app/po/files/SecuencialFile.class bin/app/po/files/SecuencialFile.class 
bin/app/po/files/RelativeFile.class: src/app/po/files/RelativeFile.java
		$(JC) $(JFLAGS) src/app/po/files/RelativeFile.java && mv src/app/po/files/RelativeFile.class bin/app/po/files/RelativeFile.class 
bin/app/po/files/StreamFile.class: src/app/po/files/StreamFile.java
		$(JC) $(JFLAGS) src/app/po/files/StreamFile.java && mv src/app/po/files/StreamFile.class bin/app/po/files/StreamFile.class 
bin/app/po/files/SecuentialFile.class: src/app/po/files/SecuentialFile.java
		$(JC) $(JFLAGS) src/app/po/files/SecuentialFile.java && mv src/app/po/files/SecuentialFile.class bin/app/po/files/SecuentialFile.class 
bin/app/po/files/StackFile.class: src/app/po/files/StackFile.java
		$(JC) $(JFLAGS) src/app/po/files/StackFile.java && mv src/app/po/files/StackFile.class bin/app/po/files/StackFile.class 
bin/app/po/persistors/DocumentDataPersistor.class: src/app/po/persistors/DocumentDataPersistor.java
		$(JC) $(JFLAGS) src/app/po/persistors/DocumentDataPersistor.java && mv src/app/po/persistors/DocumentDataPersistor.class bin/app/po/persistors/DocumentDataPersistor.class 
bin/app/po/persistors/BPlusNodePersistor.class: src/app/po/persistors/BPlusNodePersistor.java
		$(JC) $(JFLAGS) src/app/po/persistors/BPlusNodePersistor.java && mv src/app/po/persistors/BPlusNodePersistor.class bin/app/po/persistors/BPlusNodePersistor.class 
bin/app/po/persistors/LinkedBlockIntPersistor.class: src/app/po/persistors/LinkedBlockIntPersistor.java
		$(JC) $(JFLAGS) src/app/po/persistors/LinkedBlockIntPersistor.java && mv src/app/po/persistors/LinkedBlockIntPersistor.class bin/app/po/persistors/LinkedBlockIntPersistor.class 
bin/app/po/persistors/LinkedBlockByteArrayPersistor.class: src/app/po/persistors/LinkedBlockByteArrayPersistor.java
		$(JC) $(JFLAGS) src/app/po/persistors/LinkedBlockByteArrayPersistor.java && mv src/app/po/persistors/LinkedBlockByteArrayPersistor.class bin/app/po/persistors/LinkedBlockByteArrayPersistor.class 
bin/app/po/persistors/BPlusElementPersistor.class: src/app/po/persistors/BPlusElementPersistor.java
		$(JC) $(JFLAGS) src/app/po/persistors/BPlusElementPersistor.java && mv src/app/po/persistors/BPlusElementPersistor.class bin/app/po/persistors/BPlusElementPersistor.class 
bin/app/po/persistors/VariableStringPersistor.class: src/app/po/persistors/VariableStringPersistor.java
		$(JC) $(JFLAGS) src/app/po/persistors/VariableStringPersistor.java && mv src/app/po/persistors/VariableStringPersistor.class bin/app/po/persistors/VariableStringPersistor.class 
bin/app/po/persistors/StringPersistor.class: src/app/po/persistors/StringPersistor.java
		$(JC) $(JFLAGS) src/app/po/persistors/StringPersistor.java && mv src/app/po/persistors/StringPersistor.class bin/app/po/persistors/StringPersistor.class 
bin/app/po/persistors/SimpleStringPersistor.class: src/app/po/persistors/SimpleStringPersistor.java
		$(JC) $(JFLAGS) src/app/po/persistors/SimpleStringPersistor.java && mv src/app/po/persistors/SimpleStringPersistor.class bin/app/po/persistors/SimpleStringPersistor.class 
bin/app/po/persistors/AbstractPersistor.class: src/app/po/persistors/AbstractPersistor.java
		$(JC) $(JFLAGS) src/app/po/persistors/AbstractPersistor.java && mv src/app/po/persistors/AbstractPersistor.class bin/app/po/persistors/AbstractPersistor.class 
bin/app/po/persistors/DocumentInfoPersistor.class: src/app/po/persistors/DocumentInfoPersistor.java
		$(JC) $(JFLAGS) src/app/po/persistors/DocumentInfoPersistor.java && mv src/app/po/persistors/DocumentInfoPersistor.class bin/app/po/persistors/DocumentInfoPersistor.class 
bin/app/po/persistors/MaxSizeAbstractPersistor.class: src/app/po/persistors/MaxSizeAbstractPersistor.java
		$(JC) $(JFLAGS) src/app/po/persistors/MaxSizeAbstractPersistor.java && mv src/app/po/persistors/MaxSizeAbstractPersistor.class bin/app/po/persistors/MaxSizeAbstractPersistor.class 
bin/app/po/persistors/IntegerPersistor.class: src/app/po/persistors/IntegerPersistor.java
		$(JC) $(JFLAGS) src/app/po/persistors/IntegerPersistor.java && mv src/app/po/persistors/IntegerPersistor.class bin/app/po/persistors/IntegerPersistor.class 
bin/app/po/persistors/BytePersistor.class: src/app/po/persistors/BytePersistor.java
		$(JC) $(JFLAGS) src/app/po/persistors/BytePersistor.java && mv src/app/po/persistors/BytePersistor.class bin/app/po/persistors/BytePersistor.class 
bin/app/dao/bplus/BPlusNodeDaoImp.class: src/app/dao/bplus/BPlusNodeDaoImp.java
		$(JC) $(JFLAGS) src/app/dao/bplus/BPlusNodeDaoImp.java && mv src/app/dao/bplus/BPlusNodeDaoImp.class bin/app/dao/bplus/BPlusNodeDaoImp.class 
bin/app/dao/bplus/BPlusNodeDaoTest.class: src/app/dao/bplus/BPlusNodeDaoTest.java
		$(JC) $(JFLAGS) src/app/dao/bplus/BPlusNodeDaoTest.java && mv src/app/dao/bplus/BPlusNodeDaoTest.class bin/app/dao/bplus/BPlusNodeDaoTest.class 
bin/app/dao/documents/DocumentsDictionaryImp.class: src/app/dao/documents/DocumentsDictionaryImp.java
		$(JC) $(JFLAGS) src/app/dao/documents/DocumentsDictionaryImp.java && mv src/app/dao/documents/DocumentsDictionaryImp.class bin/app/dao/documents/DocumentsDictionaryImp.class 
bin/app/bo/MockIndex.class: src/app/bo/MockIndex.java
		$(JC) $(JFLAGS) src/app/bo/MockIndex.java && mv src/app/bo/MockIndex.class bin/app/bo/MockIndex.class 
bin/app/bo/MockDocumentsDictionary.class: src/app/bo/MockDocumentsDictionary.java
		$(JC) $(JFLAGS) src/app/bo/MockDocumentsDictionary.java && mv src/app/bo/MockDocumentsDictionary.class bin/app/bo/MockDocumentsDictionary.class 
bin/app/bo/bplus/BPlusTreeBoImp.class: src/app/bo/bplus/BPlusTreeBoImp.java
		$(JC) $(JFLAGS) src/app/bo/bplus/BPlusTreeBoImp.java && mv src/app/bo/bplus/BPlusTreeBoImp.class bin/app/bo/bplus/BPlusTreeBoImp.class 
bin/app/bo/bplus/BPlusTreeBoTest.class: src/app/bo/bplus/BPlusTreeBoTest.java
		$(JC) $(JFLAGS) src/app/bo/bplus/BPlusTreeBoTest.java && mv src/app/bo/bplus/BPlusTreeBoTest.class bin/app/bo/bplus/BPlusTreeBoTest.class 
bin/app/bo/bplus/AbstractBPlusTreeBo.class: src/app/bo/bplus/AbstractBPlusTreeBo.java
		$(JC) $(JFLAGS) src/app/bo/bplus/AbstractBPlusTreeBo.java && mv src/app/bo/bplus/AbstractBPlusTreeBo.class bin/app/bo/bplus/AbstractBPlusTreeBo.class 
bin/app/bo/IndexImp.class: src/app/bo/IndexImp.java
		$(JC) $(JFLAGS) src/app/bo/IndexImp.java && mv src/app/bo/IndexImp.class bin/app/bo/IndexImp.class 
bin/test/index/TestDocumentsDictionary.class: src/test/index/TestDocumentsDictionary.java
		$(JC) $(JFLAGS) src/test/index/TestDocumentsDictionary.java && mv src/test/index/TestDocumentsDictionary.class bin/test/index/TestDocumentsDictionary.class 
bin/test/index/TestMockIndex.class: src/test/index/TestMockIndex.java
		$(JC) $(JFLAGS) src/test/index/TestMockIndex.java && mv src/test/index/TestMockIndex.class bin/test/index/TestMockIndex.class 
bin/test/index/TestDocumentsDictionaryImp.class: src/test/index/TestDocumentsDictionaryImp.java
		$(JC) $(JFLAGS) src/test/index/TestDocumentsDictionaryImp.java && mv src/test/index/TestDocumentsDictionaryImp.class bin/test/index/TestDocumentsDictionaryImp.class 
bin/test/index/TestQueryEngineMocks.class: src/test/index/TestQueryEngineMocks.java
		$(JC) $(JFLAGS) src/test/index/TestQueryEngineMocks.java && mv src/test/index/TestQueryEngineMocks.class bin/test/index/TestQueryEngineMocks.class 
bin/test/index/TestIndexImp.class: src/test/index/TestIndexImp.java
		$(JC) $(JFLAGS) src/test/index/TestIndexImp.java && mv src/test/index/TestIndexImp.class bin/test/index/TestIndexImp.class 
bin/test/index/TestQueryEngine.class: src/test/index/TestQueryEngine.java
		$(JC) $(JFLAGS) src/test/index/TestQueryEngine.java && mv src/test/index/TestQueryEngine.class bin/test/index/TestQueryEngine.class 
bin/test/index/TestMockDocumentsDictionary.class: src/test/index/TestMockDocumentsDictionary.java
		$(JC) $(JFLAGS) src/test/index/TestMockDocumentsDictionary.java && mv src/test/index/TestMockDocumentsDictionary.class bin/test/index/TestMockDocumentsDictionary.class 
bin/test/index/TestDefaultQueryEngine.class: src/test/index/TestDefaultQueryEngine.java
		$(JC) $(JFLAGS) src/test/index/TestDefaultQueryEngine.java && mv src/test/index/TestDefaultQueryEngine.class bin/test/index/TestDefaultQueryEngine.class 
bin/test/index/TestIndex.class: src/test/index/TestIndex.java
		$(JC) $(JFLAGS) src/test/index/TestIndex.java && mv src/test/index/TestIndex.class bin/test/index/TestIndex.class 
bin/test/files/RelativelFileTest.class: src/test/files/RelativelFileTest.java
		$(JC) $(JFLAGS) src/test/files/RelativelFileTest.java && mv src/test/files/RelativelFileTest.class bin/test/files/RelativelFileTest.class 
bin/test/files/test.class: src/test/files/test.java
		$(JC) $(JFLAGS) src/test/files/test.java && mv src/test/files/test.class bin/test/files/test.class 
bin/test/files/SecuentialFileTest.class: src/test/files/SecuentialFileTest.java
		$(JC) $(JFLAGS) src/test/files/SecuentialFileTest.java && mv src/test/files/SecuentialFileTest.class bin/test/files/SecuentialFileTest.class 
bin/test/files/FileTest.class: src/test/files/FileTest.java
		$(JC) $(JFLAGS) src/test/files/FileTest.java && mv src/test/files/FileTest.class bin/test/files/FileTest.class 
bin/test/files/StackFileTest.class: src/test/files/StackFileTest.java
		$(JC) $(JFLAGS) src/test/files/StackFileTest.java && mv src/test/files/StackFileTest.class bin/test/files/StackFileTest.class 
bin/test/persistors/TestIntegerPersistor.class: src/test/persistors/TestIntegerPersistor.java
		$(JC) $(JFLAGS) src/test/persistors/TestIntegerPersistor.java && mv src/test/persistors/TestIntegerPersistor.class bin/test/persistors/TestIntegerPersistor.class 
bin/test/persistors/TestPersistor.class: src/test/persistors/TestPersistor.java
		$(JC) $(JFLAGS) src/test/persistors/TestPersistor.java && mv src/test/persistors/TestPersistor.class bin/test/persistors/TestPersistor.class 
bin/test/persistors/TestBPlusNodePersistor.class: src/test/persistors/TestBPlusNodePersistor.java
		$(JC) $(JFLAGS) src/test/persistors/TestBPlusNodePersistor.java && mv src/test/persistors/TestBPlusNodePersistor.class bin/test/persistors/TestBPlusNodePersistor.class 
bin/test/persistors/TestBytePersistor.class: src/test/persistors/TestBytePersistor.java
		$(JC) $(JFLAGS) src/test/persistors/TestBytePersistor.java && mv src/test/persistors/TestBytePersistor.class bin/test/persistors/TestBytePersistor.class 
bin/test/persistors/TestStringPersistor.class: src/test/persistors/TestStringPersistor.java
		$(JC) $(JFLAGS) src/test/persistors/TestStringPersistor.java && mv src/test/persistors/TestStringPersistor.class bin/test/persistors/TestStringPersistor.class 
bin/test/bplus/BPlusNodeTestUtils.class: src/test/bplus/BPlusNodeTestUtils.java
		$(JC) $(JFLAGS) src/test/bplus/BPlusNodeTestUtils.java && mv src/test/bplus/BPlusNodeTestUtils.class bin/test/bplus/BPlusNodeTestUtils.class 
bin/test/bplus/TestBPlusTreeBo.class: src/test/bplus/TestBPlusTreeBo.java
		$(JC) $(JFLAGS) src/test/bplus/TestBPlusTreeBo.java && mv src/test/bplus/TestBPlusTreeBo.class bin/test/bplus/TestBPlusTreeBo.class 
bin/test/bplus/TestBPlusTreeBoImp.class: src/test/bplus/TestBPlusTreeBoImp.java
		$(JC) $(JFLAGS) src/test/bplus/TestBPlusTreeBoImp.java && mv src/test/bplus/TestBPlusTreeBoImp.class bin/test/bplus/TestBPlusTreeBoImp.class 
bin/test/bplus/TestBPlusTreeBoImpDaoTest.class: src/test/bplus/TestBPlusTreeBoImpDaoTest.java
		$(JC) $(JFLAGS) src/test/bplus/TestBPlusTreeBoImpDaoTest.java && mv src/test/bplus/TestBPlusTreeBoImpDaoTest.class bin/test/bplus/TestBPlusTreeBoImpDaoTest.class 
bin/test/bplus/MapTest.class: src/test/bplus/MapTest.java
		$(JC) $(JFLAGS) src/test/bplus/MapTest.java && mv src/test/bplus/MapTest.class bin/test/bplus/MapTest.class 
bin/test/bplus/TestBPlusNodeDao.class: src/test/bplus/TestBPlusNodeDao.java
		$(JC) $(JFLAGS) src/test/bplus/TestBPlusNodeDao.java && mv src/test/bplus/TestBPlusNodeDao.class bin/test/bplus/TestBPlusNodeDao.class 
bin/test/bplus/BPlusTreeBoDaoTest.class: src/test/bplus/BPlusTreeBoDaoTest.java
		$(JC) $(JFLAGS) src/test/bplus/BPlusTreeBoDaoTest.java && mv src/test/bplus/BPlusTreeBoDaoTest.class bin/test/bplus/BPlusTreeBoDaoTest.class 
bin/test/bplus/TestBPlusNodeDaoTest.class: src/test/bplus/TestBPlusNodeDaoTest.java
		$(JC) $(JFLAGS) src/test/bplus/TestBPlusNodeDaoTest.java && mv src/test/bplus/TestBPlusNodeDaoTest.class bin/test/bplus/TestBPlusNodeDaoTest.class 
bin/test/bplus/TestBPlusNodeDaoImp.class: src/test/bplus/TestBPlusNodeDaoImp.java
		$(JC) $(JFLAGS) src/test/bplus/TestBPlusNodeDaoImp.java && mv src/test/bplus/TestBPlusNodeDaoImp.class bin/test/bplus/TestBPlusNodeDaoImp.class 
bin/test/bplus/TestBPlusTreeBoTest.class: src/test/bplus/TestBPlusTreeBoTest.java
		$(JC) $(JFLAGS) src/test/bplus/TestBPlusTreeBoTest.java && mv src/test/bplus/TestBPlusTreeBoTest.class bin/test/bplus/TestBPlusTreeBoTest.class 
bin/test/utils/KeyCodificationTest.class: src/test/utils/KeyCodificationTest.java
		$(JC) $(JFLAGS) src/test/utils/KeyCodificationTest.java && mv src/test/utils/KeyCodificationTest.class bin/test/utils/KeyCodificationTest.class 
bin/test/processor/TestStemmerProcessor.class: src/test/processor/TestStemmerProcessor.java
		$(JC) $(JFLAGS) src/test/processor/TestStemmerProcessor.java && mv src/test/processor/TestStemmerProcessor.class bin/test/processor/TestStemmerProcessor.class 
bin/DocumentsIndexer.class: src/DocumentsIndexer.java
		$(JC) $(JFLAGS) src/DocumentsIndexer.java && mv src/DocumentsIndexer.class bin/DocumentsIndexer.class 
bin/TreeDumper.class: src/TreeDumper.java
		$(JC) $(JFLAGS) src/TreeDumper.java && mv src/TreeDumper.class bin/TreeDumper.class 


