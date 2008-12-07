CLASSPATHS=src:WEB-INF/lib/htmlparser.jar:WEB-INF/lib/servlet-api.jar:WEB-INF/lib/junit-4.5.jar:WEB-INF/lib/log4j-1.2.15.jar

JFLAGS = -g:none -classpath $(CLASSPATHS) -d WEB-INF/classes/ -source 1.6 -target 1.6
JC = javac


CLASSES = ./src/app/dao/bplus/BPlusNodeDaoTest.java ./src/app/dao/bplus/BPlusNodeDaoImp.java ./src/app/dao/documents/NullDocumentsDictionary.java ./src/app/dao/documents/DocumentsDictionaryImp.java ./src/app/bo/WordCollectorIndex.java ./src/app/bo/bplus/AbstractBPlusTreeBo.java ./src/app/bo/bplus/BPlusTreeBoImp.java ./src/app/bo/bplus/BPlusTreeBoTest.java ./src/app/bo/MockDocumentsDictionary.java ./src/app/bo/MockIndex.java ./src/app/bo/IndexImp.java ./src/app/po/files/StackFile.java ./src/app/po/files/SecuencialFile.java ./src/app/po/files/AbstractBloquedFile.java ./src/app/po/files/AbstractFile.java ./src/app/po/files/StreamFile.java ./src/app/po/files/BufferedRelativeFile.java ./src/app/po/files/RelativeFile.java ./src/app/po/files/SecuentialFile.java ./src/app/po/persistors/IntegerPersistor.java ./src/app/po/persistors/SimpleStringPersistor.java ./src/app/po/persistors/DocumentInfoPersistor.java ./src/app/po/persistors/LinkedBlockPersistor.java ./src/app/po/persistors/AbstractPersistor.java ./src/app/po/persistors/SignatureFilePersistor.java ./src/app/po/persistors/BytePersistor.java ./src/app/po/persistors/MaxSizeAbstractPersistor.java ./src/app/po/persistors/DocumentDataPersistor.java ./src/app/po/persistors/LongPersistor.java ./src/app/po/persistors/StringPersistor.java ./src/app/po/persistors/BPlusNodePersistor.java ./src/app/po/persistors/BPlusElementPersistor.java ./src/app/po/persistors/GammaDistancesBlockPersistor.java ./src/app/po/persistors/VariableStringPersistor.java ./src/app/query/parser/CompositeQueryParser.java ./src/app/query/parser/ParentesisParser.java ./src/app/query/parser/TrimParser.java ./src/app/query/parser/exception/ParserException.java ./src/app/query/parser/exception/CantDigestException.java ./src/app/query/parser/exception/ParserGenericException.java ./src/app/query/parser/QueryAndParser.java ./src/app/query/parser/QueryNotParser.java ./src/app/query/parser/CompositeParser.java ./src/app/query/parser/QueryParser.java ./src/app/query/parser/RecursiveParser.java ./src/app/query/parser/QueryOrParser.java ./src/app/query/parser/QueryWordParser.java ./src/app/query/tree/QueryOr.java ./src/app/query/tree/QueryNot.java ./src/app/query/tree/CompositeQuery.java ./src/app/query/tree/QueryAnd.java ./src/app/query/QueryWord.java ./src/web/Model.java ./src/web/search/SearchView.java ./src/web/search/SearchModel.java ./src/web/indexer/IndexerStatsView.java ./src/web/indexer/IndexerModel.java ./src/web/indexer/IndexerView.java ./src/web/View.java ./src/api/QueryEngine.java ./src/api/WordCollectorQueryEngine.java ./src/api/SignatureFileQueryEngine.java ./src/api/dao/documents/DocumentsDictionary.java ./src/api/dao/BPlusTree/BPlusNodeDao.java ./src/api/bo/BPlusTree/BPlusTreeBo.java ./src/api/bo/BPlusTree/BPlusNodeBo.java ./src/api/po/files/Stack.java ./src/api/po/files/File.java ./src/api/po/persistors/SimplePersistor.java ./src/api/po/persistors/Persistor.java ./src/api/po/persistors/DistancesBlock.java ./src/api/po/persistors/SizeUtils.java ./src/api/DocumentInsert.java ./src/api/IQueryEngine.java ./src/api/DocumentsIndexer.java ./src/api/ObjectFactory.java ./src/api/DefaultQueryEngine.java ./src/api/MockQueryEngine.java ./src/api/AbstractQueryEngine.java ./src/api/Index.java ./src/api/query/parser/Parser.java ./src/api/query/tree/Query.java ./src/dto/SignatureFileDto.java ./src/dto/LinkedBlock.java ./src/dto/SuffixDto.java ./src/dto/DocumentsReportDto.java ./src/dto/StopwordsPipelineDto.java ./src/dto/DocumentStatisticsDto.java ./src/dto/WordDto.java ./src/dto/DocumentDto.java ./src/processor/stopwords/StopwordsProcessor.java ./src/processor/stemming/StemmingProcessor.java ./src/processor/utils/HtmlUtils.java ./src/processor/utils/DigesterUtils.java ./src/processor/IndexedDocumentChecker.java ./src/exceptions/BusinessException.java ./src/exceptions/PersistanceException.java ./src/exceptions/PipelineOverflowException.java ./src/exceptions/DataAccessException.java ./src/search.java ./src/bplus/exceptions/BPlusNodeException.java ./src/bplus/exceptions/NodeOverflowException.java ./src/bplus/exceptions/KeyNotFoundException.java ./src/bplus/exceptions/NodeNotFoundException.java ./src/bplus/exceptions/BPlusException.java ./src/bplus/elements/BPlusAbstractElement.java ./src/bplus/elements/BPlusLeafElement.java ./src/bplus/elements/BPlusElement.java ./src/bplus/elements/BPlusIndexElement.java ./src/bplus/nodes/BPlusIndexNode.java ./src/bplus/nodes/AbstractBPlusNode.java ./src/bplus/nodes/BPlusLeafNode.java ./src/bplus/nodes/BPlusNode.java ./src/bplus/NodeHandler.java ./src/bplus/BPlusTreeFacade.java ./src/bplus/keys/BPlusNodeKey.java ./src/bplus/keys/BPlusElementKey.java ./src/bplus/MockBPlusTreeFacade.java ./src/Servlet.java ./src/utils/statistics/StatisticsGenerator.java ./src/utils/statistics/Statistics.java ./src/utils/Constants.java ./src/SearchEngine.java ./src/Main.java ./src/index.java ./src/test/processor/TestStemmerProcessor.java ./src/test/files/StackFileTest.java ./src/test/files/SecuentialFileTest.java ./src/test/files/RelativelFileTest.java ./src/test/files/FileTest.java ./src/test/files/test.java ./src/test/files/BufferedRelativeFileTest.java ./src/test/index/TestMockDocumentsDictionary.java ./src/test/index/TestMockIndex.java ./src/test/index/TestLinkedBlocksManager.java ./src/test/index/TestDocumentsDictionary.java ./src/test/index/TestDefaultQueryEngine.java ./src/test/index/TestQueryEngineMocks.java ./src/test/index/TestDocumentsDictionaryImp.java ./src/test/index/TestIndexImp.java ./src/test/index/TestQueryEngine.java ./src/test/index/TestIndex.java ./src/test/bplus/TestBPlusTreeBoImp.java ./src/test/bplus/TestBPlusNodeDao.java ./src/test/bplus/BPlusTreeBoDaoTest.java ./src/test/bplus/TestBPlusTreeBoImpDaoTest.java ./src/test/bplus/TestBPlusNodeDaoTest.java ./src/test/bplus/TestBPlusNodeDaoImp.java ./src/test/bplus/BPlusNodeTestUtils.java ./src/test/bplus/TestBPlusTreeBoTest.java ./src/test/bplus/MapTest.java ./src/test/bplus/TestBPlusTreeBo.java ./src/test/persistors/TestBPlusNodePersistor.java ./src/test/persistors/TestPersistor.java ./src/test/persistors/TestIntegerPersistor.java ./src/test/persistors/TestStringPersistor.java ./src/test/persistors/TestBytePersistor.java ./src/test/utils/KeyCodificationTest.java ./src/test/utils/GammaDistancesBlockTest.java ./src/test/query/QueryTestCase.java ./src/test/query/QueryNotTest.java ./src/test/query/CompositeQueryTest.java ./src/test/query/ParserTest.java ./src/test/query/QueryAndTest.java ./src/test/query/MockQuery.java ./src/test/query/QueryOrTest.java ./src/ControllerServlet.java ./src/linkedblocks/LinkedBlocksManager.java ./src/linkedblocks/codification/GammaDistancesBlock.java ./src/linkedblocks/utils/KeyCodificationUtils.java ./src/linkedblocks/keys/DocumentIndexKey.java ./src/signaturefiles/hash/JSHash.java ./src/signaturefiles/hash/PJWHash.java ./src/signaturefiles/hash/BPHash.java ./src/signaturefiles/hash/Hash.java ./src/signaturefiles/hash/DEKHash.java ./src/signaturefiles/hash/SDBMHash.java ./src/signaturefiles/hash/ELFHash.java ./src/signaturefiles/hash/DJBHash.java ./src/signaturefiles/hash/RSHash.java ./src/signaturefiles/hash/FNVHash.java ./src/signaturefiles/hash/APHash.java ./src/signaturefiles/hash/BKDRHash.java ./src/signaturefiles/utils/SignatureUtils.java ./src/signaturefiles/SignatureGenerator.java ./src/TreeDumper.java

default: classes war jar
classes: WEB-INF/classes/app/dao/bplus/BPlusNodeDaoTest.class WEB-INF/classes/app/dao/bplus/BPlusNodeDaoImp.class WEB-INF/classes/app/dao/documents/NullDocumentsDictionary.class WEB-INF/classes/app/dao/documents/DocumentsDictionaryImp.class WEB-INF/classes/app/bo/WordCollectorIndex.class WEB-INF/classes/app/bo/bplus/AbstractBPlusTreeBo.class WEB-INF/classes/app/bo/bplus/BPlusTreeBoImp.class WEB-INF/classes/app/bo/bplus/BPlusTreeBoTest.class WEB-INF/classes/app/bo/MockDocumentsDictionary.class WEB-INF/classes/app/bo/MockIndex.class WEB-INF/classes/app/bo/IndexImp.class WEB-INF/classes/app/po/files/StackFile.class WEB-INF/classes/app/po/files/SecuencialFile.class WEB-INF/classes/app/po/files/AbstractBloquedFile.class WEB-INF/classes/app/po/files/AbstractFile.class WEB-INF/classes/app/po/files/StreamFile.class WEB-INF/classes/app/po/files/BufferedRelativeFile.class WEB-INF/classes/app/po/files/RelativeFile.class WEB-INF/classes/app/po/files/SecuentialFile.class WEB-INF/classes/app/po/persistors/IntegerPersistor.class WEB-INF/classes/app/po/persistors/SimpleStringPersistor.class WEB-INF/classes/app/po/persistors/DocumentInfoPersistor.class WEB-INF/classes/app/po/persistors/LinkedBlockPersistor.class WEB-INF/classes/app/po/persistors/AbstractPersistor.class WEB-INF/classes/app/po/persistors/SignatureFilePersistor.class WEB-INF/classes/app/po/persistors/BytePersistor.class WEB-INF/classes/app/po/persistors/MaxSizeAbstractPersistor.class WEB-INF/classes/app/po/persistors/DocumentDataPersistor.class WEB-INF/classes/app/po/persistors/LongPersistor.class WEB-INF/classes/app/po/persistors/StringPersistor.class WEB-INF/classes/app/po/persistors/BPlusNodePersistor.class WEB-INF/classes/app/po/persistors/BPlusElementPersistor.class WEB-INF/classes/app/po/persistors/GammaDistancesBlockPersistor.class WEB-INF/classes/app/po/persistors/VariableStringPersistor.class WEB-INF/classes/app/query/parser/CompositeQueryParser.class WEB-INF/classes/app/query/parser/ParentesisParser.class WEB-INF/classes/app/query/parser/TrimParser.class WEB-INF/classes/app/query/parser/exception/ParserException.class WEB-INF/classes/app/query/parser/exception/CantDigestException.class WEB-INF/classes/app/query/parser/exception/ParserGenericException.class WEB-INF/classes/app/query/parser/QueryAndParser.class WEB-INF/classes/app/query/parser/QueryNotParser.class WEB-INF/classes/app/query/parser/CompositeParser.class WEB-INF/classes/app/query/parser/QueryParser.class WEB-INF/classes/app/query/parser/RecursiveParser.class WEB-INF/classes/app/query/parser/QueryOrParser.class WEB-INF/classes/app/query/parser/QueryWordParser.class WEB-INF/classes/app/query/tree/QueryOr.class WEB-INF/classes/app/query/tree/QueryNot.class WEB-INF/classes/app/query/tree/CompositeQuery.class WEB-INF/classes/app/query/tree/QueryAnd.class WEB-INF/classes/app/query/QueryWord.class WEB-INF/classes/web/Model.class WEB-INF/classes/web/search/SearchView.class WEB-INF/classes/web/search/SearchModel.class WEB-INF/classes/web/indexer/IndexerStatsView.class WEB-INF/classes/web/indexer/IndexerModel.class WEB-INF/classes/web/indexer/IndexerView.class WEB-INF/classes/web/View.class WEB-INF/classes/api/QueryEngine.class WEB-INF/classes/api/WordCollectorQueryEngine.class WEB-INF/classes/api/SignatureFileQueryEngine.class WEB-INF/classes/api/dao/documents/DocumentsDictionary.class WEB-INF/classes/api/dao/BPlusTree/BPlusNodeDao.class WEB-INF/classes/api/bo/BPlusTree/BPlusTreeBo.class WEB-INF/classes/api/bo/BPlusTree/BPlusNodeBo.class WEB-INF/classes/api/po/files/Stack.class WEB-INF/classes/api/po/files/File.class WEB-INF/classes/api/po/persistors/SimplePersistor.class WEB-INF/classes/api/po/persistors/Persistor.class WEB-INF/classes/api/po/persistors/DistancesBlock.class WEB-INF/classes/api/po/persistors/SizeUtils.class WEB-INF/classes/api/DocumentInsert.class WEB-INF/classes/api/IQueryEngine.class WEB-INF/classes/api/DocumentsIndexer.class WEB-INF/classes/api/ObjectFactory.class WEB-INF/classes/api/DefaultQueryEngine.class WEB-INF/classes/api/MockQueryEngine.class WEB-INF/classes/api/AbstractQueryEngine.class WEB-INF/classes/api/Index.class WEB-INF/classes/api/query/parser/Parser.class WEB-INF/classes/api/query/tree/Query.class WEB-INF/classes/dto/SignatureFileDto.class WEB-INF/classes/dto/LinkedBlock.class WEB-INF/classes/dto/SuffixDto.class WEB-INF/classes/dto/DocumentsReportDto.class WEB-INF/classes/dto/StopwordsPipelineDto.class WEB-INF/classes/dto/DocumentStatisticsDto.class WEB-INF/classes/dto/WordDto.class WEB-INF/classes/dto/DocumentDto.class WEB-INF/classes/processor/stopwords/StopwordsProcessor.class WEB-INF/classes/processor/stemming/StemmingProcessor.class WEB-INF/classes/processor/utils/HtmlUtils.class WEB-INF/classes/processor/utils/DigesterUtils.class WEB-INF/classes/processor/IndexedDocumentChecker.class WEB-INF/classes/exceptions/BusinessException.class WEB-INF/classes/exceptions/PersistanceException.class WEB-INF/classes/exceptions/PipelineOverflowException.class WEB-INF/classes/exceptions/DataAccessException.class WEB-INF/classes/search.class WEB-INF/classes/bplus/exceptions/BPlusNodeException.class WEB-INF/classes/bplus/exceptions/NodeOverflowException.class WEB-INF/classes/bplus/exceptions/KeyNotFoundException.class WEB-INF/classes/bplus/exceptions/NodeNotFoundException.class WEB-INF/classes/bplus/exceptions/BPlusException.class WEB-INF/classes/bplus/elements/BPlusAbstractElement.class WEB-INF/classes/bplus/elements/BPlusLeafElement.class WEB-INF/classes/bplus/elements/BPlusElement.class WEB-INF/classes/bplus/elements/BPlusIndexElement.class WEB-INF/classes/bplus/nodes/BPlusIndexNode.class WEB-INF/classes/bplus/nodes/AbstractBPlusNode.class WEB-INF/classes/bplus/nodes/BPlusLeafNode.class WEB-INF/classes/bplus/nodes/BPlusNode.class WEB-INF/classes/bplus/NodeHandler.class WEB-INF/classes/bplus/BPlusTreeFacade.class WEB-INF/classes/bplus/keys/BPlusNodeKey.class WEB-INF/classes/bplus/keys/BPlusElementKey.class WEB-INF/classes/bplus/MockBPlusTreeFacade.class WEB-INF/classes/Servlet.class WEB-INF/classes/utils/statistics/StatisticsGenerator.class WEB-INF/classes/utils/statistics/Statistics.class WEB-INF/classes/utils/Constants.class WEB-INF/classes/SearchEngine.class WEB-INF/classes/Main.class WEB-INF/classes/index.class WEB-INF/classes/test/processor/TestStemmerProcessor.class WEB-INF/classes/test/files/StackFileTest.class WEB-INF/classes/test/files/SecuentialFileTest.class WEB-INF/classes/test/files/RelativelFileTest.class WEB-INF/classes/test/files/FileTest.class WEB-INF/classes/test/files/test.class WEB-INF/classes/test/files/BufferedRelativeFileTest.class WEB-INF/classes/test/index/TestMockDocumentsDictionary.class WEB-INF/classes/test/index/TestMockIndex.class WEB-INF/classes/test/index/TestLinkedBlocksManager.class WEB-INF/classes/test/index/TestDocumentsDictionary.class WEB-INF/classes/test/index/TestDefaultQueryEngine.class WEB-INF/classes/test/index/TestQueryEngineMocks.class WEB-INF/classes/test/index/TestDocumentsDictionaryImp.class WEB-INF/classes/test/index/TestIndexImp.class WEB-INF/classes/test/index/TestQueryEngine.class WEB-INF/classes/test/index/TestIndex.class WEB-INF/classes/test/bplus/TestBPlusTreeBoImp.class WEB-INF/classes/test/bplus/TestBPlusNodeDao.class WEB-INF/classes/test/bplus/BPlusTreeBoDaoTest.class WEB-INF/classes/test/bplus/TestBPlusTreeBoImpDaoTest.class WEB-INF/classes/test/bplus/TestBPlusNodeDaoTest.class WEB-INF/classes/test/bplus/TestBPlusNodeDaoImp.class WEB-INF/classes/test/bplus/BPlusNodeTestUtils.class WEB-INF/classes/test/bplus/TestBPlusTreeBoTest.class WEB-INF/classes/test/bplus/MapTest.class WEB-INF/classes/test/bplus/TestBPlusTreeBo.class WEB-INF/classes/test/persistors/TestBPlusNodePersistor.class WEB-INF/classes/test/persistors/TestPersistor.class WEB-INF/classes/test/persistors/TestIntegerPersistor.class WEB-INF/classes/test/persistors/TestStringPersistor.class WEB-INF/classes/test/persistors/TestBytePersistor.class WEB-INF/classes/test/utils/KeyCodificationTest.class WEB-INF/classes/test/utils/GammaDistancesBlockTest.class WEB-INF/classes/test/query/QueryTestCase.class WEB-INF/classes/test/query/QueryNotTest.class WEB-INF/classes/test/query/CompositeQueryTest.class WEB-INF/classes/test/query/ParserTest.class WEB-INF/classes/test/query/QueryAndTest.class WEB-INF/classes/test/query/MockQuery.class WEB-INF/classes/test/query/QueryOrTest.class WEB-INF/classes/ControllerServlet.class WEB-INF/classes/linkedblocks/LinkedBlocksManager.class WEB-INF/classes/linkedblocks/codification/GammaDistancesBlock.class WEB-INF/classes/linkedblocks/utils/KeyCodificationUtils.class WEB-INF/classes/linkedblocks/keys/DocumentIndexKey.class WEB-INF/classes/signaturefiles/hash/JSHash.class WEB-INF/classes/signaturefiles/hash/PJWHash.class WEB-INF/classes/signaturefiles/hash/BPHash.class WEB-INF/classes/signaturefiles/hash/Hash.class WEB-INF/classes/signaturefiles/hash/DEKHash.class WEB-INF/classes/signaturefiles/hash/SDBMHash.class WEB-INF/classes/signaturefiles/hash/ELFHash.class WEB-INF/classes/signaturefiles/hash/DJBHash.class WEB-INF/classes/signaturefiles/hash/RSHash.class WEB-INF/classes/signaturefiles/hash/FNVHash.class WEB-INF/classes/signaturefiles/hash/APHash.class WEB-INF/classes/signaturefiles/hash/BKDRHash.class WEB-INF/classes/signaturefiles/utils/SignatureUtils.class WEB-INF/classes/signaturefiles/SignatureGenerator.class WEB-INF/classes/TreeDumper.class
clean:
	   rm WEB-INF/classes/app/dao/bplus/BPlusNodeDaoTest.class WEB-INF/classes/app/dao/bplus/BPlusNodeDaoImp.class WEB-INF/classes/app/dao/documents/NullDocumentsDictionary.class WEB-INF/classes/app/dao/documents/DocumentsDictionaryImp.class WEB-INF/classes/app/bo/WordCollectorIndex.class WEB-INF/classes/app/bo/bplus/AbstractBPlusTreeBo.class WEB-INF/classes/app/bo/bplus/BPlusTreeBoImp.class WEB-INF/classes/app/bo/bplus/BPlusTreeBoTest.class WEB-INF/classes/app/bo/MockDocumentsDictionary.class WEB-INF/classes/app/bo/MockIndex.class WEB-INF/classes/app/bo/IndexImp.class WEB-INF/classes/app/po/files/StackFile.class WEB-INF/classes/app/po/files/SecuencialFile.class WEB-INF/classes/app/po/files/AbstractBloquedFile.class WEB-INF/classes/app/po/files/AbstractFile.class WEB-INF/classes/app/po/files/StreamFile.class WEB-INF/classes/app/po/files/BufferedRelativeFile.class WEB-INF/classes/app/po/files/RelativeFile.class WEB-INF/classes/app/po/files/SecuentialFile.class WEB-INF/classes/app/po/persistors/IntegerPersistor.class WEB-INF/classes/app/po/persistors/SimpleStringPersistor.class WEB-INF/classes/app/po/persistors/DocumentInfoPersistor.class WEB-INF/classes/app/po/persistors/LinkedBlockPersistor.class WEB-INF/classes/app/po/persistors/AbstractPersistor.class WEB-INF/classes/app/po/persistors/SignatureFilePersistor.class WEB-INF/classes/app/po/persistors/BytePersistor.class WEB-INF/classes/app/po/persistors/MaxSizeAbstractPersistor.class WEB-INF/classes/app/po/persistors/DocumentDataPersistor.class WEB-INF/classes/app/po/persistors/LongPersistor.class WEB-INF/classes/app/po/persistors/StringPersistor.class WEB-INF/classes/app/po/persistors/BPlusNodePersistor.class WEB-INF/classes/app/po/persistors/BPlusElementPersistor.class WEB-INF/classes/app/po/persistors/GammaDistancesBlockPersistor.class WEB-INF/classes/app/po/persistors/VariableStringPersistor.class WEB-INF/classes/app/query/parser/CompositeQueryParser.class WEB-INF/classes/app/query/parser/ParentesisParser.class WEB-INF/classes/app/query/parser/TrimParser.class WEB-INF/classes/app/query/parser/exception/ParserException.class WEB-INF/classes/app/query/parser/exception/CantDigestException.class WEB-INF/classes/app/query/parser/exception/ParserGenericException.class WEB-INF/classes/app/query/parser/QueryAndParser.class WEB-INF/classes/app/query/parser/QueryNotParser.class WEB-INF/classes/app/query/parser/CompositeParser.class WEB-INF/classes/app/query/parser/QueryParser.class WEB-INF/classes/app/query/parser/RecursiveParser.class WEB-INF/classes/app/query/parser/QueryOrParser.class WEB-INF/classes/app/query/parser/QueryWordParser.class WEB-INF/classes/app/query/tree/QueryOr.class WEB-INF/classes/app/query/tree/QueryNot.class WEB-INF/classes/app/query/tree/CompositeQuery.class WEB-INF/classes/app/query/tree/QueryAnd.class WEB-INF/classes/app/query/QueryWord.class WEB-INF/classes/web/Model.class WEB-INF/classes/web/search/SearchView.class WEB-INF/classes/web/search/SearchModel.class WEB-INF/classes/web/indexer/IndexerStatsView.class WEB-INF/classes/web/indexer/IndexerModel.class WEB-INF/classes/web/indexer/IndexerView.class WEB-INF/classes/web/View.class WEB-INF/classes/api/QueryEngine.class WEB-INF/classes/api/WordCollectorQueryEngine.class WEB-INF/classes/api/SignatureFileQueryEngine.class WEB-INF/classes/api/dao/documents/DocumentsDictionary.class WEB-INF/classes/api/dao/BPlusTree/BPlusNodeDao.class WEB-INF/classes/api/bo/BPlusTree/BPlusTreeBo.class WEB-INF/classes/api/bo/BPlusTree/BPlusNodeBo.class WEB-INF/classes/api/po/files/Stack.class WEB-INF/classes/api/po/files/File.class WEB-INF/classes/api/po/persistors/SimplePersistor.class WEB-INF/classes/api/po/persistors/Persistor.class WEB-INF/classes/api/po/persistors/DistancesBlock.class WEB-INF/classes/api/po/persistors/SizeUtils.class WEB-INF/classes/api/DocumentInsert.class WEB-INF/classes/api/IQueryEngine.class WEB-INF/classes/api/DocumentsIndexer.class WEB-INF/classes/api/ObjectFactory.class WEB-INF/classes/api/DefaultQueryEngine.class WEB-INF/classes/api/MockQueryEngine.class WEB-INF/classes/api/AbstractQueryEngine.class WEB-INF/classes/api/Index.class WEB-INF/classes/api/query/parser/Parser.class WEB-INF/classes/api/query/tree/Query.class WEB-INF/classes/dto/SignatureFileDto.class WEB-INF/classes/dto/LinkedBlock.class WEB-INF/classes/dto/SuffixDto.class WEB-INF/classes/dto/DocumentsReportDto.class WEB-INF/classes/dto/StopwordsPipelineDto.class WEB-INF/classes/dto/DocumentStatisticsDto.class WEB-INF/classes/dto/WordDto.class WEB-INF/classes/dto/DocumentDto.class WEB-INF/classes/processor/stopwords/StopwordsProcessor.class WEB-INF/classes/processor/stemming/StemmingProcessor.class WEB-INF/classes/processor/utils/HtmlUtils.class WEB-INF/classes/processor/utils/DigesterUtils.class WEB-INF/classes/processor/IndexedDocumentChecker.class WEB-INF/classes/exceptions/BusinessException.class WEB-INF/classes/exceptions/PersistanceException.class WEB-INF/classes/exceptions/PipelineOverflowException.class WEB-INF/classes/exceptions/DataAccessException.class WEB-INF/classes/search.class WEB-INF/classes/bplus/exceptions/BPlusNodeException.class WEB-INF/classes/bplus/exceptions/NodeOverflowException.class WEB-INF/classes/bplus/exceptions/KeyNotFoundException.class WEB-INF/classes/bplus/exceptions/NodeNotFoundException.class WEB-INF/classes/bplus/exceptions/BPlusException.class WEB-INF/classes/bplus/elements/BPlusAbstractElement.class WEB-INF/classes/bplus/elements/BPlusLeafElement.class WEB-INF/classes/bplus/elements/BPlusElement.class WEB-INF/classes/bplus/elements/BPlusIndexElement.class WEB-INF/classes/bplus/nodes/BPlusIndexNode.class WEB-INF/classes/bplus/nodes/AbstractBPlusNode.class WEB-INF/classes/bplus/nodes/BPlusLeafNode.class WEB-INF/classes/bplus/nodes/BPlusNode.class WEB-INF/classes/bplus/NodeHandler.class WEB-INF/classes/bplus/BPlusTreeFacade.class WEB-INF/classes/bplus/keys/BPlusNodeKey.class WEB-INF/classes/bplus/keys/BPlusElementKey.class WEB-INF/classes/bplus/MockBPlusTreeFacade.class WEB-INF/classes/Servlet.class WEB-INF/classes/utils/statistics/StatisticsGenerator.class WEB-INF/classes/utils/statistics/Statistics.class WEB-INF/classes/utils/Constants.class WEB-INF/classes/SearchEngine.class WEB-INF/classes/Main.class WEB-INF/classes/index.class WEB-INF/classes/test/processor/TestStemmerProcessor.class WEB-INF/classes/test/files/StackFileTest.class WEB-INF/classes/test/files/SecuentialFileTest.class WEB-INF/classes/test/files/RelativelFileTest.class WEB-INF/classes/test/files/FileTest.class WEB-INF/classes/test/files/test.class WEB-INF/classes/test/files/BufferedRelativeFileTest.class WEB-INF/classes/test/index/TestMockDocumentsDictionary.class WEB-INF/classes/test/index/TestMockIndex.class WEB-INF/classes/test/index/TestLinkedBlocksManager.class WEB-INF/classes/test/index/TestDocumentsDictionary.class WEB-INF/classes/test/index/TestDefaultQueryEngine.class WEB-INF/classes/test/index/TestQueryEngineMocks.class WEB-INF/classes/test/index/TestDocumentsDictionaryImp.class WEB-INF/classes/test/index/TestIndexImp.class WEB-INF/classes/test/index/TestQueryEngine.class WEB-INF/classes/test/index/TestIndex.class WEB-INF/classes/test/bplus/TestBPlusTreeBoImp.class WEB-INF/classes/test/bplus/TestBPlusNodeDao.class WEB-INF/classes/test/bplus/BPlusTreeBoDaoTest.class WEB-INF/classes/test/bplus/TestBPlusTreeBoImpDaoTest.class WEB-INF/classes/test/bplus/TestBPlusNodeDaoTest.class WEB-INF/classes/test/bplus/TestBPlusNodeDaoImp.class WEB-INF/classes/test/bplus/BPlusNodeTestUtils.class WEB-INF/classes/test/bplus/TestBPlusTreeBoTest.class WEB-INF/classes/test/bplus/MapTest.class WEB-INF/classes/test/bplus/TestBPlusTreeBo.class WEB-INF/classes/test/persistors/TestBPlusNodePersistor.class WEB-INF/classes/test/persistors/TestPersistor.class WEB-INF/classes/test/persistors/TestIntegerPersistor.class WEB-INF/classes/test/persistors/TestStringPersistor.class WEB-INF/classes/test/persistors/TestBytePersistor.class WEB-INF/classes/test/utils/KeyCodificationTest.class WEB-INF/classes/test/utils/GammaDistancesBlockTest.class WEB-INF/classes/test/query/QueryTestCase.class WEB-INF/classes/test/query/QueryNotTest.class WEB-INF/classes/test/query/CompositeQueryTest.class WEB-INF/classes/test/query/ParserTest.class WEB-INF/classes/test/query/QueryAndTest.class WEB-INF/classes/test/query/MockQuery.class WEB-INF/classes/test/query/QueryOrTest.class WEB-INF/classes/ControllerServlet.class WEB-INF/classes/linkedblocks/LinkedBlocksManager.class WEB-INF/classes/linkedblocks/codification/GammaDistancesBlock.class WEB-INF/classes/linkedblocks/utils/KeyCodificationUtils.class WEB-INF/classes/linkedblocks/keys/DocumentIndexKey.class WEB-INF/classes/signaturefiles/hash/JSHash.class WEB-INF/classes/signaturefiles/hash/PJWHash.class WEB-INF/classes/signaturefiles/hash/BPHash.class WEB-INF/classes/signaturefiles/hash/Hash.class WEB-INF/classes/signaturefiles/hash/DEKHash.class WEB-INF/classes/signaturefiles/hash/SDBMHash.class WEB-INF/classes/signaturefiles/hash/ELFHash.class WEB-INF/classes/signaturefiles/hash/DJBHash.class WEB-INF/classes/signaturefiles/hash/RSHash.class WEB-INF/classes/signaturefiles/hash/FNVHash.class WEB-INF/classes/signaturefiles/hash/APHash.class WEB-INF/classes/signaturefiles/hash/BKDRHash.class WEB-INF/classes/signaturefiles/utils/SignatureUtils.class WEB-INF/classes/signaturefiles/SignatureGenerator.class WEB-INF/classes/TreeDumper.class
war:
	cp src/log4j.xml WEB-INF/classes/
	test -d documents || mkdir documents
	jar cfm bombita.war manifesto.txt words/ html/ documents/ WEB-INF/
jar:
	cp src/log4j.xml WEB-INF/classes/
	test -d documents || mkdir documents
	cd WEB-INF/classes && jar cfm ../../bombita.jar ../../manifesto-jar.txt ../../words/ ../../html/ ../../documents/  .
dist:
	mv WEB-INF/classes WEB-INF/classes.tmp
	mkdir WEB-INF/classes
	tar -c ./src/app/dao/bplus/BPlusNodeDaoTest.java ./src/app/dao/bplus/BPlusNodeDaoImp.java ./src/app/dao/documents/NullDocumentsDictionary.java ./src/app/dao/documents/DocumentsDictionaryImp.java ./src/app/bo/WordCollectorIndex.java ./src/app/bo/bplus/AbstractBPlusTreeBo.java ./src/app/bo/bplus/BPlusTreeBoImp.java ./src/app/bo/bplus/BPlusTreeBoTest.java ./src/app/bo/MockDocumentsDictionary.java ./src/app/bo/MockIndex.java ./src/app/bo/IndexImp.java ./src/app/po/files/StackFile.java ./src/app/po/files/SecuencialFile.java ./src/app/po/files/AbstractBloquedFile.java ./src/app/po/files/AbstractFile.java ./src/app/po/files/StreamFile.java ./src/app/po/files/BufferedRelativeFile.java ./src/app/po/files/RelativeFile.java ./src/app/po/files/SecuentialFile.java ./src/app/po/persistors/IntegerPersistor.java ./src/app/po/persistors/SimpleStringPersistor.java ./src/app/po/persistors/DocumentInfoPersistor.java ./src/app/po/persistors/LinkedBlockPersistor.java ./src/app/po/persistors/AbstractPersistor.java ./src/app/po/persistors/SignatureFilePersistor.java ./src/app/po/persistors/BytePersistor.java ./src/app/po/persistors/MaxSizeAbstractPersistor.java ./src/app/po/persistors/DocumentDataPersistor.java ./src/app/po/persistors/LongPersistor.java ./src/app/po/persistors/StringPersistor.java ./src/app/po/persistors/BPlusNodePersistor.java ./src/app/po/persistors/BPlusElementPersistor.java ./src/app/po/persistors/GammaDistancesBlockPersistor.java ./src/app/po/persistors/VariableStringPersistor.java ./src/app/query/parser/CompositeQueryParser.java ./src/app/query/parser/ParentesisParser.java ./src/app/query/parser/TrimParser.java ./src/app/query/parser/exception/ParserException.java ./src/app/query/parser/exception/CantDigestException.java ./src/app/query/parser/exception/ParserGenericException.java ./src/app/query/parser/QueryAndParser.java ./src/app/query/parser/QueryNotParser.java ./src/app/query/parser/CompositeParser.java ./src/app/query/parser/QueryParser.java ./src/app/query/parser/RecursiveParser.java ./src/app/query/parser/QueryOrParser.java ./src/app/query/parser/QueryWordParser.java ./src/app/query/tree/QueryOr.java ./src/app/query/tree/QueryNot.java ./src/app/query/tree/CompositeQuery.java ./src/app/query/tree/QueryAnd.java ./src/app/query/QueryWord.java ./src/web/Model.java ./src/web/search/SearchView.java ./src/web/search/SearchModel.java ./src/web/indexer/IndexerStatsView.java ./src/web/indexer/IndexerModel.java ./src/web/indexer/IndexerView.java ./src/web/View.java ./src/api/QueryEngine.java ./src/api/WordCollectorQueryEngine.java ./src/api/SignatureFileQueryEngine.java ./src/api/dao/documents/DocumentsDictionary.java ./src/api/dao/BPlusTree/BPlusNodeDao.java ./src/api/bo/BPlusTree/BPlusTreeBo.java ./src/api/bo/BPlusTree/BPlusNodeBo.java ./src/api/po/files/Stack.java ./src/api/po/files/File.java ./src/api/po/persistors/SimplePersistor.java ./src/api/po/persistors/Persistor.java ./src/api/po/persistors/DistancesBlock.java ./src/api/po/persistors/SizeUtils.java ./src/api/DocumentInsert.java ./src/api/IQueryEngine.java ./src/api/DocumentsIndexer.java ./src/api/ObjectFactory.java ./src/api/DefaultQueryEngine.java ./src/api/MockQueryEngine.java ./src/api/AbstractQueryEngine.java ./src/api/Index.java ./src/api/query/parser/Parser.java ./src/api/query/tree/Query.java ./src/dto/SignatureFileDto.java ./src/dto/LinkedBlock.java ./src/dto/SuffixDto.java ./src/dto/DocumentsReportDto.java ./src/dto/StopwordsPipelineDto.java ./src/dto/DocumentStatisticsDto.java ./src/dto/WordDto.java ./src/dto/DocumentDto.java ./src/processor/stopwords/StopwordsProcessor.java ./src/processor/stemming/StemmingProcessor.java ./src/processor/utils/HtmlUtils.java ./src/processor/utils/DigesterUtils.java ./src/processor/IndexedDocumentChecker.java ./src/exceptions/BusinessException.java ./src/exceptions/PersistanceException.java ./src/exceptions/PipelineOverflowException.java ./src/exceptions/DataAccessException.java ./src/search.java ./src/bplus/exceptions/BPlusNodeException.java ./src/bplus/exceptions/NodeOverflowException.java ./src/bplus/exceptions/KeyNotFoundException.java ./src/bplus/exceptions/NodeNotFoundException.java ./src/bplus/exceptions/BPlusException.java ./src/bplus/elements/BPlusAbstractElement.java ./src/bplus/elements/BPlusLeafElement.java ./src/bplus/elements/BPlusElement.java ./src/bplus/elements/BPlusIndexElement.java ./src/bplus/nodes/BPlusIndexNode.java ./src/bplus/nodes/AbstractBPlusNode.java ./src/bplus/nodes/BPlusLeafNode.java ./src/bplus/nodes/BPlusNode.java ./src/bplus/NodeHandler.java ./src/bplus/BPlusTreeFacade.java ./src/bplus/keys/BPlusNodeKey.java ./src/bplus/keys/BPlusElementKey.java ./src/bplus/MockBPlusTreeFacade.java ./src/Servlet.java ./src/utils/statistics/StatisticsGenerator.java ./src/utils/statistics/Statistics.java ./src/utils/Constants.java ./src/SearchEngine.java ./src/Main.java ./src/index.java ./src/test/processor/TestStemmerProcessor.java ./src/test/files/StackFileTest.java ./src/test/files/SecuentialFileTest.java ./src/test/files/RelativelFileTest.java ./src/test/files/FileTest.java ./src/test/files/test.java ./src/test/files/BufferedRelativeFileTest.java ./src/test/index/TestMockDocumentsDictionary.java ./src/test/index/TestMockIndex.java ./src/test/index/TestLinkedBlocksManager.java ./src/test/index/TestDocumentsDictionary.java ./src/test/index/TestDefaultQueryEngine.java ./src/test/index/TestQueryEngineMocks.java ./src/test/index/TestDocumentsDictionaryImp.java ./src/test/index/TestIndexImp.java ./src/test/index/TestQueryEngine.java ./src/test/index/TestIndex.java ./src/test/bplus/TestBPlusTreeBoImp.java ./src/test/bplus/TestBPlusNodeDao.java ./src/test/bplus/BPlusTreeBoDaoTest.java ./src/test/bplus/TestBPlusTreeBoImpDaoTest.java ./src/test/bplus/TestBPlusNodeDaoTest.java ./src/test/bplus/TestBPlusNodeDaoImp.java ./src/test/bplus/BPlusNodeTestUtils.java ./src/test/bplus/TestBPlusTreeBoTest.java ./src/test/bplus/MapTest.java ./src/test/bplus/TestBPlusTreeBo.java ./src/test/persistors/TestBPlusNodePersistor.java ./src/test/persistors/TestPersistor.java ./src/test/persistors/TestIntegerPersistor.java ./src/test/persistors/TestStringPersistor.java ./src/test/persistors/TestBytePersistor.java ./src/test/utils/KeyCodificationTest.java ./src/test/utils/GammaDistancesBlockTest.java ./src/test/query/QueryTestCase.java ./src/test/query/QueryNotTest.java ./src/test/query/CompositeQueryTest.java ./src/test/query/ParserTest.java ./src/test/query/QueryAndTest.java ./src/test/query/MockQuery.java ./src/test/query/QueryOrTest.java ./src/ControllerServlet.java ./src/linkedblocks/LinkedBlocksManager.java ./src/linkedblocks/codification/GammaDistancesBlock.java ./src/linkedblocks/utils/KeyCodificationUtils.java ./src/linkedblocks/keys/DocumentIndexKey.java ./src/signaturefiles/hash/JSHash.java ./src/signaturefiles/hash/PJWHash.java ./src/signaturefiles/hash/BPHash.java ./src/signaturefiles/hash/Hash.java ./src/signaturefiles/hash/DEKHash.java ./src/signaturefiles/hash/SDBMHash.java ./src/signaturefiles/hash/ELFHash.java ./src/signaturefiles/hash/DJBHash.java ./src/signaturefiles/hash/RSHash.java ./src/signaturefiles/hash/FNVHash.java ./src/signaturefiles/hash/APHash.java ./src/signaturefiles/hash/BKDRHash.java ./src/signaturefiles/utils/SignatureUtils.java ./src/signaturefiles/SignatureGenerator.java ./src/TreeDumper.java leemeporfavor.txt manifesto.txt manifesto-jar.txt html/* src/log4j.xml words/stemming.txt words/stopwords.txt makefile WEB-INF/classes WEB-INF/web.xml WEB-INF/lib/junit-4.5.jar WEB-INF/lib/log4j-1.2.15.jar WEB-INF/lib/servlet-api.jar WEB-INF/lib/htmlparser.jar > bombita-src.tar 
	rmdir WEB-INF/classes
	mv WEB-INF/classes.tmp WEB-INF/classes
	gzip --force bombita-src.tar 
	@echo "*************************************************"
	@echo "* 	bombita-src.tar.gz generated	       *"
	@echo "*************************************************" 

WEB-INF/classes/app/dao/bplus/BPlusNodeDaoTest.class: src/app/dao/bplus/BPlusNodeDaoTest.java
		$(JC) $(JFLAGS) src/app/dao/bplus/BPlusNodeDaoTest.java
WEB-INF/classes/app/dao/bplus/BPlusNodeDaoImp.class: src/app/dao/bplus/BPlusNodeDaoImp.java
		$(JC) $(JFLAGS) src/app/dao/bplus/BPlusNodeDaoImp.java
WEB-INF/classes/app/dao/documents/NullDocumentsDictionary.class: src/app/dao/documents/NullDocumentsDictionary.java
		$(JC) $(JFLAGS) src/app/dao/documents/NullDocumentsDictionary.java
WEB-INF/classes/app/dao/documents/DocumentsDictionaryImp.class: src/app/dao/documents/DocumentsDictionaryImp.java
		$(JC) $(JFLAGS) src/app/dao/documents/DocumentsDictionaryImp.java
WEB-INF/classes/app/bo/WordCollectorIndex.class: src/app/bo/WordCollectorIndex.java
		$(JC) $(JFLAGS) src/app/bo/WordCollectorIndex.java
WEB-INF/classes/app/bo/bplus/AbstractBPlusTreeBo.class: src/app/bo/bplus/AbstractBPlusTreeBo.java
		$(JC) $(JFLAGS) src/app/bo/bplus/AbstractBPlusTreeBo.java
WEB-INF/classes/app/bo/bplus/BPlusTreeBoImp.class: src/app/bo/bplus/BPlusTreeBoImp.java
		$(JC) $(JFLAGS) src/app/bo/bplus/BPlusTreeBoImp.java
WEB-INF/classes/app/bo/bplus/BPlusTreeBoTest.class: src/app/bo/bplus/BPlusTreeBoTest.java
		$(JC) $(JFLAGS) src/app/bo/bplus/BPlusTreeBoTest.java
WEB-INF/classes/app/bo/MockDocumentsDictionary.class: src/app/bo/MockDocumentsDictionary.java
		$(JC) $(JFLAGS) src/app/bo/MockDocumentsDictionary.java
WEB-INF/classes/app/bo/MockIndex.class: src/app/bo/MockIndex.java
		$(JC) $(JFLAGS) src/app/bo/MockIndex.java
WEB-INF/classes/app/bo/IndexImp.class: src/app/bo/IndexImp.java
		$(JC) $(JFLAGS) src/app/bo/IndexImp.java
WEB-INF/classes/app/po/files/StackFile.class: src/app/po/files/StackFile.java
		$(JC) $(JFLAGS) src/app/po/files/StackFile.java
WEB-INF/classes/app/po/files/SecuencialFile.class: src/app/po/files/SecuencialFile.java
		$(JC) $(JFLAGS) src/app/po/files/SecuencialFile.java
WEB-INF/classes/app/po/files/AbstractBloquedFile.class: src/app/po/files/AbstractBloquedFile.java
		$(JC) $(JFLAGS) src/app/po/files/AbstractBloquedFile.java
WEB-INF/classes/app/po/files/AbstractFile.class: src/app/po/files/AbstractFile.java
		$(JC) $(JFLAGS) src/app/po/files/AbstractFile.java
WEB-INF/classes/app/po/files/StreamFile.class: src/app/po/files/StreamFile.java
		$(JC) $(JFLAGS) src/app/po/files/StreamFile.java
WEB-INF/classes/app/po/files/BufferedRelativeFile.class: src/app/po/files/BufferedRelativeFile.java
		$(JC) $(JFLAGS) src/app/po/files/BufferedRelativeFile.java
WEB-INF/classes/app/po/files/RelativeFile.class: src/app/po/files/RelativeFile.java
		$(JC) $(JFLAGS) src/app/po/files/RelativeFile.java
WEB-INF/classes/app/po/files/SecuentialFile.class: src/app/po/files/SecuentialFile.java
		$(JC) $(JFLAGS) src/app/po/files/SecuentialFile.java
WEB-INF/classes/app/po/persistors/IntegerPersistor.class: src/app/po/persistors/IntegerPersistor.java
		$(JC) $(JFLAGS) src/app/po/persistors/IntegerPersistor.java
WEB-INF/classes/app/po/persistors/SimpleStringPersistor.class: src/app/po/persistors/SimpleStringPersistor.java
		$(JC) $(JFLAGS) src/app/po/persistors/SimpleStringPersistor.java
WEB-INF/classes/app/po/persistors/DocumentInfoPersistor.class: src/app/po/persistors/DocumentInfoPersistor.java
		$(JC) $(JFLAGS) src/app/po/persistors/DocumentInfoPersistor.java
WEB-INF/classes/app/po/persistors/LinkedBlockPersistor.class: src/app/po/persistors/LinkedBlockPersistor.java
		$(JC) $(JFLAGS) src/app/po/persistors/LinkedBlockPersistor.java
WEB-INF/classes/app/po/persistors/AbstractPersistor.class: src/app/po/persistors/AbstractPersistor.java
		$(JC) $(JFLAGS) src/app/po/persistors/AbstractPersistor.java
WEB-INF/classes/app/po/persistors/SignatureFilePersistor.class: src/app/po/persistors/SignatureFilePersistor.java
		$(JC) $(JFLAGS) src/app/po/persistors/SignatureFilePersistor.java
WEB-INF/classes/app/po/persistors/BytePersistor.class: src/app/po/persistors/BytePersistor.java
		$(JC) $(JFLAGS) src/app/po/persistors/BytePersistor.java
WEB-INF/classes/app/po/persistors/MaxSizeAbstractPersistor.class: src/app/po/persistors/MaxSizeAbstractPersistor.java
		$(JC) $(JFLAGS) src/app/po/persistors/MaxSizeAbstractPersistor.java
WEB-INF/classes/app/po/persistors/DocumentDataPersistor.class: src/app/po/persistors/DocumentDataPersistor.java
		$(JC) $(JFLAGS) src/app/po/persistors/DocumentDataPersistor.java
WEB-INF/classes/app/po/persistors/LongPersistor.class: src/app/po/persistors/LongPersistor.java
		$(JC) $(JFLAGS) src/app/po/persistors/LongPersistor.java
WEB-INF/classes/app/po/persistors/StringPersistor.class: src/app/po/persistors/StringPersistor.java
		$(JC) $(JFLAGS) src/app/po/persistors/StringPersistor.java
WEB-INF/classes/app/po/persistors/BPlusNodePersistor.class: src/app/po/persistors/BPlusNodePersistor.java
		$(JC) $(JFLAGS) src/app/po/persistors/BPlusNodePersistor.java
WEB-INF/classes/app/po/persistors/BPlusElementPersistor.class: src/app/po/persistors/BPlusElementPersistor.java
		$(JC) $(JFLAGS) src/app/po/persistors/BPlusElementPersistor.java
WEB-INF/classes/app/po/persistors/GammaDistancesBlockPersistor.class: src/app/po/persistors/GammaDistancesBlockPersistor.java
		$(JC) $(JFLAGS) src/app/po/persistors/GammaDistancesBlockPersistor.java
WEB-INF/classes/app/po/persistors/VariableStringPersistor.class: src/app/po/persistors/VariableStringPersistor.java
		$(JC) $(JFLAGS) src/app/po/persistors/VariableStringPersistor.java
WEB-INF/classes/app/query/parser/CompositeQueryParser.class: src/app/query/parser/CompositeQueryParser.java
		$(JC) $(JFLAGS) src/app/query/parser/CompositeQueryParser.java
WEB-INF/classes/app/query/parser/ParentesisParser.class: src/app/query/parser/ParentesisParser.java
		$(JC) $(JFLAGS) src/app/query/parser/ParentesisParser.java
WEB-INF/classes/app/query/parser/TrimParser.class: src/app/query/parser/TrimParser.java
		$(JC) $(JFLAGS) src/app/query/parser/TrimParser.java
WEB-INF/classes/app/query/parser/exception/ParserException.class: src/app/query/parser/exception/ParserException.java
		$(JC) $(JFLAGS) src/app/query/parser/exception/ParserException.java
WEB-INF/classes/app/query/parser/exception/CantDigestException.class: src/app/query/parser/exception/CantDigestException.java
		$(JC) $(JFLAGS) src/app/query/parser/exception/CantDigestException.java
WEB-INF/classes/app/query/parser/exception/ParserGenericException.class: src/app/query/parser/exception/ParserGenericException.java
		$(JC) $(JFLAGS) src/app/query/parser/exception/ParserGenericException.java
WEB-INF/classes/app/query/parser/QueryAndParser.class: src/app/query/parser/QueryAndParser.java
		$(JC) $(JFLAGS) src/app/query/parser/QueryAndParser.java
WEB-INF/classes/app/query/parser/QueryNotParser.class: src/app/query/parser/QueryNotParser.java
		$(JC) $(JFLAGS) src/app/query/parser/QueryNotParser.java
WEB-INF/classes/app/query/parser/CompositeParser.class: src/app/query/parser/CompositeParser.java
		$(JC) $(JFLAGS) src/app/query/parser/CompositeParser.java
WEB-INF/classes/app/query/parser/QueryParser.class: src/app/query/parser/QueryParser.java
		$(JC) $(JFLAGS) src/app/query/parser/QueryParser.java
WEB-INF/classes/app/query/parser/RecursiveParser.class: src/app/query/parser/RecursiveParser.java
		$(JC) $(JFLAGS) src/app/query/parser/RecursiveParser.java
WEB-INF/classes/app/query/parser/QueryOrParser.class: src/app/query/parser/QueryOrParser.java
		$(JC) $(JFLAGS) src/app/query/parser/QueryOrParser.java
WEB-INF/classes/app/query/parser/QueryWordParser.class: src/app/query/parser/QueryWordParser.java
		$(JC) $(JFLAGS) src/app/query/parser/QueryWordParser.java
WEB-INF/classes/app/query/tree/QueryOr.class: src/app/query/tree/QueryOr.java
		$(JC) $(JFLAGS) src/app/query/tree/QueryOr.java
WEB-INF/classes/app/query/tree/QueryNot.class: src/app/query/tree/QueryNot.java
		$(JC) $(JFLAGS) src/app/query/tree/QueryNot.java
WEB-INF/classes/app/query/tree/CompositeQuery.class: src/app/query/tree/CompositeQuery.java
		$(JC) $(JFLAGS) src/app/query/tree/CompositeQuery.java
WEB-INF/classes/app/query/tree/QueryAnd.class: src/app/query/tree/QueryAnd.java
		$(JC) $(JFLAGS) src/app/query/tree/QueryAnd.java
WEB-INF/classes/app/query/QueryWord.class: src/app/query/QueryWord.java
		$(JC) $(JFLAGS) src/app/query/QueryWord.java
WEB-INF/classes/web/Model.class: src/web/Model.java
		$(JC) $(JFLAGS) src/web/Model.java
WEB-INF/classes/web/search/SearchView.class: src/web/search/SearchView.java
		$(JC) $(JFLAGS) src/web/search/SearchView.java
WEB-INF/classes/web/search/SearchModel.class: src/web/search/SearchModel.java
		$(JC) $(JFLAGS) src/web/search/SearchModel.java
WEB-INF/classes/web/indexer/IndexerStatsView.class: src/web/indexer/IndexerStatsView.java
		$(JC) $(JFLAGS) src/web/indexer/IndexerStatsView.java
WEB-INF/classes/web/indexer/IndexerModel.class: src/web/indexer/IndexerModel.java
		$(JC) $(JFLAGS) src/web/indexer/IndexerModel.java
WEB-INF/classes/web/indexer/IndexerView.class: src/web/indexer/IndexerView.java
		$(JC) $(JFLAGS) src/web/indexer/IndexerView.java
WEB-INF/classes/web/View.class: src/web/View.java
		$(JC) $(JFLAGS) src/web/View.java
WEB-INF/classes/api/QueryEngine.class: src/api/QueryEngine.java
		$(JC) $(JFLAGS) src/api/QueryEngine.java
WEB-INF/classes/api/WordCollectorQueryEngine.class: src/api/WordCollectorQueryEngine.java
		$(JC) $(JFLAGS) src/api/WordCollectorQueryEngine.java
WEB-INF/classes/api/SignatureFileQueryEngine.class: src/api/SignatureFileQueryEngine.java
		$(JC) $(JFLAGS) src/api/SignatureFileQueryEngine.java
WEB-INF/classes/api/dao/documents/DocumentsDictionary.class: src/api/dao/documents/DocumentsDictionary.java
		$(JC) $(JFLAGS) src/api/dao/documents/DocumentsDictionary.java
WEB-INF/classes/api/dao/BPlusTree/BPlusNodeDao.class: src/api/dao/BPlusTree/BPlusNodeDao.java
		$(JC) $(JFLAGS) src/api/dao/BPlusTree/BPlusNodeDao.java
WEB-INF/classes/api/bo/BPlusTree/BPlusTreeBo.class: src/api/bo/BPlusTree/BPlusTreeBo.java
		$(JC) $(JFLAGS) src/api/bo/BPlusTree/BPlusTreeBo.java
WEB-INF/classes/api/bo/BPlusTree/BPlusNodeBo.class: src/api/bo/BPlusTree/BPlusNodeBo.java
		$(JC) $(JFLAGS) src/api/bo/BPlusTree/BPlusNodeBo.java
WEB-INF/classes/api/po/files/Stack.class: src/api/po/files/Stack.java
		$(JC) $(JFLAGS) src/api/po/files/Stack.java
WEB-INF/classes/api/po/files/File.class: src/api/po/files/File.java
		$(JC) $(JFLAGS) src/api/po/files/File.java
WEB-INF/classes/api/po/persistors/SimplePersistor.class: src/api/po/persistors/SimplePersistor.java
		$(JC) $(JFLAGS) src/api/po/persistors/SimplePersistor.java
WEB-INF/classes/api/po/persistors/Persistor.class: src/api/po/persistors/Persistor.java
		$(JC) $(JFLAGS) src/api/po/persistors/Persistor.java
WEB-INF/classes/api/po/persistors/DistancesBlock.class: src/api/po/persistors/DistancesBlock.java
		$(JC) $(JFLAGS) src/api/po/persistors/DistancesBlock.java
WEB-INF/classes/api/po/persistors/SizeUtils.class: src/api/po/persistors/SizeUtils.java
		$(JC) $(JFLAGS) src/api/po/persistors/SizeUtils.java
WEB-INF/classes/api/DocumentInsert.class: src/api/DocumentInsert.java
		$(JC) $(JFLAGS) src/api/DocumentInsert.java
WEB-INF/classes/api/IQueryEngine.class: src/api/IQueryEngine.java
		$(JC) $(JFLAGS) src/api/IQueryEngine.java
WEB-INF/classes/api/DocumentsIndexer.class: src/api/DocumentsIndexer.java
		$(JC) $(JFLAGS) src/api/DocumentsIndexer.java
WEB-INF/classes/api/ObjectFactory.class: src/api/ObjectFactory.java
		$(JC) $(JFLAGS) src/api/ObjectFactory.java
WEB-INF/classes/api/DefaultQueryEngine.class: src/api/DefaultQueryEngine.java
		$(JC) $(JFLAGS) src/api/DefaultQueryEngine.java
WEB-INF/classes/api/MockQueryEngine.class: src/api/MockQueryEngine.java
		$(JC) $(JFLAGS) src/api/MockQueryEngine.java
WEB-INF/classes/api/AbstractQueryEngine.class: src/api/AbstractQueryEngine.java
		$(JC) $(JFLAGS) src/api/AbstractQueryEngine.java
WEB-INF/classes/api/Index.class: src/api/Index.java
		$(JC) $(JFLAGS) src/api/Index.java
WEB-INF/classes/api/query/parser/Parser.class: src/api/query/parser/Parser.java
		$(JC) $(JFLAGS) src/api/query/parser/Parser.java
WEB-INF/classes/api/query/tree/Query.class: src/api/query/tree/Query.java
		$(JC) $(JFLAGS) src/api/query/tree/Query.java
WEB-INF/classes/dto/SignatureFileDto.class: src/dto/SignatureFileDto.java
		$(JC) $(JFLAGS) src/dto/SignatureFileDto.java
WEB-INF/classes/dto/LinkedBlock.class: src/dto/LinkedBlock.java
		$(JC) $(JFLAGS) src/dto/LinkedBlock.java
WEB-INF/classes/dto/SuffixDto.class: src/dto/SuffixDto.java
		$(JC) $(JFLAGS) src/dto/SuffixDto.java
WEB-INF/classes/dto/DocumentsReportDto.class: src/dto/DocumentsReportDto.java
		$(JC) $(JFLAGS) src/dto/DocumentsReportDto.java
WEB-INF/classes/dto/StopwordsPipelineDto.class: src/dto/StopwordsPipelineDto.java
		$(JC) $(JFLAGS) src/dto/StopwordsPipelineDto.java
WEB-INF/classes/dto/DocumentStatisticsDto.class: src/dto/DocumentStatisticsDto.java
		$(JC) $(JFLAGS) src/dto/DocumentStatisticsDto.java
WEB-INF/classes/dto/WordDto.class: src/dto/WordDto.java
		$(JC) $(JFLAGS) src/dto/WordDto.java
WEB-INF/classes/dto/DocumentDto.class: src/dto/DocumentDto.java
		$(JC) $(JFLAGS) src/dto/DocumentDto.java
WEB-INF/classes/processor/stopwords/StopwordsProcessor.class: src/processor/stopwords/StopwordsProcessor.java
		$(JC) $(JFLAGS) src/processor/stopwords/StopwordsProcessor.java
WEB-INF/classes/processor/stemming/StemmingProcessor.class: src/processor/stemming/StemmingProcessor.java
		$(JC) $(JFLAGS) src/processor/stemming/StemmingProcessor.java
WEB-INF/classes/processor/utils/HtmlUtils.class: src/processor/utils/HtmlUtils.java
		$(JC) $(JFLAGS) src/processor/utils/HtmlUtils.java
WEB-INF/classes/processor/utils/DigesterUtils.class: src/processor/utils/DigesterUtils.java
		$(JC) $(JFLAGS) src/processor/utils/DigesterUtils.java
WEB-INF/classes/processor/IndexedDocumentChecker.class: src/processor/IndexedDocumentChecker.java
		$(JC) $(JFLAGS) src/processor/IndexedDocumentChecker.java
WEB-INF/classes/exceptions/BusinessException.class: src/exceptions/BusinessException.java
		$(JC) $(JFLAGS) src/exceptions/BusinessException.java
WEB-INF/classes/exceptions/PersistanceException.class: src/exceptions/PersistanceException.java
		$(JC) $(JFLAGS) src/exceptions/PersistanceException.java
WEB-INF/classes/exceptions/PipelineOverflowException.class: src/exceptions/PipelineOverflowException.java
		$(JC) $(JFLAGS) src/exceptions/PipelineOverflowException.java
WEB-INF/classes/exceptions/DataAccessException.class: src/exceptions/DataAccessException.java
		$(JC) $(JFLAGS) src/exceptions/DataAccessException.java
WEB-INF/classes/search.class: src/search.java
		$(JC) $(JFLAGS) src/search.java
WEB-INF/classes/bplus/exceptions/BPlusNodeException.class: src/bplus/exceptions/BPlusNodeException.java
		$(JC) $(JFLAGS) src/bplus/exceptions/BPlusNodeException.java
WEB-INF/classes/bplus/exceptions/NodeOverflowException.class: src/bplus/exceptions/NodeOverflowException.java
		$(JC) $(JFLAGS) src/bplus/exceptions/NodeOverflowException.java
WEB-INF/classes/bplus/exceptions/KeyNotFoundException.class: src/bplus/exceptions/KeyNotFoundException.java
		$(JC) $(JFLAGS) src/bplus/exceptions/KeyNotFoundException.java
WEB-INF/classes/bplus/exceptions/NodeNotFoundException.class: src/bplus/exceptions/NodeNotFoundException.java
		$(JC) $(JFLAGS) src/bplus/exceptions/NodeNotFoundException.java
WEB-INF/classes/bplus/exceptions/BPlusException.class: src/bplus/exceptions/BPlusException.java
		$(JC) $(JFLAGS) src/bplus/exceptions/BPlusException.java
WEB-INF/classes/bplus/elements/BPlusAbstractElement.class: src/bplus/elements/BPlusAbstractElement.java
		$(JC) $(JFLAGS) src/bplus/elements/BPlusAbstractElement.java
WEB-INF/classes/bplus/elements/BPlusLeafElement.class: src/bplus/elements/BPlusLeafElement.java
		$(JC) $(JFLAGS) src/bplus/elements/BPlusLeafElement.java
WEB-INF/classes/bplus/elements/BPlusElement.class: src/bplus/elements/BPlusElement.java
		$(JC) $(JFLAGS) src/bplus/elements/BPlusElement.java
WEB-INF/classes/bplus/elements/BPlusIndexElement.class: src/bplus/elements/BPlusIndexElement.java
		$(JC) $(JFLAGS) src/bplus/elements/BPlusIndexElement.java
WEB-INF/classes/bplus/nodes/BPlusIndexNode.class: src/bplus/nodes/BPlusIndexNode.java
		$(JC) $(JFLAGS) src/bplus/nodes/BPlusIndexNode.java
WEB-INF/classes/bplus/nodes/AbstractBPlusNode.class: src/bplus/nodes/AbstractBPlusNode.java
		$(JC) $(JFLAGS) src/bplus/nodes/AbstractBPlusNode.java
WEB-INF/classes/bplus/nodes/BPlusLeafNode.class: src/bplus/nodes/BPlusLeafNode.java
		$(JC) $(JFLAGS) src/bplus/nodes/BPlusLeafNode.java
WEB-INF/classes/bplus/nodes/BPlusNode.class: src/bplus/nodes/BPlusNode.java
		$(JC) $(JFLAGS) src/bplus/nodes/BPlusNode.java
WEB-INF/classes/bplus/NodeHandler.class: src/bplus/NodeHandler.java
		$(JC) $(JFLAGS) src/bplus/NodeHandler.java
WEB-INF/classes/bplus/BPlusTreeFacade.class: src/bplus/BPlusTreeFacade.java
		$(JC) $(JFLAGS) src/bplus/BPlusTreeFacade.java
WEB-INF/classes/bplus/keys/BPlusNodeKey.class: src/bplus/keys/BPlusNodeKey.java
		$(JC) $(JFLAGS) src/bplus/keys/BPlusNodeKey.java
WEB-INF/classes/bplus/keys/BPlusElementKey.class: src/bplus/keys/BPlusElementKey.java
		$(JC) $(JFLAGS) src/bplus/keys/BPlusElementKey.java
WEB-INF/classes/bplus/MockBPlusTreeFacade.class: src/bplus/MockBPlusTreeFacade.java
		$(JC) $(JFLAGS) src/bplus/MockBPlusTreeFacade.java
WEB-INF/classes/Servlet.class: src/Servlet.java
		$(JC) $(JFLAGS) src/Servlet.java
WEB-INF/classes/utils/statistics/StatisticsGenerator.class: src/utils/statistics/StatisticsGenerator.java
		$(JC) $(JFLAGS) src/utils/statistics/StatisticsGenerator.java
WEB-INF/classes/utils/statistics/Statistics.class: src/utils/statistics/Statistics.java
		$(JC) $(JFLAGS) src/utils/statistics/Statistics.java
WEB-INF/classes/utils/Constants.class: src/utils/Constants.java
		$(JC) $(JFLAGS) src/utils/Constants.java
WEB-INF/classes/SearchEngine.class: src/SearchEngine.java
		$(JC) $(JFLAGS) src/SearchEngine.java
WEB-INF/classes/Main.class: src/Main.java
		$(JC) $(JFLAGS) src/Main.java
WEB-INF/classes/index.class: src/index.java
		$(JC) $(JFLAGS) src/index.java
WEB-INF/classes/test/processor/TestStemmerProcessor.class: src/test/processor/TestStemmerProcessor.java
		$(JC) $(JFLAGS) src/test/processor/TestStemmerProcessor.java
WEB-INF/classes/test/files/StackFileTest.class: src/test/files/StackFileTest.java
		$(JC) $(JFLAGS) src/test/files/StackFileTest.java
WEB-INF/classes/test/files/SecuentialFileTest.class: src/test/files/SecuentialFileTest.java
		$(JC) $(JFLAGS) src/test/files/SecuentialFileTest.java
WEB-INF/classes/test/files/RelativelFileTest.class: src/test/files/RelativelFileTest.java
		$(JC) $(JFLAGS) src/test/files/RelativelFileTest.java
WEB-INF/classes/test/files/FileTest.class: src/test/files/FileTest.java
		$(JC) $(JFLAGS) src/test/files/FileTest.java
WEB-INF/classes/test/files/test.class: src/test/files/test.java
		$(JC) $(JFLAGS) src/test/files/test.java
WEB-INF/classes/test/files/BufferedRelativeFileTest.class: src/test/files/BufferedRelativeFileTest.java
		$(JC) $(JFLAGS) src/test/files/BufferedRelativeFileTest.java
WEB-INF/classes/test/index/TestMockDocumentsDictionary.class: src/test/index/TestMockDocumentsDictionary.java
		$(JC) $(JFLAGS) src/test/index/TestMockDocumentsDictionary.java
WEB-INF/classes/test/index/TestMockIndex.class: src/test/index/TestMockIndex.java
		$(JC) $(JFLAGS) src/test/index/TestMockIndex.java
WEB-INF/classes/test/index/TestLinkedBlocksManager.class: src/test/index/TestLinkedBlocksManager.java
		$(JC) $(JFLAGS) src/test/index/TestLinkedBlocksManager.java
WEB-INF/classes/test/index/TestDocumentsDictionary.class: src/test/index/TestDocumentsDictionary.java
		$(JC) $(JFLAGS) src/test/index/TestDocumentsDictionary.java
WEB-INF/classes/test/index/TestDefaultQueryEngine.class: src/test/index/TestDefaultQueryEngine.java
		$(JC) $(JFLAGS) src/test/index/TestDefaultQueryEngine.java
WEB-INF/classes/test/index/TestQueryEngineMocks.class: src/test/index/TestQueryEngineMocks.java
		$(JC) $(JFLAGS) src/test/index/TestQueryEngineMocks.java
WEB-INF/classes/test/index/TestDocumentsDictionaryImp.class: src/test/index/TestDocumentsDictionaryImp.java
		$(JC) $(JFLAGS) src/test/index/TestDocumentsDictionaryImp.java
WEB-INF/classes/test/index/TestIndexImp.class: src/test/index/TestIndexImp.java
		$(JC) $(JFLAGS) src/test/index/TestIndexImp.java
WEB-INF/classes/test/index/TestQueryEngine.class: src/test/index/TestQueryEngine.java
		$(JC) $(JFLAGS) src/test/index/TestQueryEngine.java
WEB-INF/classes/test/index/TestIndex.class: src/test/index/TestIndex.java
		$(JC) $(JFLAGS) src/test/index/TestIndex.java
WEB-INF/classes/test/bplus/TestBPlusTreeBoImp.class: src/test/bplus/TestBPlusTreeBoImp.java
		$(JC) $(JFLAGS) src/test/bplus/TestBPlusTreeBoImp.java
WEB-INF/classes/test/bplus/TestBPlusNodeDao.class: src/test/bplus/TestBPlusNodeDao.java
		$(JC) $(JFLAGS) src/test/bplus/TestBPlusNodeDao.java
WEB-INF/classes/test/bplus/BPlusTreeBoDaoTest.class: src/test/bplus/BPlusTreeBoDaoTest.java
		$(JC) $(JFLAGS) src/test/bplus/BPlusTreeBoDaoTest.java
WEB-INF/classes/test/bplus/TestBPlusTreeBoImpDaoTest.class: src/test/bplus/TestBPlusTreeBoImpDaoTest.java
		$(JC) $(JFLAGS) src/test/bplus/TestBPlusTreeBoImpDaoTest.java
WEB-INF/classes/test/bplus/TestBPlusNodeDaoTest.class: src/test/bplus/TestBPlusNodeDaoTest.java
		$(JC) $(JFLAGS) src/test/bplus/TestBPlusNodeDaoTest.java
WEB-INF/classes/test/bplus/TestBPlusNodeDaoImp.class: src/test/bplus/TestBPlusNodeDaoImp.java
		$(JC) $(JFLAGS) src/test/bplus/TestBPlusNodeDaoImp.java
WEB-INF/classes/test/bplus/BPlusNodeTestUtils.class: src/test/bplus/BPlusNodeTestUtils.java
		$(JC) $(JFLAGS) src/test/bplus/BPlusNodeTestUtils.java
WEB-INF/classes/test/bplus/TestBPlusTreeBoTest.class: src/test/bplus/TestBPlusTreeBoTest.java
		$(JC) $(JFLAGS) src/test/bplus/TestBPlusTreeBoTest.java
WEB-INF/classes/test/bplus/MapTest.class: src/test/bplus/MapTest.java
		$(JC) $(JFLAGS) src/test/bplus/MapTest.java
WEB-INF/classes/test/bplus/TestBPlusTreeBo.class: src/test/bplus/TestBPlusTreeBo.java
		$(JC) $(JFLAGS) src/test/bplus/TestBPlusTreeBo.java
WEB-INF/classes/test/persistors/TestBPlusNodePersistor.class: src/test/persistors/TestBPlusNodePersistor.java
		$(JC) $(JFLAGS) src/test/persistors/TestBPlusNodePersistor.java
WEB-INF/classes/test/persistors/TestPersistor.class: src/test/persistors/TestPersistor.java
		$(JC) $(JFLAGS) src/test/persistors/TestPersistor.java
WEB-INF/classes/test/persistors/TestIntegerPersistor.class: src/test/persistors/TestIntegerPersistor.java
		$(JC) $(JFLAGS) src/test/persistors/TestIntegerPersistor.java
WEB-INF/classes/test/persistors/TestStringPersistor.class: src/test/persistors/TestStringPersistor.java
		$(JC) $(JFLAGS) src/test/persistors/TestStringPersistor.java
WEB-INF/classes/test/persistors/TestBytePersistor.class: src/test/persistors/TestBytePersistor.java
		$(JC) $(JFLAGS) src/test/persistors/TestBytePersistor.java
WEB-INF/classes/test/utils/KeyCodificationTest.class: src/test/utils/KeyCodificationTest.java
		$(JC) $(JFLAGS) src/test/utils/KeyCodificationTest.java
WEB-INF/classes/test/utils/GammaDistancesBlockTest.class: src/test/utils/GammaDistancesBlockTest.java
		$(JC) $(JFLAGS) src/test/utils/GammaDistancesBlockTest.java
WEB-INF/classes/test/query/QueryTestCase.class: src/test/query/QueryTestCase.java
		$(JC) $(JFLAGS) src/test/query/QueryTestCase.java
WEB-INF/classes/test/query/QueryNotTest.class: src/test/query/QueryNotTest.java
		$(JC) $(JFLAGS) src/test/query/QueryNotTest.java
WEB-INF/classes/test/query/CompositeQueryTest.class: src/test/query/CompositeQueryTest.java
		$(JC) $(JFLAGS) src/test/query/CompositeQueryTest.java
WEB-INF/classes/test/query/ParserTest.class: src/test/query/ParserTest.java
		$(JC) $(JFLAGS) src/test/query/ParserTest.java
WEB-INF/classes/test/query/QueryAndTest.class: src/test/query/QueryAndTest.java
		$(JC) $(JFLAGS) src/test/query/QueryAndTest.java
WEB-INF/classes/test/query/MockQuery.class: src/test/query/MockQuery.java
		$(JC) $(JFLAGS) src/test/query/MockQuery.java
WEB-INF/classes/test/query/QueryOrTest.class: src/test/query/QueryOrTest.java
		$(JC) $(JFLAGS) src/test/query/QueryOrTest.java
WEB-INF/classes/ControllerServlet.class: src/ControllerServlet.java
		$(JC) $(JFLAGS) src/ControllerServlet.java
WEB-INF/classes/linkedblocks/LinkedBlocksManager.class: src/linkedblocks/LinkedBlocksManager.java
		$(JC) $(JFLAGS) src/linkedblocks/LinkedBlocksManager.java
WEB-INF/classes/linkedblocks/codification/GammaDistancesBlock.class: src/linkedblocks/codification/GammaDistancesBlock.java
		$(JC) $(JFLAGS) src/linkedblocks/codification/GammaDistancesBlock.java
WEB-INF/classes/linkedblocks/utils/KeyCodificationUtils.class: src/linkedblocks/utils/KeyCodificationUtils.java
		$(JC) $(JFLAGS) src/linkedblocks/utils/KeyCodificationUtils.java
WEB-INF/classes/linkedblocks/keys/DocumentIndexKey.class: src/linkedblocks/keys/DocumentIndexKey.java
		$(JC) $(JFLAGS) src/linkedblocks/keys/DocumentIndexKey.java
WEB-INF/classes/signaturefiles/hash/JSHash.class: src/signaturefiles/hash/JSHash.java
		$(JC) $(JFLAGS) src/signaturefiles/hash/JSHash.java
WEB-INF/classes/signaturefiles/hash/PJWHash.class: src/signaturefiles/hash/PJWHash.java
		$(JC) $(JFLAGS) src/signaturefiles/hash/PJWHash.java
WEB-INF/classes/signaturefiles/hash/BPHash.class: src/signaturefiles/hash/BPHash.java
		$(JC) $(JFLAGS) src/signaturefiles/hash/BPHash.java
WEB-INF/classes/signaturefiles/hash/Hash.class: src/signaturefiles/hash/Hash.java
		$(JC) $(JFLAGS) src/signaturefiles/hash/Hash.java
WEB-INF/classes/signaturefiles/hash/DEKHash.class: src/signaturefiles/hash/DEKHash.java
		$(JC) $(JFLAGS) src/signaturefiles/hash/DEKHash.java
WEB-INF/classes/signaturefiles/hash/SDBMHash.class: src/signaturefiles/hash/SDBMHash.java
		$(JC) $(JFLAGS) src/signaturefiles/hash/SDBMHash.java
WEB-INF/classes/signaturefiles/hash/ELFHash.class: src/signaturefiles/hash/ELFHash.java
		$(JC) $(JFLAGS) src/signaturefiles/hash/ELFHash.java
WEB-INF/classes/signaturefiles/hash/DJBHash.class: src/signaturefiles/hash/DJBHash.java
		$(JC) $(JFLAGS) src/signaturefiles/hash/DJBHash.java
WEB-INF/classes/signaturefiles/hash/RSHash.class: src/signaturefiles/hash/RSHash.java
		$(JC) $(JFLAGS) src/signaturefiles/hash/RSHash.java
WEB-INF/classes/signaturefiles/hash/FNVHash.class: src/signaturefiles/hash/FNVHash.java
		$(JC) $(JFLAGS) src/signaturefiles/hash/FNVHash.java
WEB-INF/classes/signaturefiles/hash/APHash.class: src/signaturefiles/hash/APHash.java
		$(JC) $(JFLAGS) src/signaturefiles/hash/APHash.java
WEB-INF/classes/signaturefiles/hash/BKDRHash.class: src/signaturefiles/hash/BKDRHash.java
		$(JC) $(JFLAGS) src/signaturefiles/hash/BKDRHash.java
WEB-INF/classes/signaturefiles/utils/SignatureUtils.class: src/signaturefiles/utils/SignatureUtils.java
		$(JC) $(JFLAGS) src/signaturefiles/utils/SignatureUtils.java
WEB-INF/classes/signaturefiles/SignatureGenerator.class: src/signaturefiles/SignatureGenerator.java
		$(JC) $(JFLAGS) src/signaturefiles/SignatureGenerator.java
WEB-INF/classes/TreeDumper.class: src/TreeDumper.java
		$(JC) $(JFLAGS) src/TreeDumper.java


