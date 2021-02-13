#ifndef LAB01_H
#define LAB01_H
#define MAX 50
#include <stdio.h>
#include <stdlib.h>




typedef struct vecN{
  int N=0;
  int tab[MAX]={0};
  struct vecN* spouse = NULL;
}vecN;


void printVec(vecN*);

int fib(int);

bool fillVecWithFibonacci(vecN*, int);

void revert(vecN*);

void extend(vecN*, int );

void truncate(vecN*, int);

void checkVecSpouse(vecN *);

void marry(vecN*, vecN*);

void divorce (vecN*, vecN*);

void swap(vecN*, vecN*);

#endif