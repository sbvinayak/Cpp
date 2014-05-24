#ifndef _KMAP_H_
#define _KMAP_H_

#include <iostream>
#include "term.h"
#include <bitset>
#include <climits>

typedef std::bitset<4> FourBit;
typedef struct min1_ *min1;
typedef struct min2_ *min2;
typedef struct min4_ *min4;
typedef struct min8_ *min8;
typedef struct min1list_ *min1list;
typedef struct min2list_ *min2list;
typedef struct min4list_ *min4list;
typedef struct min8list_ *min8list;

	struct min1_
	{
		int a;
	};
	struct min2_ 
	{
		int a[2];
	};
	struct min4_ 
	{
		int a[4];
	};
	struct min8_ 
	{
		int a[8];
	};
	
	struct min1list_
	{
		min1 head;
		min1list tail;
	};

	struct min2list_
	{
		min2 head;
		min2list tail;
	};
	
	struct min4list_
	{
		min4 head;
		min4list tail;
	};

	struct min8list_
	{
		min8 head;
		min8list tail;
	};

class Kmap
{
private:
	Term t[16];
	min1list m1;
	min2list m2;
	min4list m4;
	min8list m8;

public:
	Kmap();
	~Kmap();				//Impilicit Destructor declared here
	void MinInsert(int p); 	//Inserts minterms in the respective position
	void MapPrint();
	void GetVal();
	void GetMin2();
	void GetMin4();
	void GetMin8();
	void MinTable1Add(int a);
	void MinTable2Add(int a, int b);
	void MinTable4Add(int a, int b, int c, int d );
	void MinTable8Add(int arr[] );
	void MinTable1Delete(int a, int b, min1list *mlist );
	void MinTable2Delete(int a, int b, int c, int d, min2list *mlist );
	void MinTable4Delete(int arr[], min4list *mlist );
	void MinTable2Print();
	void MinTable4Print();
	void PrintMinTerm(FourBit a, FourBit b) ;
	void PrintExp() ;
};

#endif
