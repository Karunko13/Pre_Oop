#pragma once
#include <iostream>

typedef int counter;

//funkcja do wypisywania ciagu,jako argumenty podawany jest jej adres oraz dlugosc
void printSequence(const double *, int);

//funkcja "badajaca" rozmiar ciagu
void initCounter(int *);

//funkcja wypelniajaca elementy ciagu liczbami z ciagu arytmetycznego,jako argumenty: od jakiej liczby zaczac,o ile zwiekszyc, i jak dlugi ma byc ciag(double,double,int)
double* initArithmeticSequence(double,double,int);

//funckja wypelniajaca elementy ciagu liczbami z ciagu geometrycznego,jako argumenty: od jakiej liczby zaczac,o ile zwiekszyc, i jak dlugi ma byc ciag(double,double,int)
double * initGeometricalSequence(double, double, int );

void addSequence(const double ***, double **, double*,int);

//funkcja usuwajaca ciag
void deleteSequence(const double**);

void printAllSequences(const double**,double*);

void deleteAllSequences(const double**,double*);


