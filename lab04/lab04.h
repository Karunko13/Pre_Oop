#pragma once 

typedef int counter;
static counter count;
static counter* wsk_nPrints;

void printSequence(const double* , int);

void initCounter(int*);

double* initArithmeticSequence(double, double, int);

void addSequence(const double ***, double **, const double*, int);

void deleteSequence(const double**);

void printAllSequences(const double** , double*);

void deleteAllSequences(const double** , double*);

void initCounter(int*);

double* initGeometricalSequence(double, double, int);