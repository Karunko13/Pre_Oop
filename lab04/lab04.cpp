#include "lab04.h"

void printSequence(const double*sekwencja,int rozmiar)
{

	if(rozmiar>0)
	{
		std::cout<<"(";
		for(int i=0;i<rozmiar;i++)
		{
			std::cout<<sekwencja[i]<<",";
		}
		std::cout<<"\b)\n";
	}
	else 
	{
	std::cout<<"Nothing to print.";
	return;
	}

}

 double*  initGeometricalSequence(double pierwszy , double liczba, int rozmiar )
 {
	 if(rozmiar==0)
	 {
		 std::cout<<"Nothing to print.\n";
	 }

	 else{
		double *tab=(double*)malloc(sizeof(double)*rozmiar);
		tab[0]=pierwszy;
		for(int i=1;i<rozmiar;i++)
		{
			tab[i]=tab[i-1]*liczba;
		}
		return tab;
	 }
	 
 }

void initCounter(int *x)
{
	if(*x==0 || *x<0)
	{
		std::cout<<"Size must be non-zero(and postivite)";
	}
}

double* initArithmeticSequence(double pierwszy ,double liczba ,int rozmiar)
{
	double *tablica=(double*)malloc(sizeof(double)*rozmiar);
	tablica[0]=pierwszy;
	for(int i=1;i<rozmiar; i++)
	{
		tablica[i]=tablica[i-1]+liczba;
	}
	return tablica;
}

void addSequence(const double ***, double **, double*,int)
{
}

void deleteSequence(const double**sekwencja)
{
	if(*sekwencja != NULL)
	{
		free((void*)*sekwencja);
		*sekwencja=NULL;
		std::cout<<"Sequence deleted.\n";
	}
	else{
		std::cout<<"Nothing to delete.\n";
	}
}

void printAllSequences(const double**,double*)
{
}


void deleteAllSequences(const double**,double*)
{
}

