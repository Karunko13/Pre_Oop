#pragma once 
#include <iostream>
#include <string>
#define ROZMIAR 50

using namespace std;



struct vecM{
  int N=0;//rozmiar
  int tab[ROZMIAR]={0};
  struct vecM *malzonek=NULL;	
};

void printVec(vecM *);
bool fillVecWithFibonacci(vecM*, int);
int fib(int);
void revert(vecM *);
void extend(vecM *, int);
void truncate(vecM *, int);
void checkVecSpouse(vecM*);
void marry(vecM*,vecM*);
void divorce(vecM*,vecM*);
void swap(vecM*,vecM*);