#include "lab03.h"

void printArray(myArray tablica){
	if(tablica.N>0)
	{
			std::cout<<"[";
			for(int i=0; i<tablica.N ;i++)
			{
				std::cout<<tablica.tab[i]<<",";
			}
			std::cout<<"\b]";

	}
	else
	{
		std::cout<<"Cannot print empty array.\n";
	}
}

int fib(int dlugosc){
	if(dlugosc<2)
		{
			return 1;
		}
	if(dlugosc<0)
	{
		std::cout<<"Dlugosc cant be <0\n";
		return 0;
	}
	return fib(dlugosc-1)+fib(dlugosc-2);
}

bool fillArrayWithFibonacci(myArray *struktura,int dlugosc)
{
		if(struktura==nullptr)
		{
			std::cout<<"Empty pointer provided. \n";
			return 0;
		}
		if(dlugosc<=0 || dlugosc>ROZMIAR)
		{
			std::cout<<"Wrong number of dimensions.\n";
			return false;
		}

		struktura->N=dlugosc;
		for(int i=0; i<dlugosc; i++)
		{
			struktura->tab[i]=fib(i);
		}
		return true;
}

void extend(myArray *struktura,int dodaj)
{
	if(dodaj+struktura->N>ROZMIAR)
	{
		printf("Wow, you've just gone crazy(%d>%d).\n",dodaj+struktura->N,ROZMIAR );
		return;
	}

	struktura->N=struktura->N+dodaj;
	printArray(*struktura);
	std::cout<<"(extending by "<<dodaj<<" done\n)";
}

void truncate(myArray *struktura,int obetnij)
{
	if(struktura->N-obetnij<0)
	{
		std::cout<<"dlugosc<0\n";
		return;
	
	}
	struktura->N=struktura->N-obetnij;
	printArray(*struktura);
	printf("(truncation by %d done)\n",obetnij);
}

void revert(myArray *struktura)
{
	int a; //przechowuje tymczasowa wartosc, potrzebna do revert
	int x=(struktura->N/2);

	for(int i=0 ;i<x; i++)
	{
		a=struktura->tab[i];
		struktura->tab[i]=struktura->tab[struktura->N-1-i];
		struktura->tab[struktura->N-1-i]=a;
	}
	printArray(*struktura);
	std::cout<<"(reverting done)\n";
}

void marry(myArray *X,myArray *Y)
{
	if(X==Y)
	{
		std::cout<<"Can't marry myself.\n";
		return;
	}
  int blizniak=0;
	if(X->N==Y->N)
	{
		
		for(int i=0; i<X->N; i++)
		{
			if(X->tab[i]==Y->tab[i])
			blizniak=1;

		}
	if(blizniak)
	{
		std::cout<<"Can't marry my twin.\n";
	}
	else
	{
	X->malzonek=Y;
	Y->malzonek=X;
	}
	return;

	}
	X->malzonek=Y;
	Y->malzonek=X;
}
void checkArraySpouse(myArray* struktura)
{
	if(struktura->malzonek==NULL)
	{
		printArray(*struktura);

		std::cout<<"has no spouse.\n";
	}
	else{
		printArray(*struktura);
		std::cout<<"is parried with";
		printArray(*(struktura->malzonek));
		std::cout<<"\n";
	}
}
void divorce(myArray *X, myArray*Y)
{
	X->malzonek=NULL;
	Y->malzonek=NULL;
}
void printParents(myArray *struktura)
{
	if(struktura->rodzic1==NULL)
	{
		printArray(*struktura);
		std::cout<<"has no parents.\n";
	}
	else{
		std::cout<<"Parents of";
		printArray(*struktura);
		std::cout<<"are";
		printArray(*(struktura->rodzic1));
		std::cout<<"and";
		printArray(*(struktura->rodzic2));
	}
}

myArray formChild(myArray *X,myArray *Y)
{
	myArray Z;//dziecko
	if(X==nullptr && Y==nullptr)
	{
		std::cout<<"I ain't God.\n";
		return Z;//aby potem dostac komunikat ze Z jest puste
	}
	if(X==nullptr || Y==nullptr)
	{
		std::cout<<"No partenogenesis possible.\n";
		return Z;
	}
	if(X->malzonek==Y && Y->malzonek==X)
	{
		if(X->N+Y->N>ROZMIAR)
		{
			std::cout<<"too many dimensions";
			return Z;
		}
		else{
			Z.N=X->N+Y->N;
			for(int i=0;i<X->N;i++)
			{
				Z.tab[i]=X->tab[i];
			}
			for(int i=0; i<Y->N;i++)
			{
				Z.tab[X->N+i]=Y->tab[i];
			}	
			Z.rodzic1=X;
			Z.rodzic2=Y;


		}

	}
	else{

		std::cout<<"Only spouses may have children.\n";
	}
	return Z;
}