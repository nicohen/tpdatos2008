CLASSPATHS=src:lib/htmlparser.jar:lib/servlet-api.jar:lib/junit-4.5.jar:lib/log4j-1.2.15.jar

JFLAGS = -g -classpath $(CLASSPATHS)
JC = javac


CLASSES = ./src/app/dao/bplus/BPlusNodeDaoTest.java ./src/app/dao/bplus/BPlusNodeDaoImp.java ./src/app/dao/documents/DocumentsDictionaryImp.java ./src/app/bo/bplus/AbstractBPlusTreeBo.java ./src/app/bo/bplus/BPlusTreeBoImp.java ./src/app/bo/bplus/BPlusTreeBoTest.java ./src/app/bo/MockDocumentsDictionary.java ./src/app/bo/MockIndex.java ./src/app/bo/IndexImp.java ./src/app/po/files/StackFile.java ./src/app/po/files/SecuencialFile.java ./src/app/po/files/AbstractFile.java ./src/app/po/files/StreamFile.java ./src/app/po/files/RelativeFile.java ./src/app/po/files/SecuentialFile.java ./src/app/po/persistors/IntegerPersistor.java ./src/app/po/persistors/SimpleStringPersistor.java ./src/app/po/persistors/LinkedBlockByteArrayPersistor.java ./src/app/po/persistors/DocumentInfoPersistor.java ./src/app/po/persistors/AbstractPersistor.java ./src/app/po/persistors/BytePersistor.java ./src/app/po/persistors/MaxSizeAbstractPersistor.java ./src/app/po/persistors/DocumentDataPersistor.java ./src/app/po/persistors/StringPersistor.java ./src/app/po/persistors/BPlusNodePersistor.java ./src/app/po/persistors/LinkedBlockIntPersistor.java ./src/app/po/persistors/BPlusElementPersistor.java ./src/app/po/persistors/VariableStringPersistor.java ./src/api/QueryEngine.java ./src/api/dao/documents/DocumentsDictionary.java ./src/api/dao/BPlusTree/BPlusNodeDao.java ./src/api/bo/BPlusTree/BPlusTreeBo.java ./src/api/bo/BPlusTree/BPlusNodeBo.java ./src/api/po/files/Stack.java ./src/api/po/files/File.java ./src/api/po/persistors/Persistor.java ./src/api/po/persistors/DistancesBlock.java ./src/api/po/persistors/SizeUtils.java ./src/api/DocumentInsert.java ./src/api/ObjectFactory.java ./src/api/DefaultQueryEngine.java ./src/api/MockQueryEngine.java ./src/api/Index.java ./src/dto/LinkedBlock.java ./src/dto/SuffixDto.java ./src/dto/StopwordsPipelineDto.java ./src/dto/WordDto.java ./src/dto/DocumentDto.java ./src/processor/stopwords/StopwordsProcessor.java ./src/processor/stemming/StemmingProcessor.java ./src/processor/utils/HtmlUtils.java ./src/processor/utils/DigesterUtils.java ./src/processor/IndexedDocumentChecker.java ./src/exceptions/BusinessException.java ./src/exceptions/PersistanceException.java ./src/exceptions/PipelineOverflowException.java ./src/exceptions/DataAccessException.java ./src/bplus/exceptions/BPlusNodeException.java ./src/bplus/exceptions/NodeOverflowException.java ./src/bplus/exceptions/KeyNotFoundException.java ./src/bplus/exceptions/NodeNotFoundException.java ./src/bplus/exceptions/BPlusException.java ./src/bplus/elements/BPlusAbstractElement.java ./src/bplus/elements/BPlusLeafElement.java ./src/bplus/elements/BPlusElement.java ./src/bplus/elements/BPlusIndexElement.java ./src/bplus/nodes/BPlusIndexNode.java ./src/bplus/nodes/AbstractBPlusNode.java ./src/bplus/nodes/BPlusLeafNode.java ./src/bplus/nodes/BPlusNode.java ./src/bplus/NodeHandler.java ./src/bplus/BPlusTreeFacade.java ./src/bplus/keys/BPlusNodeKey.java ./src/bplus/keys/BPlusElementKey.java ./src/bplus/MockBPlusTreeFacade.java ./src/utils/statistics/StatisticsGeneratorSingleton.java ./src/utils/statistics/StatisticsGenerator.java ./src/utils/statistics/Statistics.java ./src/utils/Constants.java ./src/SearchEngine.java ./src/DocumentsIndexer.java ./src/test/processor/TestStemmerProcessor.java ./src/test/files/StackFileTest.java ./src/test/files/SecuentialFileTest.java ./src/test/files/RelativelFileTest.java ./src/test/files/FileTest.java ./src/test/files/test.java ./src/test/index/TestMockDocumentsDictionary.java ./src/test/index/TestMockIndex.java ./src/test/index/TestDocumentsDictionary.java ./src/test/index/TestDefaultQueryEngine.java ./src/test/index/TestQueryEngineMocks.java ./src/test/index/TestDocumentsDictionaryImp.java ./src/test/index/TestIndexImp.java ./src/test/index/TestQueryEngine.java ./src/test/index/TestIndex.java ./src/test/bplus/TestBPlusTreeBoImp.java ./src/test/bplus/TestBPlusNodeDao.java ./src/test/bplus/BPlusTreeBoDaoTest.java ./src/test/bplus/TestBPlusTreeBoImpDaoTest.java ./src/test/bplus/TestBPlusNodeDaoTest.java ./src/test/bplus/TestBPlusNodeDaoImp.java ./src/test/bplus/BPlusNodeTestUtils.java ./src/test/bplus/TestBPlusTreeBoTest.java ./src/test/bplus/MapTest.java ./src/test/bplus/TestBPlusTreeBo.java ./src/test/persistors/TestBPlusNodePersistor.java ./src/test/persistors/TestPersistor.java ./src/test/persistors/TestIntegerPersistor.java ./src/test/persistors/TestStringPersistor.java ./src/test/persistors/TestBytePersistor.java ./src/test/utils/KeyCodificationTest.java ./src/ControllerServlet.java ./src/linkedblocks/VariableLinkedBlocksManager.java ./src/linkedblocks/LinkedBlocksManager.java ./src/linkedblocks/codification/GammaDistancesBlock.java ./src/linkedblocks/utils/KeyCodificationUtils.java ./src/linkedblocks/keys/DocumentIndexKey.java ./src/TreeDumper.java

default: classes
classes: ./bin/app/dao/bplus/BPlusNodeDaoTest.class ./bin/app/dao/bplus/BPlusNodeDaoImp.class ./bin/app/dao/documents/DocumentsDictionaryImp.class ./bin/app/bo/bplus/AbstractBPlusTreeBo.class ./bin/app/bo/bplus/BPlusTreeBoImp.class ./bin/app/bo/bplus/BPlusTreeBoTest.class ./bin/app/bo/MockDocumentsDictionary.class ./bin/app/bo/MockIndex.class ./bin/app/bo/IndexImp.class ./bin/app/po/files/StackFile.class ./bin/app/po/files/SecuencialFile.class ./bin/app/po/files/AbstractFile.class ./bin/app/po/files/StreamFile.class ./bin/app/po/files/RelativeFile.class ./bin/app/po/files/SecuentialFile.class ./bin/app/po/persistors/IntegerPersistor.class ./bin/app/po/persistors/SimpleStringPersistor.class ./bin/app/po/persistors/LinkedBlockByteArrayPersistor.class ./bin/app/po/persistors/DocumentInfoPersistor.class ./bin/app/po/persistors/AbstractPersistor.class ./bin/app/po/persistors/BytePersistor.class ./bin/app/po/persistors/MaxSizeAbstractPersistor.class ./bin/app/po/persistors/DocumentDataPersistor.class ./bin/app/po/persistors/StringPersistor.class ./bin/app/po/persistors/BPlusNodePersistor.class ./bin/app/po/persistors/LinkedBlockIntPersistor.class ./bin/app/po/persistors/BPlusElementPersistor.class ./bin/app/po/persistors/VariableStringPersistor.class ./bin/api/QueryEngine.class ./bin/api/dao/documents/DocumentsDictionary.class ./bin/api/dao/BPlusTree/BPlusNodeDao.class ./bin/api/bo/BPlusTree/BPlusTreeBo.class ./bin/api/bo/BPlusTree/BPlusNodeBo.class ./bin/api/po/files/Stack.class ./bin/api/po/files/File.class ./bin/api/po/persistors/Persistor.class ./bin/api/po/persistors/DistancesBlock.class ./bin/api/po/persistors/SizeUtils.class ./bin/api/DocumentInsert.class ./bin/api/ObjectFactory.class ./bin/api/DefaultQueryEngine.class ./bin/api/MockQueryEngine.class ./bin/api/Index.class ./bin/dto/LinkedBlock.class ./bin/dto/SuffixDto.class ./bin/dto/StopwordsPipelineDto.class ./bin/dto/WordDto.class ./bin/dto/DocumentDto.class ./bin/processor/stopwords/StopwordsProcessor.class ./bin/processor/stemming/StemmingProcessor.class ./bin/processor/utils/HtmlUtils.class ./bin/processor/utils/DigesterUtils.class ./bin/processor/IndexedDocumentChecker.class ./bin/exceptions/BusinessException.class ./bin/exceptions/PersistanceException.class ./bin/exceptions/PipelineOverflowException.class ./bin/exceptions/DataAccessException.class ./bin/bplus/exceptions/BPlusNodeException.class ./bin/bplus/exceptions/NodeOverflowException.class ./bin/bplus/exceptions/KeyNotFoundException.class ./bin/bplus/exceptions/NodeNotFoundException.class ./bin/bplus/exceptions/BPlusException.class ./bin/bplus/elements/BPlusAbstractElement.class ./bin/bplus/elements/BPlusLeafElement.class ./bin/bplus/elements/BPlusElement.class ./bin/bplus/elements/BPlusIndexElement.class ./bin/bplus/nodes/BPlusIndexNode.class ./bin/bplus/nodes/AbstractBPlusNode.class ./bin/bplus/nodes/BPlusLeafNode.class ./bin/bplus/nodes/BPlusNode.class ./bin/bplus/NodeHandler.class ./bin/bplus/BPlusTreeFacade.class ./bin/bplus/keys/BPlusNodeKey.class ./bin/bplus/keys/BPlusElementKey.class ./bin/bplus/MockBPlusTreeFacade.class ./bin/utils/statistics/StatisticsGeneratorSingleton.class ./bin/utils/statistics/StatisticsGenerator.class ./bin/utils/statistics/Statistics.class ./bin/utils/Constants.class ./bin/SearchEngine.class ./bin/DocumentsIndexer.class ./bin/test/processor/TestStemmerProcessor.class ./bin/test/files/StackFileTest.class ./bin/test/files/SecuentialFileTest.class ./bin/test/files/RelativelFileTest.class ./bin/test/files/FileTest.class ./bin/test/files/test.class ./bin/test/index/TestMockDocumentsDictionary.class ./bin/test/index/TestMockIndex.class ./bin/test/index/TestDocumentsDictionary.class ./bin/test/index/TestDefaultQueryEngine.class ./bin/test/index/TestQueryEngineMocks.class ./bin/test/index/TestDocumentsDictionaryImp.class ./bin/test/index/TestIndexImp.class ./bin/test/index/TestQueryEngine.class ./bin/test/index/TestIndex.class ./bin/test/bplus/TestBPlusTreeBoImp.class ./bin/test/bplus/TestBPlusNodeDao.class ./bin/test/bplus/BPlusTreeBoDaoTest.class ./bin/test/bplus/TestBPlusTreeBoImpDaoTest.class ./bin/test/bplus/TestBPlusNodeDaoTest.class ./bin/test/bplus/TestBPlusNodeDaoImp.class ./bin/test/bplus/BPlusNodeTestUtils.class ./bin/test/bplus/TestBPlusTreeBoTest.class ./bin/test/bplus/MapTest.class ./bin/test/bplus/TestBPlusTreeBo.class ./bin/test/persistors/TestBPlusNodePersistor.class ./bin/test/persistors/TestPersistor.class ./bin/test/persistors/TestIntegerPersistor.class ./bin/test/persistors/TestStringPersistor.class ./bin/test/persistors/TestBytePersistor.class ./bin/test/utils/KeyCodificationTest.class ./bin/ControllerServlet.class ./bin/linkedblocks/VariableLinkedBlocksManager.class ./bin/linkedblocks/LinkedBlocksManager.class ./bin/linkedblocks/codification/GammaDistancesBlock.class ./bin/linkedblocks/utils/KeyCodificationUtils.class ./bin/linkedblocks/keys/DocumentIndexKey.class ./bin/TreeDumper.class
clean:
	   rm $(CLASSES:.java=.class)

bin/app/dao/bplus/BPlusNodeDaoTest.class: src/app/dao/bplus/BPlusNodeDaoTest.java
		$(JC) $(JFLAGS) src/app/dao/bplus/BPlusNodeDaoTest.java
bin/app/dao/bplus/BPlusNodeDaoImp.class: src/app/dao/bplus/BPlusNodeDaoImp.java
		$(JC) $(JFLAGS) src/app/dao/bplus/BPlusNodeDaoImp.java
bin/app/dao/documents/DocumentsDictionaryImp.class: src/app/dao/documents/DocumentsDictionaryImp.java
		$(JC) $(JFLAGS) src/app/dao/documents/DocumentsDictionaryImp.java
bin/app/bo/bplus/AbstractBPlusTreeBo.class: src/app/bo/bplus/AbstractBPlusTreeBo.java
		$(JC) $(JFLAGS) src/app/bo/bplus/AbstractBPlusTreeBo.java
bin/app/bo/bplus/BPlusTreeBoImp.class: src/app/bo/bplus/BPlusTreeBoImp.java
		$(JC) $(JFLAGS) src/app/bo/bplus/BPlusTreeBoImp.java
bin/app/bo/bplus/BPlusTreeBoTest.class: src/app/bo/bplus/BPlusTreeBoTest.java
		$(JC) $(JFLAGS) src/app/bo/bplus/BPlusTreeBoTest.java
bin/app/bo/MockDocumentsDictionary.class: src/app/bo/MockDocumentsDictionary.java
		$(JC) $(JFLAGS) src/app/bo/MockDocumentsDictionary.java
bin/app/bo/MockIndex.class: src/app/bo/MockIndex.java
		$(JC) $(JFLAGS) src/app/bo/MockIndex.java
bin/app/bo/IndexImp.class: src/app/bo/IndexImp.java
		$(JC) $(JFLAGS) src/app/bo/IndexImp.java
bin/app/po/files/StackFile.class: src/app/po/files/StackFile.java
		$(JC) $(JFLAGS) src/app/po/files/StackFile.java
bin/app/po/files/SecuencialFile.class: src/app/po/files/SecuencialFile.java
		$(JC) $(JFLAGS) src/app/po/files/SecuencialFile.java
bin/app/po/files/AbstractFile.class: src/app/po/files/AbstractFile.java
		$(JC) $(JFLAGS) src/app/po/files/AbstractFile.java
bin/app/po/files/StreamFile.class: src/app/po/files/StreamFile.java
		$(JC) $(JFLAGS) src/app/po/files/StreamFile.java
bin/app/po/files/RelativeFile.class: src/app/po/files/RelativeFile.java
		$(JC) $(JFLAGS) src/app/po/files/RelativeFile.java
bin/app/po/files/SecuentialFile.class: src/app/po/files/SecuentialFile.java
		$(JC) $(JFLAGS) src/app/po/files/SecuentialFile.java
bin/app/po/persistors/IntegerPersistor.class: src/app/po/persistors/IntegerPersistor.java
		$(JC) $(JFLAGS) src/app/po/persistors/IntegerPersistor.java
bin/app/po/persistors/SimpleStringPersistor.class: src/app/po/persistors/SimpleStringPersistor.java
		$(JC) $(JFLAGS) src/app/po/persistors/SimpleStringPersistor.java
bin/app/po/persistors/LinkedBlockByteArrayPersistor.class: src/app/po/persistors/LinkedBlockByteArrayPersistor.java
		$(JC) $(JFLAGS) src/app/po/persistors/LinkedBlockByteArrayPersistor.java
bin/app/po/persistors/DocumentInfoPersistor.class: src/app/po/persistors/DocumentInfoPersistor.java
		$(JC) $(JFLAGS) src/app/po/persistors/DocumentInfoPersistor.java
bin/app/po/persistors/AbstractPersistor.class: src/app/po/persistors/AbstractPersistor.java
		$(JC) $(JFLAGS) src/app/po/persistors/AbstractPersistor.java
bin/app/po/persistors/BytePersistor.class: src/app/po/persistors/BytePersistor.java
		$(JC) $(JFLAGS) src/app/po/persistors/BytePersistor.java
bin/app/po/persistors/MaxSizeAbstractPersistor.class: src/app/po/persistors/MaxSizeAbstractPersistor.java
		$(JC) $(JFLAGS) src/app/po/persistors/MaxSizeAbstractPersistor.java
bin/app/po/persistors/DocumentDataPersistor.class: src/app/po/persistors/DocumentDataPersistor.java
		$(JC) $(JFLAGS) src/app/po/persistors/DocumentDataPersistor.java
bin/app/po/persistors/StringPersistor.class: src/app/po/persistors/StringPersistor.java
		$(JC) $(JFLAGS) src/app/po/persistors/StringPersistor.java
bin/app/po/persistors/BPlusNodePersistor.class: src/app/po/persistors/BPlusNodePersistor.java
		$(JC) $(JFLAGS) src/app/po/persistors/BPlusNodePersistor.java
bin/app/po/persistors/LinkedBlockIntPersistor.class: src/app/po/persistors/LinkedBlockIntPersistor.java
		$(JC) $(JFLAGS) src/app/po/persistors/LinkedBlockIntPersistor.java
bin/app/po/persistors/BPlusElementPersistor.class: src/app/po/persistors/BPlusElementPersistor.java
		$(JC) $(JFLAGS) src/app/po/persistors/BPlusElementPersistor.java
bin/app/po/persistors/VariableStringPersistor.class: src/app/po/persistors/VariableStringPersistor.java
		$(JC) $(JFLAGS) src/app/po/persistors/VariableStringPersistor.java
bin/api/QueryEngine.class: src/api/QueryEngine.java
		$(JC) $(JFLAGS) src/api/QueryEngine.java
bin/api/dao/documents/DocumentsDictionary.class: src/api/dao/documents/DocumentsDictionary.java
		$(JC) $(JFLAGS) src/api/dao/documents/DocumentsDictionary.java
bin/api/dao/BPlusTree/BPlusNodeDao.class: src/api/dao/BPlusTree/BPlusNodeDao.java
		$(JC) $(JFLAGS) src/api/dao/BPlusTree/BPlusNodeDao.java
bin/api/bo/BPlusTree/BPlusTreeBo.class: src/api/bo/BPlusTree/BPlusTreeBo.java
		$(JC) $(JFLAGS) src/api/bo/BPlusTree/BPlusTreeBo.java
bin/api/bo/BPlusTree/BPlusNodeBo.class: src/api/bo/BPlusTree/BPlusNodeBo.java
		$(JC) $(JFLAGS) src/api/bo/BPlusTree/BPlusNodeBo.java
bin/api/po/files/Stack.class: src/api/po/files/Stack.java
		$(JC) $(JFLAGS) src/api/po/files/Stack.java
bin/api/po/files/File.class: src/api/po/files/File.java
		$(JC) $(JFLAGS) src/api/po/files/File.java
bin/api/po/persistors/Persistor.class: src/api/po/persistors/Persistor.java
		$(JC) $(JFLAGS) src/api/po/persistors/Persistor.java
bin/api/po/persistors/DistancesBlock.class: src/api/po/persistors/DistancesBlock.java
		$(JC) $(JFLAGS) src/api/po/persistors/DistancesBlock.java
bin/api/po/persistors/SizeUtils.class: src/api/po/persistors/SizeUtils.java
		$(JC) $(JFLAGS) src/api/po/persistors/SizeUtils.java
bin/api/DocumentInsert.class: src/api/DocumentInsert.java
		$(JC) $(JFLAGS) src/api/DocumentInsert.java
bin/api/ObjectFactory.class: src/api/ObjectFactory.java
		$(JC) $(JFLAGS) src/api/ObjectFactory.java
bin/api/DefaultQueryEngine.class: src/api/DefaultQueryEngine.java
		$(JC) $(JFLAGS) src/api/DefaultQueryEngine.java
bin/api/MockQueryEngine.class: src/api/MockQueryEngine.java
		$(JC) $(JFLAGS) src/api/MockQueryEngine.java
bin/api/Index.class: src/api/Index.java
		$(JC) $(JFLAGS) src/api/Index.java
bin/dto/LinkedBlock.class: src/dto/LinkedBlock.java
		$(JC) $(JFLAGS) src/dto/LinkedBlock.java
bin/dto/SuffixDto.class: src/dto/SuffixDto.java
		$(JC) $(JFLAGS) src/dto/SuffixDto.java
bin/dto/StopwordsPipelineDto.class: src/dto/StopwordsPipelineDto.java
		$(JC) $(JFLAGS) src/dto/StopwordsPipelineDto.java
bin/dto/WordDto.class: src/dto/WordDto.java
		$(JC) $(JFLAGS) src/dto/WordDto.java
bin/dto/DocumentDto.class: src/dto/DocumentDto.java
		$(JC) $(JFLAGS) src/dto/DocumentDto.java
bin/processor/stopwords/StopwordsProcessor.class: src/processor/stopwords/StopwordsProcessor.java
		$(JC) $(JFLAGS) src/processor/stopwords/StopwordsProcessor.java
bin/processor/stemming/StemmingProcessor.class: src/processor/stemming/StemmingProcessor.java
		$(JC) $(JFLAGS) src/processor/stemming/StemmingProcessor.java
bin/processor/utils/HtmlUtils.class: src/processor/utils/HtmlUtils.java
		$(JC) $(JFLAGS) src/processor/utils/HtmlUtils.java
bin/processor/utils/DigesterUtils.class: src/processor/utils/DigesterUtils.java
		$(JC) $(JFLAGS) src/processor/utils/DigesterUtils.java
bin/processor/IndexedDocumentChecker.class: src/processor/IndexedDocumentChecker.java
		$(JC) $(JFLAGS) src/processor/IndexedDocumentChecker.java
bin/exceptions/BusinessException.class: src/exceptions/BusinessException.java
		$(JC) $(JFLAGS) src/exceptions/BusinessException.java
bin/exceptions/PersistanceException.class: src/exceptions/PersistanceException.java
		$(JC) $(JFLAGS) src/exceptions/PersistanceException.java
bin/exceptions/PipelineOverflowException.class: src/exceptions/PipelineOverflowException.java
		$(JC) $(JFLAGS) src/exceptions/PipelineOverflowException.java
bin/exceptions/DataAccessException.class: src/exceptions/DataAccessException.java
		$(JC) $(JFLAGS) src/exceptions/DataAccessException.java
bin/bplus/exceptions/BPlusNodeException.class: src/bplus/exceptions/BPlusNodeException.java
		$(JC) $(JFLAGS) src/bplus/exceptions/BPlusNodeException.java
bin/bplus/exceptions/NodeOverflowException.class: src/bplus/exceptions/NodeOverflowException.java
		$(JC) $(JFLAGS) src/bplus/exceptions/NodeOverflowException.java
bin/bplus/exceptions/KeyNotFoundException.class: src/bplus/exceptions/KeyNotFoundException.java
		$(JC) $(JFLAGS) src/bplus/exceptions/KeyNotFoundException.java
bin/bplus/exceptions/NodeNotFoundException.class: src/bplus/exceptions/NodeNotFoundException.java
		$(JC) $(JFLAGS) src/bplus/exceptions/NodeNotFoundException.java
bin/bplus/exceptions/BPlusException.class: src/bplus/exceptions/BPlusException.java
		$(JC) $(JFLAGS) src/bplus/exceptions/BPlusException.java
bin/bplus/elements/BPlusAbstractElement.class: src/bplus/elements/BPlusAbstractElement.java
		$(JC) $(JFLAGS) src/bplus/elements/BPlusAbstractElement.java
bin/bplus/elements/BPlusLeafElement.class: src/bplus/elements/BPlusLeafElement.java
		$(JC) $(JFLAGS) src/bplus/elements/BPlusLeafElement.java
bin/bplus/elements/BPlusElement.class: src/bplus/elements/BPlusElement.java
		$(JC) $(JFLAGS) src/bplus/elements/BPlusElement.java
bin/bplus/elements/BPlusIndexElement.class: src/bplus/elements/BPlusIndexElement.java
		$(JC) $(JFLAGS) src/bplus/elements/BPlusIndexElement.java
bin/bplus/nodes/BPlusIndexNode.class: src/bplus/nodes/BPlusIndexNode.java
		$(JC) $(JFLAGS) src/bplus/nodes/BPlusIndexNode.java
bin/bplus/nodes/AbstractBPlusNode.class: src/bplus/nodes/AbstractBPlusNode.java
		$(JC) $(JFLAGS) src/bplus/nodes/AbstractBPlusNode.java
bin/bplus/nodes/BPlusLeafNode.class: src/bplus/nodes/BPlusLeafNode.java
		$(JC) $(JFLAGS) src/bplus/nodes/BPlusLeafNode.java
bin/bplus/nodes/BPlusNode.class: src/bplus/nodes/BPlusNode.java
		$(JC) $(JFLAGS) src/bplus/nodes/BPlusNode.java
bin/bplus/NodeHandler.class: src/bplus/NodeHandler.java
		$(JC) $(JFLAGS) src/bplus/NodeHandler.java
bin/bplus/BPlusTreeFacade.class: src/bplus/BPlusTreeFacade.java
		$(JC) $(JFLAGS) src/bplus/BPlusTreeFacade.java
bin/bplus/keys/BPlusNodeKey.class: src/bplus/keys/BPlusNodeKey.java
		$(JC) $(JFLAGS) src/bplus/keys/BPlusNodeKey.java
bin/bplus/keys/BPlusElementKey.class: src/bplus/keys/BPlusElementKey.java
		$(JC) $(JFLAGS) src/bplus/keys/BPlusElementKey.java
bin/bplus/MockBPlusTreeFacade.class: src/bplus/MockBPlusTreeFacade.java
		$(JC) $(JFLAGS) src/bplus/MockBPlusTreeFacade.java
bin/utils/statistics/StatisticsGeneratorSingleton.class: src/utils/statistics/StatisticsGeneratorSingleton.java
		$(JC) $(JFLAGS) src/utils/statistics/StatisticsGeneratorSingleton.java
bin/utils/statistics/StatisticsGenerator.class: src/utils/statistics/StatisticsGenerator.java
		$(JC) $(JFLAGS) src/utils/statistics/StatisticsGenerator.java
bin/utils/statistics/Statistics.class: src/utils/statistics/Statistics.java
		$(JC) $(JFLAGS) src/utils/statistics/Statistics.java
bin/utils/Constants.class: src/utils/Constants.java
		$(JC) $(JFLAGS) src/utils/Constants.java
bin/SearchEngine.class: src/SearchEngine.java
		$(JC) $(JFLAGS) src/SearchEngine.java
bin/DocumentsIndexer.class: src/DocumentsIndexer.java
		$(JC) $(JFLAGS) src/DocumentsIndexer.java
bin/test/processor/TestStemmerProcessor.class: src/test/processor/TestStemmerProcessor.java
		$(JC) $(JFLAGS) src/test/processor/TestStemmerProcessor.java
bin/test/files/StackFileTest.class: src/test/files/StackFileTest.java
		$(JC) $(JFLAGS) src/test/files/StackFileTest.java
bin/test/files/SecuentialFileTest.class: src/test/files/SecuentialFileTest.java
		$(JC) $(JFLAGS) src/test/files/SecuentialFileTest.java
bin/test/files/RelativelFileTest.class: src/test/files/RelativelFileTest.java
		$(JC) $(JFLAGS) src/test/files/RelativelFileTest.java
bin/test/files/FileTest.class: src/test/files/FileTest.java
		$(JC) $(JFLAGS) src/test/files/FileTest.java
bin/test/files/test.class: src/test/files/test.java
		$(JC) $(JFLAGS) src/test/files/test.java
bin/test/index/TestMockDocumentsDictionary.class: src/test/index/TestMockDocumentsDictionary.java
		$(JC) $(JFLAGS) src/test/index/TestMockDocumentsDictionary.java
bin/test/index/TestMockIndex.class: src/test/index/TestMockIndex.java
		$(JC) $(JFLAGS) src/test/index/TestMockIndex.java
bin/test/index/TestDocumentsDictionary.class: src/test/index/TestDocumentsDictionary.java
		$(JC) $(JFLAGS) src/test/index/TestDocumentsDictionary.java
bin/test/index/TestDefaultQueryEngine.class: src/test/index/TestDefaultQueryEngine.java
		$(JC) $(JFLAGS) src/test/index/TestDefaultQueryEngine.java
bin/test/index/TestQueryEngineMocks.class: src/test/index/TestQueryEngineMocks.java
		$(JC) $(JFLAGS) src/test/index/TestQueryEngineMocks.java
bin/test/index/TestDocumentsDictionaryImp.class: src/test/index/TestDocumentsDictionaryImp.java
		$(JC) $(JFLAGS) src/test/index/TestDocumentsDictionaryImp.java
bin/test/index/TestIndexImp.class: src/test/index/TestIndexImp.java
		$(JC) $(JFLAGS) src/test/index/TestIndexImp.java
bin/test/index/TestQueryEngine.class: src/test/index/TestQueryEngine.java
		$(JC) $(JFLAGS) src/test/index/TestQueryEngine.java
bin/test/index/TestIndex.class: src/test/index/TestIndex.java
		$(JC) $(JFLAGS) src/test/index/TestIndex.java
bin/test/bplus/TestBPlusTreeBoImp.class: src/test/bplus/TestBPlusTreeBoImp.java
		$(JC) $(JFLAGS) src/test/bplus/TestBPlusTreeBoImp.java
bin/test/bplus/TestBPlusNodeDao.class: src/test/bplus/TestBPlusNodeDao.java
		$(JC) $(JFLAGS) src/test/bplus/TestBPlusNodeDao.java
bin/test/bplus/BPlusTreeBoDaoTest.class: src/test/bplus/BPlusTreeBoDaoTest.java
		$(JC) $(JFLAGS) src/test/bplus/BPlusTreeBoDaoTest.java
bin/test/bplus/TestBPlusTreeBoImpDaoTest.class: src/test/bplus/TestBPlusTreeBoImpDaoTest.java
		$(JC) $(JFLAGS) src/test/bplus/TestBPlusTreeBoImpDaoTest.java
bin/test/bplus/TestBPlusNodeDaoTest.class: src/test/bplus/TestBPlusNodeDaoTest.java
		$(JC) $(JFLAGS) src/test/bplus/TestBPlusNodeDaoTest.java
bin/test/bplus/TestBPlusNodeDaoImp.class: src/test/bplus/TestBPlusNodeDaoImp.java
		$(JC) $(JFLAGS) src/test/bplus/TestBPlusNodeDaoImp.java
bin/test/bplus/BPlusNodeTestUtils.class: src/test/bplus/BPlusNodeTestUtils.java
		$(JC) $(JFLAGS) src/test/bplus/BPlusNodeTestUtils.java
bin/test/bplus/TestBPlusTreeBoTest.class: src/test/bplus/TestBPlusTreeBoTest.java
		$(JC) $(JFLAGS) src/test/bplus/TestBPlusTreeBoTest.java
bin/test/bplus/MapTest.class: src/test/bplus/MapTest.java
		$(JC) $(JFLAGS) src/test/bplus/MapTest.java
bin/test/bplus/TestBPlusTreeBo.class: src/test/bplus/TestBPlusTreeBo.java
		$(JC) $(JFLAGS) src/test/bplus/TestBPlusTreeBo.java
bin/test/persistors/TestBPlusNodePersistor.class: src/test/persistors/TestBPlusNodePersistor.java
		$(JC) $(JFLAGS) src/test/persistors/TestBPlusNodePersistor.java
bin/test/persistors/TestPersistor.class: src/test/persistors/TestPersistor.java
		$(JC) $(JFLAGS) src/test/persistors/TestPersistor.java
bin/test/persistors/TestIntegerPersistor.class: src/test/persistors/TestIntegerPersistor.java
		$(JC) $(JFLAGS) src/test/persistors/TestIntegerPersistor.java
bin/test/persistors/TestStringPersistor.class: src/test/persistors/TestStringPersistor.java
		$(JC) $(JFLAGS) src/test/persistors/TestStringPersistor.java
bin/test/persistors/TestBytePersistor.class: src/test/persistors/TestBytePersistor.java
		$(JC) $(JFLAGS) src/test/persistors/TestBytePersistor.java
bin/test/utils/KeyCodificationTest.class: src/test/utils/KeyCodificationTest.java
		$(JC) $(JFLAGS) src/test/utils/KeyCodificationTest.java
bin/ControllerServlet.class: src/ControllerServlet.java
		$(JC) $(JFLAGS) src/ControllerServlet.java
bin/linkedblocks/VariableLinkedBlocksManager.class: src/linkedblocks/VariableLinkedBlocksManager.java
		$(JC) $(JFLAGS) src/linkedblocks/VariableLinkedBlocksManager.java
bin/linkedblocks/LinkedBlocksManager.class: src/linkedblocks/LinkedBlocksManager.java
		$(JC) $(JFLAGS) src/linkedblocks/LinkedBlocksManager.java
bin/linkedblocks/codification/GammaDistancesBlock.class: src/linkedblocks/codification/GammaDistancesBlock.java
		$(JC) $(JFLAGS) src/linkedblocks/codification/GammaDistancesBlock.java
bin/linkedblocks/utils/KeyCodificationUtils.class: src/linkedblocks/utils/KeyCodificationUtils.java
		$(JC) $(JFLAGS) src/linkedblocks/utils/KeyCodificationUtils.java
bin/linkedblocks/keys/DocumentIndexKey.class: src/linkedblocks/keys/DocumentIndexKey.java
		$(JC) $(JFLAGS) src/linkedblocks/keys/DocumentIndexKey.java
bin/TreeDumper.class: src/TreeDumper.java
		$(JC) $(JFLAGS) src/TreeDumper.java


