#include "term.h"
#include "kmap.h"
#include <iostream>

int main()
{
	Kmap k1;
	k1.GetVal();
	k1.MapPrint();
	k1.GetMin2();
	//k1.MinTable2Print(); /*Used for Debugging*/
	k1.GetMin4();
	k1.GetMin8();
	k1.PrintExp();
	}

