CLASSPATHS=src:WEB-INF/lib/htmlparser.jar:WEB-INF/lib/servlet-api.jar:WEB-INF/lib/junit-4.5.jar:WEB-INF/lib/log4j-1.2.15.jar

JFLAGS = -g -classpath $(CLASSPATHS) -source 6.0 -target 1.6
JC = javac


CLASSES = ./src/app/dao/bplus/BPlusNodeDaoTest.java ./src/app/dao/bplus/BPlusNodeDaoImp.java ./src/app/dao/documents/NullDocumentsDictionary.java ./src/app/dao/documents/DocumentsDictionaryImp.java ./src/app/bo/WordCollectorIndex.java ./src/app/bo/bplus/AbstractBPlusTreeBo.java ./src/app/bo/bplus/BPlusTreeBoImp.java ./src/app/bo/bplus/BPlusTreeBoTest.java ./src/app/bo/MockDocumentsDictionary.java ./src/app/bo/MockIndex.java ./src/app/bo/IndexImp.java ./src/app/po/files/StackFile.java ./src/app/po/files/SecuencialFile.java ./src/app/po/files/AbstractBloquedFile.java ./src/app/po/files/AbstractFile.java ./src/app/po/files/StreamFile.java ./src/app/po/files/BufferedRelativeFile.java ./src/app/po/files/RelativeFile.java ./src/app/po/files/SecuentialFile.java ./src/app/po/persistors/IntegerPersistor.java ./src/app/po/persistors/SimpleStringPersistor.java ./src/app/po/persistors/DocumentInfoPersistor.java ./src/app/po/persistors/LinkedBlockPersistor.java ./src/app/po/persistors/AbstractPersistor.java ./src/app/po/persistors/SignatureFilePersistor.java ./src/app/po/persistors/BytePersistor.java ./src/app/po/persistors/MaxSizeAbstractPersistor.java ./src/app/po/persistors/DocumentDataPersistor.java ./src/app/po/persistors/LongPersistor.java ./src/app/po/persistors/StringPersistor.java ./src/app/po/persistors/BPlusNodePersistor.java ./src/app/po/persistors/BPlusElementPersistor.java ./src/app/po/persistors/GammaDistancesBlockPersistor.java ./src/app/po/persistors/VariableStringPersistor.java ./src/app/query/parser/CompositeQueryParser.java ./src/app/query/parser/ParentesisParser.java ./src/app/query/parser/TrimParser.java ./src/app/query/parser/exception/ParserException.java ./src/app/query/parser/exception/CantDigestException.java ./src/app/query/parser/exception/ParserGenericException.java ./src/app/query/parser/QueryAndParser.java ./src/app/query/parser/QueryNotParser.java ./src/app/query/parser/CompositeParser.java ./src/app/query/parser/QueryParser.java ./src/app/query/parser/RecursiveParser.java ./src/app/query/parser/QueryOrParser.java ./src/app/query/parser/QueryWordParser.java ./src/app/query/tree/QueryOr.java ./src/app/query/tree/QueryNot.java ./src/app/query/tree/CompositeQuery.java ./src/app/query/tree/QueryAnd.java ./src/app/query/QueryWord.java ./src/web/Model.java ./src/web/search/SearchView.java ./src/web/search/SearchModel.java ./src/web/indexer/IndexerStatsView.java ./src/web/indexer/IndexerModel.java ./src/web/indexer/IndexerView.java ./src/web/View.java ./src/api/QueryEngine.java ./src/api/WordCollectorQueryEngine.java ./src/api/SignatureFileQueryEngine.java ./src/api/dao/documents/DocumentsDictionary.java ./src/api/dao/BPlusTree/BPlusNodeDao.java ./src/api/bo/BPlusTree/BPlusTreeBo.java ./src/api/bo/BPlusTree/BPlusNodeBo.java ./src/api/po/files/Stack.java ./src/api/po/files/File.java ./src/api/po/persistors/SimplePersistor.java ./src/api/po/persistors/Persistor.java ./src/api/po/persistors/DistancesBlock.java ./src/api/po/persistors/SizeUtils.java ./src/api/DocumentInsert.java ./src/api/IQueryEngine.java ./src/api/DocumentsIndexer.java ./src/api/ObjectFactory.java ./src/api/DefaultQueryEngine.java ./src/api/MockQueryEngine.java ./src/api/AbstractQueryEngine.java ./src/api/Index.java ./src/api/query/parser/Parser.java ./src/api/query/tree/Query.java ./src/dto/SignatureFileDto.java ./src/dto/LinkedBlock.java ./src/dto/SuffixDto.java ./src/dto/DocumentsReportDto.java ./src/dto/StopwordsPipelineDto.java ./src/dto/DocumentStatisticsDto.java ./src/dto/WordDto.java ./src/dto/DocumentDto.java ./src/processor/stopwords/StopwordsProcessor.java ./src/processor/stemming/StemmingProcessor.java ./src/processor/utils/HtmlUtils.java ./src/processor/utils/DigesterUtils.java ./src/processor/IndexedDocumentChecker.java ./src/exceptions/BusinessException.java ./src/exceptions/PersistanceException.java ./src/exceptions/PipelineOverflowException.java ./src/exceptions/DataAccessException.java ./src/search.java ./src/bplus/exceptions/BPlusNodeException.java ./src/bplus/exceptions/NodeOverflowException.java ./src/bplus/exceptions/KeyNotFoundException.java ./src/bplus/exceptions/NodeNotFoundException.java ./src/bplus/exceptions/BPlusException.java ./src/bplus/elements/BPlusAbstractElement.java ./src/bplus/elements/BPlusLeafElement.java ./src/bplus/elements/BPlusElement.java ./src/bplus/elements/BPlusIndexElement.java ./src/bplus/nodes/BPlusIndexNode.java ./src/bplus/nodes/AbstractBPlusNode.java ./src/bplus/nodes/BPlusLeafNode.java ./src/bplus/nodes/BPlusNode.java ./src/bplus/NodeHandler.java ./src/bplus/BPlusTreeFacade.java ./src/bplus/keys/BPlusNodeKey.java ./src/bplus/keys/BPlusElementKey.java ./src/bplus/MockBPlusTreeFacade.java ./src/Servlet.java ./src/utils/statistics/StatisticsGenerator.java ./src/utils/statistics/Statistics.java ./src/utils/Constants.java ./src/SearchEngine.java ./src/Main.java ./src/index.java ./src/test/processor/TestStemmerProcessor.java ./src/test/files/StackFileTest.java ./src/test/files/SecuentialFileTest.java ./src/test/files/RelativelFileTest.java ./src/test/files/FileTest.java ./src/test/files/test.java ./src/test/files/BufferedRelativeFileTest.java ./src/test/index/TestMockDocumentsDictionary.java ./src/test/index/TestMockIndex.java ./src/test/index/TestLinkedBlocksManager.java ./src/test/index/TestDocumentsDictionary.java ./src/test/index/TestDefaultQueryEngine.java ./src/test/index/TestQueryEngineMocks.java ./src/test/index/TestDocumentsDictionaryImp.java ./src/test/index/TestIndexImp.java ./src/test/index/TestQueryEngine.java ./src/test/index/TestIndex.java ./src/test/bplus/TestBPlusTreeBoImp.java ./src/test/bplus/TestBPlusNodeDao.java ./src/test/bplus/BPlusTreeBoDaoTest.java ./src/test/bplus/TestBPlusTreeBoImpDaoTest.java ./src/test/bplus/TestBPlusNodeDaoTest.java ./src/test/bplus/TestBPlusNodeDaoImp.java ./src/test/bplus/BPlusNodeTestUtils.java ./src/test/bplus/TestBPlusTreeBoTest.java ./src/test/bplus/MapTest.java ./src/test/bplus/TestBPlusTreeBo.java ./src/test/persistors/TestBPlusNodePersistor.java ./src/test/persistors/TestPersistor.java ./src/test/persistors/TestIntegerPersistor.java ./src/test/persistors/TestStringPersistor.java ./src/test/persistors/TestBytePersistor.java ./src/test/utils/KeyCodificationTest.java ./src/test/utils/GammaDistancesBlockTest.java ./src/test/query/QueryTestCase.java ./src/test/query/QueryNotTest.java ./src/test/query/CompositeQueryTest.java ./src/test/query/ParserTest.java ./src/test/query/QueryAndTest.java ./src/test/query/MockQuery.java ./src/test/query/QueryOrTest.java ./src/ControllerServlet.java ./src/linkedblocks/LinkedBlocksManager.java ./src/linkedblocks/codification/GammaDistancesBlock.java ./src/linkedblocks/utils/KeyCodificationUtils.java ./src/linkedblocks/keys/DocumentIndexKey.java ./src/signaturefiles/hash/JSHash.java ./src/signaturefiles/hash/PJWHash.java ./src/signaturefiles/hash/BPHash.java ./src/signaturefiles/hash/Hash.java ./src/signaturefiles/hash/DEKHash.java ./src/signaturefiles/hash/SDBMHash.java ./src/signaturefiles/hash/ELFHash.java ./src/signaturefiles/hash/DJBHash.java ./src/signaturefiles/hash/RSHash.java ./src/signaturefiles/hash/FNVHash.java ./src/signaturefiles/hash/APHash.java ./src/signaturefiles/hash/BKDRHash.java ./src/signaturefiles/utils/SignatureUtils.java ./src/signaturefiles/SignatureGenerator.java ./src/TreeDumper.java

default: classes jar
classes: ./src/app/dao/bplus/BPlusNodeDaoTest.class ./src/app/dao/bplus/BPlusNodeDaoImp.class ./src/app/dao/documents/NullDocumentsDictionary.class ./src/app/dao/documents/DocumentsDictionaryImp.class ./src/app/bo/WordCollectorIndex.class ./src/app/bo/bplus/AbstractBPlusTreeBo.class ./src/app/bo/bplus/BPlusTreeBoImp.class ./src/app/bo/bplus/BPlusTreeBoTest.class ./src/app/bo/MockDocumentsDictionary.class ./src/app/bo/MockIndex.class ./src/app/bo/IndexImp.class ./src/app/po/files/StackFile.class ./src/app/po/files/SecuencialFile.class ./src/app/po/files/AbstractBloquedFile.class ./src/app/po/files/AbstractFile.class ./src/app/po/files/StreamFile.class ./src/app/po/files/BufferedRelativeFile.class ./src/app/po/files/RelativeFile.class ./src/app/po/files/SecuentialFile.class ./src/app/po/persistors/IntegerPersistor.class ./src/app/po/persistors/SimpleStringPersistor.class ./src/app/po/persistors/DocumentInfoPersistor.class ./src/app/po/persistors/LinkedBlockPersistor.class ./src/app/po/persistors/AbstractPersistor.class ./src/app/po/persistors/SignatureFilePersistor.class ./src/app/po/persistors/BytePersistor.class ./src/app/po/persistors/MaxSizeAbstractPersistor.class ./src/app/po/persistors/DocumentDataPersistor.class ./src/app/po/persistors/LongPersistor.class ./src/app/po/persistors/StringPersistor.class ./src/app/po/persistors/BPlusNodePersistor.class ./src/app/po/persistors/BPlusElementPersistor.class ./src/app/po/persistors/GammaDistancesBlockPersistor.class ./src/app/po/persistors/VariableStringPersistor.class ./src/app/query/parser/CompositeQueryParser.class ./src/app/query/parser/ParentesisParser.class ./src/app/query/parser/TrimParser.class ./src/app/query/parser/exception/ParserException.class ./src/app/query/parser/exception/CantDigestException.class ./src/app/query/parser/exception/ParserGenericException.class ./src/app/query/parser/QueryAndParser.class ./src/app/query/parser/QueryNotParser.class ./src/app/query/parser/CompositeParser.class ./src/app/query/parser/QueryParser.class ./src/app/query/parser/RecursiveParser.class ./src/app/query/parser/QueryOrParser.class ./src/app/query/parser/QueryWordParser.class ./src/app/query/tree/QueryOr.class ./src/app/query/tree/QueryNot.class ./src/app/query/tree/CompositeQuery.class ./src/app/query/tree/QueryAnd.class ./src/app/query/QueryWord.class ./src/web/Model.class ./src/web/search/SearchView.class ./src/web/search/SearchModel.class ./src/web/indexer/IndexerStatsView.class ./src/web/indexer/IndexerModel.class ./src/web/indexer/IndexerView.class ./src/web/View.class ./src/api/QueryEngine.class ./src/api/WordCollectorQueryEngine.class ./src/api/SignatureFileQueryEngine.class ./src/api/dao/documents/DocumentsDictionary.class ./src/api/dao/BPlusTree/BPlusNodeDao.class ./src/api/bo/BPlusTree/BPlusTreeBo.class ./src/api/bo/BPlusTree/BPlusNodeBo.class ./src/api/po/files/Stack.class ./src/api/po/files/File.class ./src/api/po/persistors/SimplePersistor.class ./src/api/po/persistors/Persistor.class ./src/api/po/persistors/DistancesBlock.class ./src/api/po/persistors/SizeUtils.class ./src/api/DocumentInsert.class ./src/api/IQueryEngine.class ./src/api/DocumentsIndexer.class ./src/api/ObjectFactory.class ./src/api/DefaultQueryEngine.class ./src/api/MockQueryEngine.class ./src/api/AbstractQueryEngine.class ./src/api/Index.class ./src/api/query/parser/Parser.class ./src/api/query/tree/Query.class ./src/dto/SignatureFileDto.class ./src/dto/LinkedBlock.class ./src/dto/SuffixDto.class ./src/dto/DocumentsReportDto.class ./src/dto/StopwordsPipelineDto.class ./src/dto/DocumentStatisticsDto.class ./src/dto/WordDto.class ./src/dto/DocumentDto.class ./src/processor/stopwords/StopwordsProcessor.class ./src/processor/stemming/StemmingProcessor.class ./src/processor/utils/HtmlUtils.class ./src/processor/utils/DigesterUtils.class ./src/processor/IndexedDocumentChecker.class ./src/exceptions/BusinessException.class ./src/exceptions/PersistanceException.class ./src/exceptions/PipelineOverflowException.class ./src/exceptions/DataAccessException.class ./src/search.class ./src/bplus/exceptions/BPlusNodeException.class ./src/bplus/exceptions/NodeOverflowException.class ./src/bplus/exceptions/KeyNotFoundException.class ./src/bplus/exceptions/NodeNotFoundException.class ./src/bplus/exceptions/BPlusException.class ./src/bplus/elements/BPlusAbstractElement.class ./src/bplus/elements/BPlusLeafElement.class ./src/bplus/elements/BPlusElement.class ./src/bplus/elements/BPlusIndexElement.class ./src/bplus/nodes/BPlusIndexNode.class ./src/bplus/nodes/AbstractBPlusNode.class ./src/bplus/nodes/BPlusLeafNode.class ./src/bplus/nodes/BPlusNode.class ./src/bplus/NodeHandler.class ./src/bplus/BPlusTreeFacade.class ./src/bplus/keys/BPlusNodeKey.class ./src/bplus/keys/BPlusElementKey.class ./src/bplus/MockBPlusTreeFacade.class ./src/Servlet.class ./src/utils/statistics/StatisticsGenerator.class ./src/utils/statistics/Statistics.class ./src/utils/Constants.class ./src/SearchEngine.class ./src/Main.class ./src/index.class ./src/test/processor/TestStemmerProcessor.class ./src/test/files/StackFileTest.class ./src/test/files/SecuentialFileTest.class ./src/test/files/RelativelFileTest.class ./src/test/files/FileTest.class ./src/test/files/test.class ./src/test/files/BufferedRelativeFileTest.class ./src/test/index/TestMockDocumentsDictionary.class ./src/test/index/TestMockIndex.class ./src/test/index/TestLinkedBlocksManager.class ./src/test/index/TestDocumentsDictionary.class ./src/test/index/TestDefaultQueryEngine.class ./src/test/index/TestQueryEngineMocks.class ./src/test/index/TestDocumentsDictionaryImp.class ./src/test/index/TestIndexImp.class ./src/test/index/TestQueryEngine.class ./src/test/index/TestIndex.class ./src/test/bplus/TestBPlusTreeBoImp.class ./src/test/bplus/TestBPlusNodeDao.class ./src/test/bplus/BPlusTreeBoDaoTest.class ./src/test/bplus/TestBPlusTreeBoImpDaoTest.class ./src/test/bplus/TestBPlusNodeDaoTest.class ./src/test/bplus/TestBPlusNodeDaoImp.class ./src/test/bplus/BPlusNodeTestUtils.class ./src/test/bplus/TestBPlusTreeBoTest.class ./src/test/bplus/MapTest.class ./src/test/bplus/TestBPlusTreeBo.class ./src/test/persistors/TestBPlusNodePersistor.class ./src/test/persistors/TestPersistor.class ./src/test/persistors/TestIntegerPersistor.class ./src/test/persistors/TestStringPersistor.class ./src/test/persistors/TestBytePersistor.class ./src/test/utils/KeyCodificationTest.class ./src/test/utils/GammaDistancesBlockTest.class ./src/test/query/QueryTestCase.class ./src/test/query/QueryNotTest.class ./src/test/query/CompositeQueryTest.class ./src/test/query/ParserTest.class ./src/test/query/QueryAndTest.class ./src/test/query/MockQuery.class ./src/test/query/QueryOrTest.class ./src/ControllerServlet.class ./src/linkedblocks/LinkedBlocksManager.class ./src/linkedblocks/codification/GammaDistancesBlock.class ./src/linkedblocks/utils/KeyCodificationUtils.class ./src/linkedblocks/keys/DocumentIndexKey.class ./src/signaturefiles/hash/JSHash.class ./src/signaturefiles/hash/PJWHash.class ./src/signaturefiles/hash/BPHash.class ./src/signaturefiles/hash/Hash.class ./src/signaturefiles/hash/DEKHash.class ./src/signaturefiles/hash/SDBMHash.class ./src/signaturefiles/hash/ELFHash.class ./src/signaturefiles/hash/DJBHash.class ./src/signaturefiles/hash/RSHash.class ./src/signaturefiles/hash/FNVHash.class ./src/signaturefiles/hash/APHash.class ./src/signaturefiles/hash/BKDRHash.class ./src/signaturefiles/utils/SignatureUtils.class ./src/signaturefiles/SignatureGenerator.class ./src/TreeDumper.class
clean:
	   rm $(CLASSES:.java=.class)
jar:
	cd src && jar cfm ../bombita.jar ../manifesto.txt log4j.xml *
dist:
	tar -c ./src/app/dao/bplus/BPlusNodeDaoTest.java ./src/app/dao/bplus/BPlusNodeDaoImp.java ./src/app/dao/documents/NullDocumentsDictionary.java ./src/app/dao/documents/DocumentsDictionaryImp.java ./src/app/bo/WordCollectorIndex.java ./src/app/bo/bplus/AbstractBPlusTreeBo.java ./src/app/bo/bplus/BPlusTreeBoImp.java ./src/app/bo/bplus/BPlusTreeBoTest.java ./src/app/bo/MockDocumentsDictionary.java ./src/app/bo/MockIndex.java ./src/app/bo/IndexImp.java ./src/app/po/files/StackFile.java ./src/app/po/files/SecuencialFile.java ./src/app/po/files/AbstractBloquedFile.java ./src/app/po/files/AbstractFile.java ./src/app/po/files/StreamFile.java ./src/app/po/files/BufferedRelativeFile.java ./src/app/po/files/RelativeFile.java ./src/app/po/files/SecuentialFile.java ./src/app/po/persistors/IntegerPersistor.java ./src/app/po/persistors/SimpleStringPersistor.java ./src/app/po/persistors/DocumentInfoPersistor.java ./src/app/po/persistors/LinkedBlockPersistor.java ./src/app/po/persistors/AbstractPersistor.java ./src/app/po/persistors/SignatureFilePersistor.java ./src/app/po/persistors/BytePersistor.java ./src/app/po/persistors/MaxSizeAbstractPersistor.java ./src/app/po/persistors/DocumentDataPersistor.java ./src/app/po/persistors/LongPersistor.java ./src/app/po/persistors/StringPersistor.java ./src/app/po/persistors/BPlusNodePersistor.java ./src/app/po/persistors/BPlusElementPersistor.java ./src/app/po/persistors/GammaDistancesBlockPersistor.java ./src/app/po/persistors/VariableStringPersistor.java ./src/app/query/parser/CompositeQueryParser.java ./src/app/query/parser/ParentesisParser.java ./src/app/query/parser/TrimParser.java ./src/app/query/parser/exception/ParserException.java ./src/app/query/parser/exception/CantDigestException.java ./src/app/query/parser/exception/ParserGenericException.java ./src/app/query/parser/QueryAndParser.java ./src/app/query/parser/QueryNotParser.java ./src/app/query/parser/CompositeParser.java ./src/app/query/parser/QueryParser.java ./src/app/query/parser/RecursiveParser.java ./src/app/query/parser/QueryOrParser.java ./src/app/query/parser/QueryWordParser.java ./src/app/query/tree/QueryOr.java ./src/app/query/tree/QueryNot.java ./src/app/query/tree/CompositeQuery.java ./src/app/query/tree/QueryAnd.java ./src/app/query/QueryWord.java ./src/web/Model.java ./src/web/search/SearchView.java ./src/web/search/SearchModel.java ./src/web/indexer/IndexerStatsView.java ./src/web/indexer/IndexerModel.java ./src/web/indexer/IndexerView.java ./src/web/View.java ./src/api/QueryEngine.java ./src/api/WordCollectorQueryEngine.java ./src/api/SignatureFileQueryEngine.java ./src/api/dao/documents/DocumentsDictionary.java ./src/api/dao/BPlusTree/BPlusNodeDao.java ./src/api/bo/BPlusTree/BPlusTreeBo.java ./src/api/bo/BPlusTree/BPlusNodeBo.java ./src/api/po/files/Stack.java ./src/api/po/files/File.java ./src/api/po/persistors/SimplePersistor.java ./src/api/po/persistors/Persistor.java ./src/api/po/persistors/DistancesBlock.java ./src/api/po/persistors/SizeUtils.java ./src/api/DocumentInsert.java ./src/api/IQueryEngine.java ./src/api/DocumentsIndexer.java ./src/api/ObjectFactory.java ./src/api/DefaultQueryEngine.java ./src/api/MockQueryEngine.java ./src/api/AbstractQueryEngine.java ./src/api/Index.java ./src/api/query/parser/Parser.java ./src/api/query/tree/Query.java ./src/dto/SignatureFileDto.java ./src/dto/LinkedBlock.java ./src/dto/SuffixDto.java ./src/dto/DocumentsReportDto.java ./src/dto/StopwordsPipelineDto.java ./src/dto/DocumentStatisticsDto.java ./src/dto/WordDto.java ./src/dto/DocumentDto.java ./src/processor/stopwords/StopwordsProcessor.java ./src/processor/stemming/StemmingProcessor.java ./src/processor/utils/HtmlUtils.java ./src/processor/utils/DigesterUtils.java ./src/processor/IndexedDocumentChecker.java ./src/exceptions/BusinessException.java ./src/exceptions/PersistanceException.java ./src/exceptions/PipelineOverflowException.java ./src/exceptions/DataAccessException.java ./src/search.java ./src/bplus/exceptions/BPlusNodeException.java ./src/bplus/exceptions/NodeOverflowException.java ./src/bplus/exceptions/KeyNotFoundException.java ./src/bplus/exceptions/NodeNotFoundException.java ./src/bplus/exceptions/BPlusException.java ./src/bplus/elements/BPlusAbstractElement.java ./src/bplus/elements/BPlusLeafElement.java ./src/bplus/elements/BPlusElement.java ./src/bplus/elements/BPlusIndexElement.java ./src/bplus/nodes/BPlusIndexNode.java ./src/bplus/nodes/AbstractBPlusNode.java ./src/bplus/nodes/BPlusLeafNode.java ./src/bplus/nodes/BPlusNode.java ./src/bplus/NodeHandler.java ./src/bplus/BPlusTreeFacade.java ./src/bplus/keys/BPlusNodeKey.java ./src/bplus/keys/BPlusElementKey.java ./src/bplus/MockBPlusTreeFacade.java ./src/Servlet.java ./src/utils/statistics/StatisticsGenerator.java ./src/utils/statistics/Statistics.java ./src/utils/Constants.java ./src/SearchEngine.java ./src/Main.java ./src/index.java ./src/test/processor/TestStemmerProcessor.java ./src/test/files/StackFileTest.java ./src/test/files/SecuentialFileTest.java ./src/test/files/RelativelFileTest.java ./src/test/files/FileTest.java ./src/test/files/test.java ./src/test/files/BufferedRelativeFileTest.java ./src/test/index/TestMockDocumentsDictionary.java ./src/test/index/TestMockIndex.java ./src/test/index/TestLinkedBlocksManager.java ./src/test/index/TestDocumentsDictionary.java ./src/test/index/TestDefaultQueryEngine.java ./src/test/index/TestQueryEngineMocks.java ./src/test/index/TestDocumentsDictionaryImp.java ./src/test/index/TestIndexImp.java ./src/test/index/TestQueryEngine.java ./src/test/index/TestIndex.java ./src/test/bplus/TestBPlusTreeBoImp.java ./src/test/bplus/TestBPlusNodeDao.java ./src/test/bplus/BPlusTreeBoDaoTest.java ./src/test/bplus/TestBPlusTreeBoImpDaoTest.java ./src/test/bplus/TestBPlusNodeDaoTest.java ./src/test/bplus/TestBPlusNodeDaoImp.java ./src/test/bplus/BPlusNodeTestUtils.java ./src/test/bplus/TestBPlusTreeBoTest.java ./src/test/bplus/MapTest.java ./src/test/bplus/TestBPlusTreeBo.java ./src/test/persistors/TestBPlusNodePersistor.java ./src/test/persistors/TestPersistor.java ./src/test/persistors/TestIntegerPersistor.java ./src/test/persistors/TestStringPersistor.java ./src/test/persistors/TestBytePersistor.java ./src/test/utils/KeyCodificationTest.java ./src/test/utils/GammaDistancesBlockTest.java ./src/test/query/QueryTestCase.java ./src/test/query/QueryNotTest.java ./src/test/query/CompositeQueryTest.java ./src/test/query/ParserTest.java ./src/test/query/QueryAndTest.java ./src/test/query/MockQuery.java ./src/test/query/QueryOrTest.java ./src/ControllerServlet.java ./src/linkedblocks/LinkedBlocksManager.java ./src/linkedblocks/codification/GammaDistancesBlock.java ./src/linkedblocks/utils/KeyCodificationUtils.java ./src/linkedblocks/keys/DocumentIndexKey.java ./src/signaturefiles/hash/JSHash.java ./src/signaturefiles/hash/PJWHash.java ./src/signaturefiles/hash/BPHash.java ./src/signaturefiles/hash/Hash.java ./src/signaturefiles/hash/DEKHash.java ./src/signaturefiles/hash/SDBMHash.java ./src/signaturefiles/hash/ELFHash.java ./src/signaturefiles/hash/DJBHash.java ./src/signaturefiles/hash/RSHash.java ./src/signaturefiles/hash/FNVHash.java ./src/signaturefiles/hash/APHash.java ./src/signaturefiles/hash/BKDRHash.java ./src/signaturefiles/utils/SignatureUtils.java ./src/signaturefiles/SignatureGenerator.java ./src/TreeDumper.java leemeporfavor.txt manifesto.txt src/log4j.xml words/stemming.txt words/stopwords.txt makefile WEB-INF/lib/junit-4.5.jar WEB-INF/lib/log4j-1.2.15.jar WEB-INF/lib/servlet-api.jar WEB-INF/lib/htmlparser.jar > bombita-src.tar 
	gzip --force bombita-src.tar 
	@echo "*************************************************"
	@echo "* 	bombita-src.tar.gz generated	       *"
	@echo "*************************************************" 

src/app/dao/bplus/BPlusNodeDaoTest.class: src/app/dao/bplus/BPlusNodeDaoTest.java
		$(JC) $(JFLAGS) src/app/dao/bplus/BPlusNodeDaoTest.java
src/app/dao/bplus/BPlusNodeDaoImp.class: src/app/dao/bplus/BPlusNodeDaoImp.java
		$(JC) $(JFLAGS) src/app/dao/bplus/BPlusNodeDaoImp.java
src/app/dao/documents/NullDocumentsDictionary.class: src/app/dao/documents/NullDocumentsDictionary.java
		$(JC) $(JFLAGS) src/app/dao/documents/NullDocumentsDictionary.java
src/app/dao/documents/DocumentsDictionaryImp.class: src/app/dao/documents/DocumentsDictionaryImp.java
		$(JC) $(JFLAGS) src/app/dao/documents/DocumentsDictionaryImp.java
src/app/bo/WordCollectorIndex.class: src/app/bo/WordCollectorIndex.java
		$(JC) $(JFLAGS) src/app/bo/WordCollectorIndex.java
src/app/bo/bplus/AbstractBPlusTreeBo.class: src/app/bo/bplus/AbstractBPlusTreeBo.java
		$(JC) $(JFLAGS) src/app/bo/bplus/AbstractBPlusTreeBo.java
src/app/bo/bplus/BPlusTreeBoImp.class: src/app/bo/bplus/BPlusTreeBoImp.java
		$(JC) $(JFLAGS) src/app/bo/bplus/BPlusTreeBoImp.java
src/app/bo/bplus/BPlusTreeBoTest.class: src/app/bo/bplus/BPlusTreeBoTest.java
		$(JC) $(JFLAGS) src/app/bo/bplus/BPlusTreeBoTest.java
src/app/bo/MockDocumentsDictionary.class: src/app/bo/MockDocumentsDictionary.java
		$(JC) $(JFLAGS) src/app/bo/MockDocumentsDictionary.java
src/app/bo/MockIndex.class: src/app/bo/MockIndex.java
		$(JC) $(JFLAGS) src/app/bo/MockIndex.java
src/app/bo/IndexImp.class: src/app/bo/IndexImp.java
		$(JC) $(JFLAGS) src/app/bo/IndexImp.java
src/app/po/files/StackFile.class: src/app/po/files/StackFile.java
		$(JC) $(JFLAGS) src/app/po/files/StackFile.java
src/app/po/files/SecuencialFile.class: src/app/po/files/SecuencialFile.java
		$(JC) $(JFLAGS) src/app/po/files/SecuencialFile.java
src/app/po/files/AbstractBloquedFile.class: src/app/po/files/AbstractBloquedFile.java
		$(JC) $(JFLAGS) src/app/po/files/AbstractBloquedFile.java
src/app/po/files/AbstractFile.class: src/app/po/files/AbstractFile.java
		$(JC) $(JFLAGS) src/app/po/files/AbstractFile.java
src/app/po/files/StreamFile.class: src/app/po/files/StreamFile.java
		$(JC) $(JFLAGS) src/app/po/files/StreamFile.java
src/app/po/files/BufferedRelativeFile.class: src/app/po/files/BufferedRelativeFile.java
		$(JC) $(JFLAGS) src/app/po/files/BufferedRelativeFile.java
src/app/po/files/RelativeFile.class: src/app/po/files/RelativeFile.java
		$(JC) $(JFLAGS) src/app/po/files/RelativeFile.java
src/app/po/files/SecuentialFile.class: src/app/po/files/SecuentialFile.java
		$(JC) $(JFLAGS) src/app/po/files/SecuentialFile.java
src/app/po/persistors/IntegerPersistor.class: src/app/po/persistors/IntegerPersistor.java
		$(JC) $(JFLAGS) src/app/po/persistors/IntegerPersistor.java
src/app/po/persistors/SimpleStringPersistor.class: src/app/po/persistors/SimpleStringPersistor.java
		$(JC) $(JFLAGS) src/app/po/persistors/SimpleStringPersistor.java
src/app/po/persistors/DocumentInfoPersistor.class: src/app/po/persistors/DocumentInfoPersistor.java
		$(JC) $(JFLAGS) src/app/po/persistors/DocumentInfoPersistor.java
src/app/po/persistors/LinkedBlockPersistor.class: src/app/po/persistors/LinkedBlockPersistor.java
		$(JC) $(JFLAGS) src/app/po/persistors/LinkedBlockPersistor.java
src/app/po/persistors/AbstractPersistor.class: src/app/po/persistors/AbstractPersistor.java
		$(JC) $(JFLAGS) src/app/po/persistors/AbstractPersistor.java
src/app/po/persistors/SignatureFilePersistor.class: src/app/po/persistors/SignatureFilePersistor.java
		$(JC) $(JFLAGS) src/app/po/persistors/SignatureFilePersistor.java
src/app/po/persistors/BytePersistor.class: src/app/po/persistors/BytePersistor.java
		$(JC) $(JFLAGS) src/app/po/persistors/BytePersistor.java
src/app/po/persistors/MaxSizeAbstractPersistor.class: src/app/po/persistors/MaxSizeAbstractPersistor.java
		$(JC) $(JFLAGS) src/app/po/persistors/MaxSizeAbstractPersistor.java
src/app/po/persistors/DocumentDataPersistor.class: src/app/po/persistors/DocumentDataPersistor.java
		$(JC) $(JFLAGS) src/app/po/persistors/DocumentDataPersistor.java
src/app/po/persistors/LongPersistor.class: src/app/po/persistors/LongPersistor.java
		$(JC) $(JFLAGS) src/app/po/persistors/LongPersistor.java
src/app/po/persistors/StringPersistor.class: src/app/po/persistors/StringPersistor.java
		$(JC) $(JFLAGS) src/app/po/persistors/StringPersistor.java
src/app/po/persistors/BPlusNodePersistor.class: src/app/po/persistors/BPlusNodePersistor.java
		$(JC) $(JFLAGS) src/app/po/persistors/BPlusNodePersistor.java
src/app/po/persistors/BPlusElementPersistor.class: src/app/po/persistors/BPlusElementPersistor.java
		$(JC) $(JFLAGS) src/app/po/persistors/BPlusElementPersistor.java
src/app/po/persistors/GammaDistancesBlockPersistor.class: src/app/po/persistors/GammaDistancesBlockPersistor.java
		$(JC) $(JFLAGS) src/app/po/persistors/GammaDistancesBlockPersistor.java
src/app/po/persistors/VariableStringPersistor.class: src/app/po/persistors/VariableStringPersistor.java
		$(JC) $(JFLAGS) src/app/po/persistors/VariableStringPersistor.java
src/app/query/parser/CompositeQueryParser.class: src/app/query/parser/CompositeQueryParser.java
		$(JC) $(JFLAGS) src/app/query/parser/CompositeQueryParser.java
src/app/query/parser/ParentesisParser.class: src/app/query/parser/ParentesisParser.java
		$(JC) $(JFLAGS) src/app/query/parser/ParentesisParser.java
src/app/query/parser/TrimParser.class: src/app/query/parser/TrimParser.java
		$(JC) $(JFLAGS) src/app/query/parser/TrimParser.java
src/app/query/parser/exception/ParserException.class: src/app/query/parser/exception/ParserException.java
		$(JC) $(JFLAGS) src/app/query/parser/exception/ParserException.java
src/app/query/parser/exception/CantDigestException.class: src/app/query/parser/exception/CantDigestException.java
		$(JC) $(JFLAGS) src/app/query/parser/exception/CantDigestException.java
src/app/query/parser/exception/ParserGenericException.class: src/app/query/parser/exception/ParserGenericException.java
		$(JC) $(JFLAGS) src/app/query/parser/exception/ParserGenericException.java
src/app/query/parser/QueryAndParser.class: src/app/query/parser/QueryAndParser.java
		$(JC) $(JFLAGS) src/app/query/parser/QueryAndParser.java
src/app/query/parser/QueryNotParser.class: src/app/query/parser/QueryNotParser.java
		$(JC) $(JFLAGS) src/app/query/parser/QueryNotParser.java
src/app/query/parser/CompositeParser.class: src/app/query/parser/CompositeParser.java
		$(JC) $(JFLAGS) src/app/query/parser/CompositeParser.java
src/app/query/parser/QueryParser.class: src/app/query/parser/QueryParser.java
		$(JC) $(JFLAGS) src/app/query/parser/QueryParser.java
src/app/query/parser/RecursiveParser.class: src/app/query/parser/RecursiveParser.java
		$(JC) $(JFLAGS) src/app/query/parser/RecursiveParser.java
src/app/query/parser/QueryOrParser.class: src/app/query/parser/QueryOrParser.java
		$(JC) $(JFLAGS) src/app/query/parser/QueryOrParser.java
src/app/query/parser/QueryWordParser.class: src/app/query/parser/QueryWordParser.java
		$(JC) $(JFLAGS) src/app/query/parser/QueryWordParser.java
src/app/query/tree/QueryOr.class: src/app/query/tree/QueryOr.java
		$(JC) $(JFLAGS) src/app/query/tree/QueryOr.java
src/app/query/tree/QueryNot.class: src/app/query/tree/QueryNot.java
		$(JC) $(JFLAGS) src/app/query/tree/QueryNot.java
src/app/query/tree/CompositeQuery.class: src/app/query/tree/CompositeQuery.java
		$(JC) $(JFLAGS) src/app/query/tree/CompositeQuery.java
src/app/query/tree/QueryAnd.class: src/app/query/tree/QueryAnd.java
		$(JC) $(JFLAGS) src/app/query/tree/QueryAnd.java
src/app/query/QueryWord.class: src/app/query/QueryWord.java
		$(JC) $(JFLAGS) src/app/query/QueryWord.java
src/web/Model.class: src/web/Model.java
		$(JC) $(JFLAGS) src/web/Model.java
src/web/search/SearchView.class: src/web/search/SearchView.java
		$(JC) $(JFLAGS) src/web/search/SearchView.java
src/web/search/SearchModel.class: src/web/search/SearchModel.java
		$(JC) $(JFLAGS) src/web/search/SearchModel.java
src/web/indexer/IndexerStatsView.class: src/web/indexer/IndexerStatsView.java
		$(JC) $(JFLAGS) src/web/indexer/IndexerStatsView.java
src/web/indexer/IndexerModel.class: src/web/indexer/IndexerModel.java
		$(JC) $(JFLAGS) src/web/indexer/IndexerModel.java
src/web/indexer/IndexerView.class: src/web/indexer/IndexerView.java
		$(JC) $(JFLAGS) src/web/indexer/IndexerView.java
src/web/View.class: src/web/View.java
		$(JC) $(JFLAGS) src/web/View.java
src/api/QueryEngine.class: src/api/QueryEngine.java
		$(JC) $(JFLAGS) src/api/QueryEngine.java
src/api/WordCollectorQueryEngine.class: src/api/WordCollectorQueryEngine.java
		$(JC) $(JFLAGS) src/api/WordCollectorQueryEngine.java
src/api/SignatureFileQueryEngine.class: src/api/SignatureFileQueryEngine.java
		$(JC) $(JFLAGS) src/api/SignatureFileQueryEngine.java
src/api/dao/documents/DocumentsDictionary.class: src/api/dao/documents/DocumentsDictionary.java
		$(JC) $(JFLAGS) src/api/dao/documents/DocumentsDictionary.java
src/api/dao/BPlusTree/BPlusNodeDao.class: src/api/dao/BPlusTree/BPlusNodeDao.java
		$(JC) $(JFLAGS) src/api/dao/BPlusTree/BPlusNodeDao.java
src/api/bo/BPlusTree/BPlusTreeBo.class: src/api/bo/BPlusTree/BPlusTreeBo.java
		$(JC) $(JFLAGS) src/api/bo/BPlusTree/BPlusTreeBo.java
src/api/bo/BPlusTree/BPlusNodeBo.class: src/api/bo/BPlusTree/BPlusNodeBo.java
		$(JC) $(JFLAGS) src/api/bo/BPlusTree/BPlusNodeBo.java
src/api/po/files/Stack.class: src/api/po/files/Stack.java
		$(JC) $(JFLAGS) src/api/po/files/Stack.java
src/api/po/files/File.class: src/api/po/files/File.java
		$(JC) $(JFLAGS) src/api/po/files/File.java
src/api/po/persistors/SimplePersistor.class: src/api/po/persistors/SimplePersistor.java
		$(JC) $(JFLAGS) src/api/po/persistors/SimplePersistor.java
src/api/po/persistors/Persistor.class: src/api/po/persistors/Persistor.java
		$(JC) $(JFLAGS) src/api/po/persistors/Persistor.java
src/api/po/persistors/DistancesBlock.class: src/api/po/persistors/DistancesBlock.java
		$(JC) $(JFLAGS) src/api/po/persistors/DistancesBlock.java
src/api/po/persistors/SizeUtils.class: src/api/po/persistors/SizeUtils.java
		$(JC) $(JFLAGS) src/api/po/persistors/SizeUtils.java
src/api/DocumentInsert.class: src/api/DocumentInsert.java
		$(JC) $(JFLAGS) src/api/DocumentInsert.java
src/api/IQueryEngine.class: src/api/IQueryEngine.java
		$(JC) $(JFLAGS) src/api/IQueryEngine.java
src/api/DocumentsIndexer.class: src/api/DocumentsIndexer.java
		$(JC) $(JFLAGS) src/api/DocumentsIndexer.java
src/api/ObjectFactory.class: src/api/ObjectFactory.java
		$(JC) $(JFLAGS) src/api/ObjectFactory.java
src/api/DefaultQueryEngine.class: src/api/DefaultQueryEngine.java
		$(JC) $(JFLAGS) src/api/DefaultQueryEngine.java
src/api/MockQueryEngine.class: src/api/MockQueryEngine.java
		$(JC) $(JFLAGS) src/api/MockQueryEngine.java
src/api/AbstractQueryEngine.class: src/api/AbstractQueryEngine.java
		$(JC) $(JFLAGS) src/api/AbstractQueryEngine.java
src/api/Index.class: src/api/Index.java
		$(JC) $(JFLAGS) src/api/Index.java
src/api/query/parser/Parser.class: src/api/query/parser/Parser.java
		$(JC) $(JFLAGS) src/api/query/parser/Parser.java
src/api/query/tree/Query.class: src/api/query/tree/Query.java
		$(JC) $(JFLAGS) src/api/query/tree/Query.java
src/dto/SignatureFileDto.class: src/dto/SignatureFileDto.java
		$(JC) $(JFLAGS) src/dto/SignatureFileDto.java
src/dto/LinkedBlock.class: src/dto/LinkedBlock.java
		$(JC) $(JFLAGS) src/dto/LinkedBlock.java
src/dto/SuffixDto.class: src/dto/SuffixDto.java
		$(JC) $(JFLAGS) src/dto/SuffixDto.java
src/dto/DocumentsReportDto.class: src/dto/DocumentsReportDto.java
		$(JC) $(JFLAGS) src/dto/DocumentsReportDto.java
src/dto/StopwordsPipelineDto.class: src/dto/StopwordsPipelineDto.java
		$(JC) $(JFLAGS) src/dto/StopwordsPipelineDto.java
src/dto/DocumentStatisticsDto.class: src/dto/DocumentStatisticsDto.java
		$(JC) $(JFLAGS) src/dto/DocumentStatisticsDto.java
src/dto/WordDto.class: src/dto/WordDto.java
		$(JC) $(JFLAGS) src/dto/WordDto.java
src/dto/DocumentDto.class: src/dto/DocumentDto.java
		$(JC) $(JFLAGS) src/dto/DocumentDto.java
src/processor/stopwords/StopwordsProcessor.class: src/processor/stopwords/StopwordsProcessor.java
		$(JC) $(JFLAGS) src/processor/stopwords/StopwordsProcessor.java
src/processor/stemming/StemmingProcessor.class: src/processor/stemming/StemmingProcessor.java
		$(JC) $(JFLAGS) src/processor/stemming/StemmingProcessor.java
src/processor/utils/HtmlUtils.class: src/processor/utils/HtmlUtils.java
		$(JC) $(JFLAGS) src/processor/utils/HtmlUtils.java
src/processor/utils/DigesterUtils.class: src/processor/utils/DigesterUtils.java
		$(JC) $(JFLAGS) src/processor/utils/DigesterUtils.java
src/processor/IndexedDocumentChecker.class: src/processor/IndexedDocumentChecker.java
		$(JC) $(JFLAGS) src/processor/IndexedDocumentChecker.java
src/exceptions/BusinessException.class: src/exceptions/BusinessException.java
		$(JC) $(JFLAGS) src/exceptions/BusinessException.java
src/exceptions/PersistanceException.class: src/exceptions/PersistanceException.java
		$(JC) $(JFLAGS) src/exceptions/PersistanceException.java
src/exceptions/PipelineOverflowException.class: src/exceptions/PipelineOverflowException.java
		$(JC) $(JFLAGS) src/exceptions/PipelineOverflowException.java
src/exceptions/DataAccessException.class: src/exceptions/DataAccessException.java
		$(JC) $(JFLAGS) src/exceptions/DataAccessException.java
src/search.class: src/search.java
		$(JC) $(JFLAGS) src/search.java
src/bplus/exceptions/BPlusNodeException.class: src/bplus/exceptions/BPlusNodeException.java
		$(JC) $(JFLAGS) src/bplus/exceptions/BPlusNodeException.java
src/bplus/exceptions/NodeOverflowException.class: src/bplus/exceptions/NodeOverflowException.java
		$(JC) $(JFLAGS) src/bplus/exceptions/NodeOverflowException.java
src/bplus/exceptions/KeyNotFoundException.class: src/bplus/exceptions/KeyNotFoundException.java
		$(JC) $(JFLAGS) src/bplus/exceptions/KeyNotFoundException.java
src/bplus/exceptions/NodeNotFoundException.class: src/bplus/exceptions/NodeNotFoundException.java
		$(JC) $(JFLAGS) src/bplus/exceptions/NodeNotFoundException.java
src/bplus/exceptions/BPlusException.class: src/bplus/exceptions/BPlusException.java
		$(JC) $(JFLAGS) src/bplus/exceptions/BPlusException.java
src/bplus/elements/BPlusAbstractElement.class: src/bplus/elements/BPlusAbstractElement.java
		$(JC) $(JFLAGS) src/bplus/elements/BPlusAbstractElement.java
src/bplus/elements/BPlusLeafElement.class: src/bplus/elements/BPlusLeafElement.java
		$(JC) $(JFLAGS) src/bplus/elements/BPlusLeafElement.java
src/bplus/elements/BPlusElement.class: src/bplus/elements/BPlusElement.java
		$(JC) $(JFLAGS) src/bplus/elements/BPlusElement.java
src/bplus/elements/BPlusIndexElement.class: src/bplus/elements/BPlusIndexElement.java
		$(JC) $(JFLAGS) src/bplus/elements/BPlusIndexElement.java
src/bplus/nodes/BPlusIndexNode.class: src/bplus/nodes/BPlusIndexNode.java
		$(JC) $(JFLAGS) src/bplus/nodes/BPlusIndexNode.java
src/bplus/nodes/AbstractBPlusNode.class: src/bplus/nodes/AbstractBPlusNode.java
		$(JC) $(JFLAGS) src/bplus/nodes/AbstractBPlusNode.java
src/bplus/nodes/BPlusLeafNode.class: src/bplus/nodes/BPlusLeafNode.java
		$(JC) $(JFLAGS) src/bplus/nodes/BPlusLeafNode.java
src/bplus/nodes/BPlusNode.class: src/bplus/nodes/BPlusNode.java
		$(JC) $(JFLAGS) src/bplus/nodes/BPlusNode.java
src/bplus/NodeHandler.class: src/bplus/NodeHandler.java
		$(JC) $(JFLAGS) src/bplus/NodeHandler.java
src/bplus/BPlusTreeFacade.class: src/bplus/BPlusTreeFacade.java
		$(JC) $(JFLAGS) src/bplus/BPlusTreeFacade.java
src/bplus/keys/BPlusNodeKey.class: src/bplus/keys/BPlusNodeKey.java
		$(JC) $(JFLAGS) src/bplus/keys/BPlusNodeKey.java
src/bplus/keys/BPlusElementKey.class: src/bplus/keys/BPlusElementKey.java
		$(JC) $(JFLAGS) src/bplus/keys/BPlusElementKey.java
src/bplus/MockBPlusTreeFacade.class: src/bplus/MockBPlusTreeFacade.java
		$(JC) $(JFLAGS) src/bplus/MockBPlusTreeFacade.java
src/Servlet.class: src/Servlet.java
		$(JC) $(JFLAGS) src/Servlet.java
src/utils/statistics/StatisticsGenerator.class: src/utils/statistics/StatisticsGenerator.java
		$(JC) $(JFLAGS) src/utils/statistics/StatisticsGenerator.java
src/utils/statistics/Statistics.class: src/utils/statistics/Statistics.java
		$(JC) $(JFLAGS) src/utils/statistics/Statistics.java
src/utils/Constants.class: src/utils/Constants.java
		$(JC) $(JFLAGS) src/utils/Constants.java
src/SearchEngine.class: src/SearchEngine.java
		$(JC) $(JFLAGS) src/SearchEngine.java
src/Main.class: src/Main.java
		$(JC) $(JFLAGS) src/Main.java
src/index.class: src/index.java
		$(JC) $(JFLAGS) src/index.java
src/test/processor/TestStemmerProcessor.class: src/test/processor/TestStemmerProcessor.java
		$(JC) $(JFLAGS) src/test/processor/TestStemmerProcessor.java
src/test/files/StackFileTest.class: src/test/files/StackFileTest.java
		$(JC) $(JFLAGS) src/test/files/StackFileTest.java
src/test/files/SecuentialFileTest.class: src/test/files/SecuentialFileTest.java
		$(JC) $(JFLAGS) src/test/files/SecuentialFileTest.java
src/test/files/RelativelFileTest.class: src/test/files/RelativelFileTest.java
		$(JC) $(JFLAGS) src/test/files/RelativelFileTest.java
src/test/files/FileTest.class: src/test/files/FileTest.java
		$(JC) $(JFLAGS) src/test/files/FileTest.java
src/test/files/test.class: src/test/files/test.java
		$(JC) $(JFLAGS) src/test/files/test.java
src/test/files/BufferedRelativeFileTest.class: src/test/files/BufferedRelativeFileTest.java
		$(JC) $(JFLAGS) src/test/files/BufferedRelativeFileTest.java
src/test/index/TestMockDocumentsDictionary.class: src/test/index/TestMockDocumentsDictionary.java
		$(JC) $(JFLAGS) src/test/index/TestMockDocumentsDictionary.java
src/test/index/TestMockIndex.class: src/test/index/TestMockIndex.java
		$(JC) $(JFLAGS) src/test/index/TestMockIndex.java
src/test/index/TestLinkedBlocksManager.class: src/test/index/TestLinkedBlocksManager.java
		$(JC) $(JFLAGS) src/test/index/TestLinkedBlocksManager.java
src/test/index/TestDocumentsDictionary.class: src/test/index/TestDocumentsDictionary.java
		$(JC) $(JFLAGS) src/test/index/TestDocumentsDictionary.java
src/test/index/TestDefaultQueryEngine.class: src/test/index/TestDefaultQueryEngine.java
		$(JC) $(JFLAGS) src/test/index/TestDefaultQueryEngine.java
src/test/index/TestQueryEngineMocks.class: src/test/index/TestQueryEngineMocks.java
		$(JC) $(JFLAGS) src/test/index/TestQueryEngineMocks.java
src/test/index/TestDocumentsDictionaryImp.class: src/test/index/TestDocumentsDictionaryImp.java
		$(JC) $(JFLAGS) src/test/index/TestDocumentsDictionaryImp.java
src/test/index/TestIndexImp.class: src/test/index/TestIndexImp.java
		$(JC) $(JFLAGS) src/test/index/TestIndexImp.java
src/test/index/TestQueryEngine.class: src/test/index/TestQueryEngine.java
		$(JC) $(JFLAGS) src/test/index/TestQueryEngine.java
src/test/index/TestIndex.class: src/test/index/TestIndex.java
		$(JC) $(JFLAGS) src/test/index/TestIndex.java
src/test/bplus/TestBPlusTreeBoImp.class: src/test/bplus/TestBPlusTreeBoImp.java
		$(JC) $(JFLAGS) src/test/bplus/TestBPlusTreeBoImp.java
src/test/bplus/TestBPlusNodeDao.class: src/test/bplus/TestBPlusNodeDao.java
		$(JC) $(JFLAGS) src/test/bplus/TestBPlusNodeDao.java
src/test/bplus/BPlusTreeBoDaoTest.class: src/test/bplus/BPlusTreeBoDaoTest.java
		$(JC) $(JFLAGS) src/test/bplus/BPlusTreeBoDaoTest.java
src/test/bplus/TestBPlusTreeBoImpDaoTest.class: src/test/bplus/TestBPlusTreeBoImpDaoTest.java
		$(JC) $(JFLAGS) src/test/bplus/TestBPlusTreeBoImpDaoTest.java
src/test/bplus/TestBPlusNodeDaoTest.class: src/test/bplus/TestBPlusNodeDaoTest.java
		$(JC) $(JFLAGS) src/test/bplus/TestBPlusNodeDaoTest.java
src/test/bplus/TestBPlusNodeDaoImp.class: src/test/bplus/TestBPlusNodeDaoImp.java
		$(JC) $(JFLAGS) src/test/bplus/TestBPlusNodeDaoImp.java
src/test/bplus/BPlusNodeTestUtils.class: src/test/bplus/BPlusNodeTestUtils.java
		$(JC) $(JFLAGS) src/test/bplus/BPlusNodeTestUtils.java
src/test/bplus/TestBPlusTreeBoTest.class: src/test/bplus/TestBPlusTreeBoTest.java
		$(JC) $(JFLAGS) src/test/bplus/TestBPlusTreeBoTest.java
src/test/bplus/MapTest.class: src/test/bplus/MapTest.java
		$(JC) $(JFLAGS) src/test/bplus/MapTest.java
src/test/bplus/TestBPlusTreeBo.class: src/test/bplus/TestBPlusTreeBo.java
		$(JC) $(JFLAGS) src/test/bplus/TestBPlusTreeBo.java
src/test/persistors/TestBPlusNodePersistor.class: src/test/persistors/TestBPlusNodePersistor.java
		$(JC) $(JFLAGS) src/test/persistors/TestBPlusNodePersistor.java
src/test/persistors/TestPersistor.class: src/test/persistors/TestPersistor.java
		$(JC) $(JFLAGS) src/test/persistors/TestPersistor.java
src/test/persistors/TestIntegerPersistor.class: src/test/persistors/TestIntegerPersistor.java
		$(JC) $(JFLAGS) src/test/persistors/TestIntegerPersistor.java
src/test/persistors/TestStringPersistor.class: src/test/persistors/TestStringPersistor.java
		$(JC) $(JFLAGS) src/test/persistors/TestStringPersistor.java
src/test/persistors/TestBytePersistor.class: src/test/persistors/TestBytePersistor.java
		$(JC) $(JFLAGS) src/test/persistors/TestBytePersistor.java
src/test/utils/KeyCodificationTest.class: src/test/utils/KeyCodificationTest.java
		$(JC) $(JFLAGS) src/test/utils/KeyCodificationTest.java
src/test/utils/GammaDistancesBlockTest.class: src/test/utils/GammaDistancesBlockTest.java
		$(JC) $(JFLAGS) src/test/utils/GammaDistancesBlockTest.java
src/test/query/QueryTestCase.class: src/test/query/QueryTestCase.java
		$(JC) $(JFLAGS) src/test/query/QueryTestCase.java
src/test/query/QueryNotTest.class: src/test/query/QueryNotTest.java
		$(JC) $(JFLAGS) src/test/query/QueryNotTest.java
src/test/query/CompositeQueryTest.class: src/test/query/CompositeQueryTest.java
		$(JC) $(JFLAGS) src/test/query/CompositeQueryTest.java
src/test/query/ParserTest.class: src/test/query/ParserTest.java
		$(JC) $(JFLAGS) src/test/query/ParserTest.java
src/test/query/QueryAndTest.class: src/test/query/QueryAndTest.java
		$(JC) $(JFLAGS) src/test/query/QueryAndTest.java
src/test/query/MockQuery.class: src/test/query/MockQuery.java
		$(JC) $(JFLAGS) src/test/query/MockQuery.java
src/test/query/QueryOrTest.class: src/test/query/QueryOrTest.java
		$(JC) $(JFLAGS) src/test/query/QueryOrTest.java
src/ControllerServlet.class: src/ControllerServlet.java
		$(JC) $(JFLAGS) src/ControllerServlet.java
src/linkedblocks/LinkedBlocksManager.class: src/linkedblocks/LinkedBlocksManager.java
		$(JC) $(JFLAGS) src/linkedblocks/LinkedBlocksManager.java
src/linkedblocks/codification/GammaDistancesBlock.class: src/linkedblocks/codification/GammaDistancesBlock.java
		$(JC) $(JFLAGS) src/linkedblocks/codification/GammaDistancesBlock.java
src/linkedblocks/utils/KeyCodificationUtils.class: src/linkedblocks/utils/KeyCodificationUtils.java
		$(JC) $(JFLAGS) src/linkedblocks/utils/KeyCodificationUtils.java
src/linkedblocks/keys/DocumentIndexKey.class: src/linkedblocks/keys/DocumentIndexKey.java
		$(JC) $(JFLAGS) src/linkedblocks/keys/DocumentIndexKey.java
src/signaturefiles/hash/JSHash.class: src/signaturefiles/hash/JSHash.java
		$(JC) $(JFLAGS) src/signaturefiles/hash/JSHash.java
src/signaturefiles/hash/PJWHash.class: src/signaturefiles/hash/PJWHash.java
		$(JC) $(JFLAGS) src/signaturefiles/hash/PJWHash.java
src/signaturefiles/hash/BPHash.class: src/signaturefiles/hash/BPHash.java
		$(JC) $(JFLAGS) src/signaturefiles/hash/BPHash.java
src/signaturefiles/hash/Hash.class: src/signaturefiles/hash/Hash.java
		$(JC) $(JFLAGS) src/signaturefiles/hash/Hash.java
src/signaturefiles/hash/DEKHash.class: src/signaturefiles/hash/DEKHash.java
		$(JC) $(JFLAGS) src/signaturefiles/hash/DEKHash.java
src/signaturefiles/hash/SDBMHash.class: src/signaturefiles/hash/SDBMHash.java
		$(JC) $(JFLAGS) src/signaturefiles/hash/SDBMHash.java
src/signaturefiles/hash/ELFHash.class: src/signaturefiles/hash/ELFHash.java
		$(JC) $(JFLAGS) src/signaturefiles/hash/ELFHash.java
src/signaturefiles/hash/DJBHash.class: src/signaturefiles/hash/DJBHash.java
		$(JC) $(JFLAGS) src/signaturefiles/hash/DJBHash.java
src/signaturefiles/hash/RSHash.class: src/signaturefiles/hash/RSHash.java
		$(JC) $(JFLAGS) src/signaturefiles/hash/RSHash.java
src/signaturefiles/hash/FNVHash.class: src/signaturefiles/hash/FNVHash.java
		$(JC) $(JFLAGS) src/signaturefiles/hash/FNVHash.java
src/signaturefiles/hash/APHash.class: src/signaturefiles/hash/APHash.java
		$(JC) $(JFLAGS) src/signaturefiles/hash/APHash.java
src/signaturefiles/hash/BKDRHash.class: src/signaturefiles/hash/BKDRHash.java
		$(JC) $(JFLAGS) src/signaturefiles/hash/BKDRHash.java
src/signaturefiles/utils/SignatureUtils.class: src/signaturefiles/utils/SignatureUtils.java
		$(JC) $(JFLAGS) src/signaturefiles/utils/SignatureUtils.java
src/signaturefiles/SignatureGenerator.class: src/signaturefiles/SignatureGenerator.java
		$(JC) $(JFLAGS) src/signaturefiles/SignatureGenerator.java
src/TreeDumper.class: src/TreeDumper.java
		$(JC) $(JFLAGS) src/TreeDumper.java


