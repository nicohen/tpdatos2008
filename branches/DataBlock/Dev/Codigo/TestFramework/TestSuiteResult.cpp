#include "StdAfx.h"
#include "TestSuiteResult.h"

TestSuiteResult::TestSuiteResult(int failedTests )
{
	printf("::::::::::::::::::::::::::::::::::\n");
	printf(":::Tests::::::::::::::::::::::::::\n");
	printf("::::::::::::::::::::::::::::::::::\n");
	if(failedTests>0){
		printf("!!!!!!FAILED %i TEST/S !!!!!!!!!!\n",failedTests);
	}else{
		printf("Ok\n");		
	}
	printf("::::::::::::::::::::::::::::::::::\n");
}

TestSuiteResult::~TestSuiteResult(void)
{
}
