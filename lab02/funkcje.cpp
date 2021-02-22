#include "lab02.h"

void printVec(vecM *tablica){
  if(tablica->N>0)
  {
      std::cout<<"[";
      for(int i=0; i<tablica->N ;i++)
      {
        std::cout<<tablica->tab[i]<<",";
      }
      std::cout<<"\b]";

  }
  else
  {
    std::cout<<"Cannot print empty vector.\n";
  }
}
bool fillVecWithFibonacci(vecM* wektor, int dlugosc)
{
  if(wektor==nullptr)
    {
      std::cout<<"Empty pointer provided. \n";
      return 0;
    }
    if(dlugosc<=0 || dlugosc>ROZMIAR)
    {
      std::cout<<"Wrong number of dimensions.\n";
      return false;
    }

    wektor->N=dlugosc;
    for(int i=0; i<dlugosc; i++)
    {
      wektor->tab[i]=fib(i);
    }
    return true;
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
void revert(vecM *struktura)
{
  int a; //przechowuje tymczasowa wartosc, potrzebna do revert
  int x=(struktura->N/2);

  for(int i=0 ;i<x; i++)
  {
    a=struktura->tab[i];
    struktura->tab[i]=struktura->tab[struktura->N-1-i];
    struktura->tab[struktura->N-1-i]=a;
  }
  printVec(struktura);
  std::cout<<"(reverting done)\n";
}
void extend(vecM *struktura,int dodaj)
{
  if(dodaj+struktura->N>ROZMIAR)
  {
    printf("Wow, you've just gone crazy(%d>%d).\n",dodaj+struktura->N,ROZMIAR );
    return;
  }

  struktura->N=struktura->N+dodaj;
  printVec(struktura);
  std::cout<<"(extending by "<<dodaj<<" done\n)";
}
void truncate(vecM *struktura,int obetnij)
{
  if(struktura->N-obetnij<0)
  {
    std::cout<<"dlugosc<0\n";
    return;
  
  }
  struktura->N=struktura->N-obetnij;
  printVec(struktura);
  printf("(truncation by %d done)\n",obetnij);
}

void checkVecSpouse(vecM* struktura)
{
  if(struktura->malzonek==NULL)
  {
    printVec(struktura);

    std::cout<<"has no spouse.\n";
  }
  else{
    printVec(struktura);
    std::cout<<"is parried with";
    printVec(struktura->malzonek);
    std::cout<<"\n";
  }
}
void marry(vecM *X,vecM *Y)
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
void divorce(vecM *X, vecM *Y)
{
  X->malzonek=NULL;
  Y->malzonek=NULL;
}
void swap(vecM* X ,vecM* Y)
{ cout<<"Before:"<<X<<" and "<<Y<<endl; 
  vecM c = *X;
    *X = *Y;
    *Y = c;
  cout<<"after"<<X<<" and "<<Y<<endl;
}