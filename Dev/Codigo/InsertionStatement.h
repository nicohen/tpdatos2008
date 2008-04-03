#ifndef INSERTIONSTATEMENT_H_
#define INSERTIONSTATEMENT_H_
#include "Statement.h"
#include "DataValue.h"
#include <vector>

class InsertionStatement: public Statement {

	private:
		std::vector<DataValue*>* _values;
	public:
		//Constructores y destructores 
		InsertionStatement(char* fileName);
		virtual ~InsertionStatement();
			
		//Getters
		std::vector<DataValue*>* getValues();
		
		//Otros metodos
		void addValue(DataValue* aValue);
		void InsertionStatement::clearValues(vector<DataValue*>* values);
		virtual void execute(void* anIDataManager, OutPutter* anOutputter);
		
};

#endif /*INSERTIONSTATEMENT_H_*/
