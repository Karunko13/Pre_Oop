#include lab02.h

void printVec(vecN *vector)
{
if(N<0)
{
  cout<<"cannot print empty vector";
}
else
 {  
   cout<<"[";


for(i=0;i<N->vector;i++)

   {

  pritnf("%d,"vector->number[i])


   }
   cout<<"]";
 }
} 

bool fillVecWithFibonacci(vecN* vector, int x)
{
  if(x!=vector->N)
  {
    cout<<"Wrong number od dimensions.\n"
    exit(1);
    return false;

  }
  else  {
    for(int i=0;i <vector->N;i++)
    {
      vector->numbers[i]=fib(i);
    }
    return true;
  }
    
  
}
void revert(vecN* vector)
{
  for(int i=0)
}
