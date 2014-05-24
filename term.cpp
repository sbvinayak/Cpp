#include "term.h"
#include <iostream>
using namespace std;
//Class constructor
Term::Term(bool initf, int initpos)
{
	f=initf;
	pos=initpos;
	}
	
Term::Term()
{
	f=0;
	pos=0;
	}

Term::~Term()
{}


void Term::SetVal(bool initf, int initpos)
{
	f=initf;
	pos=initpos;
	}

void Term::TermPrint()
{
	cout<<f<<" ";
	}

int Term::RetVal()
{
	return f;
	}
