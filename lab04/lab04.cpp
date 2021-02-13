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
	std::cout<<"\bNothing to print.\n";
	return;
	}

}

 double*  initGeometricalSequence(double pierwszy , double liczba, int rozmiar )
 {
	 //if(rozmiar==0)
	 //{
	//	 std::cout<<"Nothing to print.\n";
	// }

	 
		double *tab=(double*)malloc(sizeof(double)*rozmiar);
		tab[0]=pierwszy;
		for(int i=1;i<rozmiar;i++)
		{
			tab[i]=tab[i-1]*liczba;
		}
		return tab;
	 
	
 }

void initCounter(int *x)
{
	if(*x==0 || *x<0)
	{
		std::cout<<"Size must be non-zero(and postivite)\n";
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

void addSequence(const double*** list, double** listLength, double* tab, int size){
   //int sizeOfList=(size/3)+1;
   static int sizeOfList=1;
  if(sizeOfList==1){
  list=(const double*)malloc(sizeof(double*)*sizeOfList);
  listLength=(double)malloc(sizeof(double)*sizeOfList);
  }
  else{
    list=(const double*)realloc(list,sizeof(double)*sizeOfList);
  listLength=(double)realloc(*listLength,sizeof(double)*sizeOfList);
  }
  (*listLength)[sizeOfList-1]=size;
  (*list)[sizeOfList-1]=tab;

  

  sizeOfList++;
}
void printAllSequences(const double** list, double* listLenght){
  for(int i=0;i<6;i++){
   printSequence(list[i],(int)listLenght[i]);
  }
}
void deleteAllSequences (const double** list, double* tab){
free(list);
free(tab);
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


