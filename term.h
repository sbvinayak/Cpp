#ifndef _TERM_H_
#define _TERM_H_
#include <iostream>

class Term
{
private :
	bool f;
	int pos;
public:
	Term();									//Default Constructor
	Term(bool initf, int initpos);			//Parameterized Constructor
	~Term(); 								//Impilicit Destructor declared
	void SetVal(bool initf, int initpos); 	//Value is set here
	void TermPrint();
	int RetVal();
};

#endif
