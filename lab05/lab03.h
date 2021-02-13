#pragma once
#include <iostream>
#define ROZMIAR 50

typedef struct myArray{
int N=0;
int tab[ROZMIAR]={0};
struct myArray *malzonek=NULL;
struct myArray *rodzic1=NULL;
struct myArray *rodzic2=NULL;

}myArray;

myArray formChild(myArray*,myArray*);

//funckcja do wypisania "wektora", jako argument przekazuje strukture
void printArray(myArray);
//uzupelnienia ciagiem fibonaciego wektora,jak argument ilosc elementow=dlugosc wektora
int fib(int);
//funkcja do uzupelnienia ciagiem fibonaciego wektora, jako argument adres wektora oraz dlugosc
bool fillArrayWithFibonacci(myArray *,int );
//poszerzenie wektora o dana wartosc, jako argument adres oraz int o ile poszerzyc
void extend(myArray*, int);
//skrocenie wektora o dana wartosc, jako argument adres oraz int o ile skrocic
void truncate(myArray*, int);
//odwrocenie wektora, czyli pierwszy element jest ostatnim itd. jako argument adres
void revert(myArray*);
//ozenienie dwoch wektorow czyli przypisanie im malzonka, jako argumenty dwa adresy
void marry(myArray*,myArray*);
//argument adres, sprawdzenie czy wektor ma malzonka
void checkArraySpouse(myArray*);
//wypisanie rodzicow wektora, jako argument adres
void printParents(myArray*);
//rozwod dwoch wektorow, jako argumenty ich adresy
void divorce(myArray*,myArray*);

