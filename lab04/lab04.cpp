#include "lab04.h"
#include <stdlib.h>
#include <iostream>


void printSequence(const double*ciag , int size)
{
  (*wsk_nPrints)++;

 if(size<=0 || !(ciag)) 
  {
    std::cout << "Nothing to print." << std::endl;
    return;
  }
  else 
  {
    printf("(");
      for (int i=0;i<size;i++)
      {
        std::cout<<ciag[i]<<", ";
      }
      printf("\b\b)\n");
  }
}

double* initGeometricalSequence(double start, double q, int size)
{
  if (size == 0)
  {
    puts("Size must be non-zero (and positive)");
    return  NULL;
  }

  double *wsk = (double*) malloc(size*sizeof(double));

  if(wsk == NULL)
  {
    puts("ERROR wsk");
    exit(1);
  }

  
  wsk[0]=start;
  for(int i=1; i<size; i++)
  {
      wsk[i]= wsk[i-1]*q;
  }
  return wsk;
}

void initCounter(int* x)
{
  wsk_nPrints =x;
}

double* initArithmeticSequence(double start, double r, int size)
{
  if (size <= 0)
  {
    puts("Size must be non-zero (and positive)");
    return  NULL;
  }

  double *wsk = (double*)malloc(size*sizeof(double));

  if(wsk == NULL)
  {
    puts("ERROR wsk");
    exit(1);
  }

  *wsk = start;
  for(int i=1; i<size; i++)
  {
      wsk[i]= wsk[i-1] + r;
  }
  return wsk;
}

void addSequence(double const ***lista_ciagow,  double **lista_dlugosci, double const* ciag, int roz)
{
    
    *lista_dlugosci=(double*) realloc(*lista_dlugosci, (count+1) * sizeof(double*));
    (*lista_dlugosci)[count] = roz;

    *lista_ciagow=(const double**) realloc(*lista_ciagow, (count+1) * sizeof(const double**));
    (*lista_ciagow)[ count] = ciag;

    count++;
}


void deleteSequence(const double**list)
{

  if(!(*list))
  {
    std::cout << "Nothing to delete." << std::endl;
    return;
  }

  free( (double*)*list );
  *list=NULL;

  std::cout << "Sequence deleted." << std::endl;
}



void printAllSequences(const double **list, double *dlugosci)
{
  for(int j=0;j<6;j++)
  {
    printSequence( list[j], (int)dlugosci[j] );
  }
}

void deleteAllSequences(const double **list, double *dlugosci)
{
  for(int j=0;j<count;j++)
    {
      deleteSequence( list+count);
      free( (double*)list[count] );
    }
  free(list);
  free(dlugosci);
  dlugosci = NULL;
}