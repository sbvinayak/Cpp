#include "kmap.h"
#include <iostream>
using namespace std;

Kmap::Kmap()
{
	for(int i=0;i<16;i++)
	t[i].SetVal(0,i);
	m2 = NULL;
	m4 = NULL;
	m1=NULL;
	m8=NULL;
	}

Kmap::~Kmap()
{}

void Kmap::MinInsert(int p)
{
	t[p].SetVal(1,p);
	MinTable1Add(p);
	}

void Kmap::MapPrint()
{
	cout<<"Kmap:"<<endl;
	t[0].TermPrint();t[1].TermPrint();t[3].TermPrint();t[2].TermPrint();cout<<endl;
	t[4].TermPrint();t[5].TermPrint();t[7].TermPrint();t[6].TermPrint();cout<<endl;
	t[12].TermPrint();t[13].TermPrint();t[15].TermPrint();t[14].TermPrint();cout<<endl;
	t[8].TermPrint();t[9].TermPrint();t[11].TermPrint();t[10].TermPrint();cout<<endl;
	cout<<endl;
	}

void Kmap::GetVal()
{
	int i,num_terms=1;
	cout<<"Enter number of min terms:";
	cin>>num_terms;
	cout<<"Enter the terms 0-15"<<endl;
	while(num_terms)
	{
	cin>>i;
	MinInsert(i);
	num_terms--;
	}
}

void Kmap::GetMin2()
{
	for(int i=0;i<15;i++)
	{
		for(int j=i+1;j<16;j++)
		{
			if(t[i].RetVal() && t[j].RetVal())
			{
					FourBit p(i&j);
					FourBit q((~i)&(~j));
					int count;
					count = p.count() + q.count();
					//cout<<"Count: "<<count<<endl; /*Used for Debugging*/
					if( count == 3 ) 
					{	
						MinTable1Delete(i,j,&m1);
						MinTable2Add(i,j);
					//	PrintMinTerm(p,q); /*Used for Debugging*/
					}
			}
		}
	}
}	

void Kmap::GetMin4()
{
	for(int i=0;i<13;i++)
	{
		for(int j=i+1;j<14;j++)
		{
			for(int k=j+1;k<15;k++)
			{
				for(int l=k+1;l<16;l++)
				{
				if(t[i].RetVal() && t[j].RetVal() && t[k].RetVal() && t[l].RetVal() )
					{
					FourBit p( (i) & (j) & (k) & (l) );
					FourBit q( (~i) & (~j) & (~k) & (~l) );
					int count;
					count = p.count() + q.count();
					//cout<<"GetMin4 Count: "<<count<<endl; /*Used for Debugging*/
					if( count == 2 ) 
						{
						MinTable2Delete(i,j,k,l,&m2);
						MinTable4Add(i,j,k,l);
					//	PrintMinTerm(p,q);   /*Used for Debugging*/
						
						}
					}
				}
			}
		}
	}
	
}


void Kmap::GetMin8()
{
	int i[8],b=0;bool valcheck = 1;
	for(i[0]=0	   ;i[0]<9;i[0]++)
	{
	for(i[1]=i[0]+1;i[1]<10;i[1]++)
	{
	for(i[2]=i[1]+1;i[2]<11;i[2]++)
	{
	for(i[3]=i[2]+1;i[3]<12;i[3]++)
	{
	for(i[4]=i[3]+1;i[4]<13;i[4]++)
	{
	for(i[5]=i[4]+1;i[5]<14;i[5]++)
	{
	for(i[6]=i[5]+1;i[6]<15;i[6]++)
	{
	for(i[7]=i[6]+1;i[7]<16;i[7]++)
	{
		for(b=0;b<8;b++)
		{
			if(t[i[b]].RetVal())
			{ valcheck = (valcheck)&&(t[i[b]].RetVal());
			}
			else 
			{
			valcheck = 0;
			break;	
			}
		}
		if(valcheck)
		{
			FourBit p( i[0] & i[1] & i[2] & i[3] & i[4] & i[5] & i[6] & i[7]);
			FourBit q( (~i[0]) & (~i[1]) & (~i[2]) & (~i[3]) & (~i[4]) & (~i[5]) & (~i[6]) & (~i[7]) );
			int count;
			count = p.count() + q.count();
			//cout<<"GetMin8 Count: "<<count<<endl; /*Used for Debugging*/
			if( count == 1 ) 
			{
				MinTable4Delete(i,&m4);
				MinTable8Add(i);
			//	PrintMinTerm(p,q);   /*Used for Debugging*/
			}
		}
		valcheck = 1;
	}}}}}}}}
}


/*****************************************
 Min table Add functions
 *****************************************/
void Kmap::MinTable1Add(int a)
{
	min1list k = new min1list_;
	k->head = new min1_;
	k->head->a = a;
	k->tail = NULL;
	
	min1list temp = m1;
	
	if(!(m1))
	{
		m1 = k;
	}
	else
	{
		while(temp->tail)
		{
			temp = temp->tail;
		}
		temp->tail = k;
		
	}
	
}


void Kmap::MinTable2Add(int a, int b)
{
	//cout<<"Fine here";
	min2list k= new min2list_;
	//cout<<k<<endl<<(k->head)<<endl;
	k->head = new min2_;
	k->head->a[0] = a;
	k->head->a[1] = b;
	//cout << (k->head->a[0]) <<" "<<(k->head->a[1])<<" ";
	k->tail = NULL;
	
	min2list temp = m2;
	if(!(m2))
	{
		m2 = k;
	}
	else
	{
		while(temp->tail)
		{
			temp = temp->tail;
		}
		temp->tail = k;
		
	}
	
}

void Kmap::MinTable4Add(int a, int b, int c, int d )
{
	//cout<<"Fine here";
	min4list k= new min4list_;
	//cout<<k<<endl<<(k->head)<<endl;
	k->head = new min4_;
	k->head->a[0] = a;
	k->head->a[1] = b;
	k->head->a[2] = c;
	k->head->a[3] = d;
	
	//cout << (k->head->a[0]) <<" "<<(k->head->a[1])<<" ";
	k->tail = NULL;
	
	min4list temp = m4;
	if(!(m4))
	{
		m4 = k;
	}
	else
	{
		while(temp->tail)
		{
			temp = temp->tail;
		}
		temp->tail = k;
		
	}
	
}

void Kmap::MinTable8Add(int arr[] )
{
	//cout<<"Fine here";
	min8list k= new min8list_;
	//cout<<k<<endl<<(k->head)<<endl;
	k->head = new min8_;
	for (int i=0 ; i<8; i++)
	{	k->head->a[i] = arr[i];}
	//cout << (k->head->a[0]) <<" "<<(k->head->a[1])<<" ";
	k->tail = NULL;
	
	min8list temp = m8;
	if(!(m8))
	{
		m8 = k;
	}
	else
	{
		while(temp->tail)
		{
			temp = temp->tail;
		}
		temp->tail = k;
		
	}
	
}

/*****************************************
 Min table delete functions
 *****************************************/
void Kmap::MinTable1Delete(int a, int b, min1list *mlist )
{
	min1list *next, *prev;
	next=mlist;
	prev=NULL;
	int x[2] = {a,b};
	int flag;
	
	while((*next)!=NULL)
	{
		flag = 0;
		for( int i = 0; i<2;i++)
		{ 
		if((*next)->head->a == x[i]) flag = 1;
		}
		if(flag)
		{
			//cout<<"Deleting "<<(*next)->head->a<<" "<<endl;
			
			if((*next)->tail==NULL){//cout<<"Last Element"<<endl;
			}
			
			//printf("reached here 2\n");
			if(prev==NULL && (*next)->tail==NULL)
			{
				//cout<<"The only element"<<endl;
				(*next)=NULL;
			}
			else
			{
				if(prev==NULL)
				{
				//Removing the first element in the min table
				(*mlist)=(*next)->tail;
				}
				else
				{
				//Removing an entry in the middle/end
				(*prev)->tail=(*next)->tail;
				}
			}
			

		}
		else
		{	prev=next;
			next=&((*next)->tail);
		}
	}
	
}

 
 
void Kmap::MinTable2Delete(int a, int b, int c, int d, min2list *mlist )
{
	min2list *next, *prev;
	next=mlist;
	prev=NULL;
	int x[4] = {a,b,c,d};
	int flag[2] ;
	
	while((*next)!=NULL)
	{
		flag[0] = 0; flag[1] = 0;
		for( int i = 0; i<4;i++)
		{ 
		if((*next)->head->a[0] == x[i]) flag[0] = 1;
		if((*next)->head->a[1] == x[i]) flag[1] = 1;
		}
		if(flag[0] && flag[1])
		{
			//cout<<"Deleting "<<(*next)->head->a[0]<<" "<<(*next)->head->a[1]<<endl;
			
			if((*next)->tail==NULL){//cout<<"Last Element"<<endl;
			}
			
			//printf("reached here 2\n");
			if(prev==NULL && (*next)->tail==NULL)
			{
				//cout<<"The only element"<<endl;
				(*next)=NULL;
			}
			else
			{
				if(prev==NULL)
				{
				//Removing the first element in the min table
				(*mlist)=(*next)->tail;
				}
				else
				{
				//Removing an entry in the middle/end
				(*prev)->tail=(*next)->tail;
				}
			}
			

		}
		else
		{	prev=next;
			next=&((*next)->tail);
		}
	}
	
}


void Kmap::MinTable4Delete(int arr[], min4list *mlist )
{
	min4list *next, *prev;
	next=mlist;
	prev=NULL;
	int flag[4] ;
	
	while((*next)!=NULL)
	{
		for(int i=0;i< 4;i++)
		{
		flag[i] = 0;
		}
		for( int i=0;i<8;i++)
		{ 
		if((*next)->head->a[0] == arr[i]) flag[0] = 1;
		if((*next)->head->a[1] == arr[i]) flag[1] = 1;
		if((*next)->head->a[2] == arr[i]) flag[2] = 1;
		if((*next)->head->a[3] == arr[i]) flag[3] = 1;
		}
		if(flag[0] && flag[1] && flag[2] && flag[3])
		{
			//cout<<"Deleting "<<(*next)->head->a[0]<<" "<<(*next)->head->a[1]<<endl;
			
			if((*next)->tail==NULL){//cout<<"Last Element"<<endl;
			}
			
			//printf("reached here 2\n");
			if(prev==NULL && (*next)->tail==NULL)
			{
				//cout<<"The only element"<<endl;
				(*next)=NULL;
			}
			else
			{
				if(prev==NULL)
				{
				//Removing the first element in the min table
				(*mlist)=(*next)->tail;
				}
				else
				{
				//Removing an entry in the middle/end
				(*prev)->tail=(*next)->tail;
				}
			}
			

		}
		else
		{	prev=next;
			next=&((*next)->tail);
		}
	}
	
}

/*****************************************
 Min table prints
 *****************************************/
void Kmap::MinTable2Print()
{
	min2list temp = m2;
	while(temp)
		{
			cout<<( temp->head->a[0] )<<" "<<( temp->head->a[1] )<<endl;
			temp = temp->tail;
		}
		
}
	
void Kmap::MinTable4Print()
{
	min4list temp = m4;
	while(temp)
		{
			for(int i = 0;i<4;i++) cout<<( temp->head->a[i] )<<" ";
			cout<<endl;
			temp = temp->tail;
		}
		
}
/*****************************************
 Min term prints
 *****************************************/

void Kmap::PrintMinTerm(FourBit a, FourBit b) 
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

void Kmap::PrintExp() 
{
	cout<<"Min expression : ";
	min1list temp1 = m1;
	min2list temp2 = m2;
	min4list temp4 = m4;
	min8list temp8 = m8;
	//cout<<"PrintExp2"<<endl;
	while (temp1!=NULL)
	{
		//cout<<"PrintExp3"<<endl;
		FourBit x(temp1->head->a);
		FourBit y( ~(temp1->head->a) );
		//cout<<"PrintExp4"<<endl;
		PrintMinTerm(x,y);
		if(temp1->tail)cout<<" + ";
		temp1 = temp1->tail;
		//cout<<"PrintExp5"<<endl;
		
	}
	if ( (m1!=NULL) && (temp2!=NULL))cout<<" + ";
	while (temp2!=NULL)
	{
		//cout<<"PrintExp3"<<endl;
		FourBit x(temp2->head->a[0] & temp2->head->a[1]);
		FourBit y( ~(temp2->head->a[0]) & ~(temp2->head->a[1]) );
		//cout<<"PrintExp4"<<endl;
		PrintMinTerm(x,y);
		if(temp2->tail)cout<<" + ";
		temp2 = temp2->tail;
		//cout<<"PrintExp5"<<endl;
		
	}
	
	if ( ((m1!=NULL)||(m2!=NULL))&&(temp4!=NULL) ) cout<<" + ";
	while (temp4!=NULL)
	{
		//cout<<"PrintExp3b"<<endl;
		FourBit x(temp4->head->a[0] & temp4->head->a[1] & temp4->head->a[2] & temp4->head->a[3]);
		FourBit y( ~(temp4->head->a[0]) & ~(temp4->head->a[1]) & ~(temp4->head->a[2]) & ~(temp4->head->a[3]) );
		PrintMinTerm(x,y);
		if(temp4->tail)cout<<" + ";
		temp4 = temp4->tail;
	}
	
	if ( ((m1!=NULL)||(m2!=NULL)||(m4!=NULL))&&(temp8!=NULL) ) cout<<" + ";
	while (temp8!=NULL)
	{
		//cout<<"PrintExp3b"<<endl;
		FourBit x(temp8->head->a[0] & temp8->head->a[1] & temp8->head->a[2] & temp8->head->a[3] & temp8->head->a[4] & temp8->head->a[5] & temp8->head->a[6] & temp8->head->a[7] ) ;
		FourBit y( ~(temp8->head->a[0]) & ~(temp8->head->a[1]) & ~(temp8->head->a[2]) & ~(temp8->head->a[3]) & ~(temp8->head->a[4]) & ~(temp8->head->a[5]) & ~(temp8->head->a[6]) & ~(temp8->head->a[7]) );
		PrintMinTerm(x,y);
		if(temp8->tail)cout<<" + ";
		temp8 = temp8->tail;
	}
	
	cout<<endl;
}


