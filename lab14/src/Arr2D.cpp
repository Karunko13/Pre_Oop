#include "Arr2D.h"

Arr2D::Arr2D()
{
	rows=0;
	columns=0;
}
Arr2D::Arr2D(int a,int b)
{
	tab=new int*[a];
	for(int i=0;i<a;i++)
	{
		tab[i]=new int [b];
		
	}
	
}

Arr2D::Arr2D(const Arr2D&)
{

}
Arr2D::Arr2D(int **a,int b,int c)
{		
		tab=a;
		rows=b;
		columns=c;
}


Arr2D::~Arr2D()
{

}
//a wiersze, b kolumny
Arr2D Arr2D::adopt(int *tab,int a,int b)
{
	int **temp=new int*[a];
	for(int i=0;i<a;i++)
	{
		temp[i]=new int [b];
	}
	int x=0;
	//przejscie po calej tablicy i zapełnienie jej elementami z tab
	for(int i=0; i<a; i++)
	{
		for(int j=0; j<b; j++)
		{
			temp[i][j]=tab[x];
			x++;
		}
	}
	return Arr2D(temp,a,b);
}


int* Arr2D::operator [](int x)
{	
return tab[x];
}


void Arr2D::print() const
{
	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<columns; j++)
		{
			cout<<tab[i][j]<<" ";
		}
	}
}

void operator <<=(const char* lewo,const Arr2D& arr)
{
	cout<<lewo<<endl;

	for(int i=0;i<arr.rows;i++)
	{
		for(int j=0;j<arr.columns;j++)
			cout << arr.tab[i][j] << " ";
		cout << endl;
	}
	cout << lewo << endl;
}
