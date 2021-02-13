#include "lab01.h"

int fib(int a)
{
  if(a<0)
  {
    printf("Error. Only numbers >= 0\n");   
    return 0;
  }
  if(a < 2 ) return 1;                    //fib(0)=fib(1)=1
  else       return fib(a-1)+fib(a-2);    //recursion fib(n)=fib(n-1)+fib(n-2)
}

void printVec(vecN* vector)
{
  if (vector->N>0)
  {
    printf("[");                          //open vector
    for (int i=0;i<vector->N;i++)
    {
      printf("%d,", vector->tab[i]);      //next nubers and ','
    }
    printf("\b]");                        //backspace to erase last ',' and close vac
  }
  else 
  {
    printf("Cannot print empty vector\n");  //if vector empty do not print
  }
}


bool fillVecWithFibonacci(vecN* vector, int rozmiar)
{
  if ( rozmiar > MAX || rozmiar <= 0)
  {
    printf("Wrong number of dimensions.\n");  //dimension <0 or >MAX
    
    return false;
  }
  else if (vector == nullptr)
  {
    printf("Empty pointer provided\n");
    return false;                       //wrong arg in function
  }
  else 
  {
    vector->N=rozmiar;                   //set proper size of vec (proper mean that we use right now) 
    for (int i=0; i<vector->N;i++)
    {
      vector->tab[i]=fib(i);          //filling vect with numbers
    }
    return true;
  } 
}

void revert(vecN* vector)
{
  int temp;
  for (int i=0; i < (vector->N)/2 ;i++)
  {
    temp = vector->tab[i];
    vector->tab[i] = vector->tab[ vector->N-1-i ];      
    vector->tab[ vector->N-1-i ] = temp;
    /*
    we go from start of vector to half and swaping [i] with [N-i] numer
    but remberber of cpp tab indexing from 0 so we need to add (-1)
    */
  }
  printVec(vector);
  printf(" (reverting done)\n");
}

void extend(vecN *vector, int add)
{
  if ( vector->N + add > MAX) {
    printf(" Wow, you've just gone crazy (%d>%d).\n", vector->N + add, MAX );   //if someone try to make vec > MAX
    return;             //empty return to end functin with no change anything 
  }
  else 
  {
    vector->N += add;  // 'unlocking' nexts dim of vec
    printVec(vector);
    printf(" (extending by %d done)\n", add);
  }
}

void truncate(vecN *vector, int cut)
{
  if ( vector->N - cut < 0) 
  {
    printf(" Wow, you've just gone crazy (dimession of vector cannot be < 0).\n");//if someone try to make vec < 0
    return ;      //empty return to end functin with no change anything 
  }
  else 
  {
    vector->N -= cut;   //'lock' unused dimensions of vec 
    printVec(vector);   
    printf(" (truncation by %d done)\n", cut);
  }
}

void checkVecSpouse(vecN *vector)
{
  if (vector->spouse == NULL) //NULL -> no spouse
  { 
    printVec(vector);
    printf(" has no spouse\n");
  }
  else
  {
    printVec(vector);
    printf(" is paired with ");
    printVec(vector->spouse); //pointer to spouse of vec
    puts("");                 //next line
  }
}

void marry(vecN* vector_1, vecN* vector_2)
{
  if(vector_1 == vector_2) //exactly the same
  {
    printf(" Can't marry myself\n");
  }
  else if(vector_1->N == vector_2->N) //might be twins
      {
        bool twin = true;         //we suppose that vecs are twins
        for(int i=0; i<vector_1->N; i++)      //checking if vecs are twins
        {
          if(vector_1->tab[i] != vector_2->tab[i])
          {
            twin = false ;        //if vecs are diffrent
          }
        }

        if(twin)
        {
          printf(" Can't marry my twin\n"); //vecs are twins
        }
        else  //not twins
        {
          vector_1->spouse = vector_2;
          vector_2->spouse = vector_1;
        
        }
      }
  else //not twins for sure
  {
    vector_1->spouse = vector_2;
    vector_2->spouse = vector_1;
  }
}

void divorce(vecN* vector_1, vecN* vector_2)
{
  vector_1->spouse = NULL;    //if we want to vec have no spose we turn vecN.spose to NULL 
  vector_2->spouse = NULL;
}

void swap(vecN* a, vecN* b)
{
  vecN* c=a;    //temp vec
  a=b;
  b=c;
}
