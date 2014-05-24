#include <iostream>
#include <stdio.h>
#include <bitset>
#include <climits>

using namespace std;
typedef std::bitset<4> FourBit;
void PrintMinTerm(FourBit, FourBit); 
int main(){
	int a=0,b=2;
	bool comp_test;
	FourBit x(a);
	FourBit y(b);
	FourBit l(~a);
	FourBit m(~b);
	FourBit p(a&b);
	FourBit q((~a)&(~b));
	if(!(p.none()))
	{
		cout<<"Min valid non compliment"<<endl;
	}
	if(!(q.none()))
	{
		cout<<"Min valid compliment"<<endl;
		
	}
	PrintMinTerm(p,q);
	std::cout<<"a "<<a<<" "<< x<<endl;
	std::cout<<"b "<<b<<" "<< y<<endl;
	std::cout<<"~a "<<a<<" "<< l<<endl;
	std::cout<<"~b "<<b<<" "<< m<<endl;
	std::cout<<"a&b "<< p<<endl;
	std::cout<<"~a&~b "<< q<<endl;
	return 0;
	}
	
	
void PrintMinTerm(FourBit a, FourBit b) 
{
	for(int i=3;i>=0;i--)
	{
		if(a[i])
		{
		cout<<"X"<<i;
		}
		if(b[i])
		{
		cout<<"X"<<i<<"'";
		}
	}
}
