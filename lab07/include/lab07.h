#pragma once
#include <iostream>
//struktura "Vector", reprezentuje wektor, zawiera jego rozmiar oraz wskaznik do tablicy jednowymiarowej
struct Vector{
	
	int nDim; 
	int *licz; 


};

//Struktura "Matrix", reprezentuje macierz, zawiera rozmiary macierzy i wskaznik na tablice dwuwymiarową
struct Matrix{
	
	int dim1;  
	int dim2; 
	int **liczMat; 

};

//funkcja przyjmujaca argumenty"domyslne", tworzy wektor,jako argumenty przyjmuje rozmiar oraz zawartosc kolejnych elementow
Vector *form_Vector(int a=3,int dane=0);

//funkcja przyjmujaca argumenty"domyslne, tworzy macierz, jako argumenty przyjmuje rozmiar,rozmiar,zawartosc poszczegolnych elementów
const Matrix *form_Matrix(int a=3,int b=3,int dane=0);

//funkcja wypisujaca wektor,jako argument wskaznik na pierwszy element
void print(Vector &wek);

//funkcja wypisujaca macierz,jako argument wskaznik na pierwszy element
void print(const Matrix &mat);

//funkcja usuwajaca wektor z pamieci(zwalniajaca pamiec w ktorej był wektor)
void deleteAll(Vector* wek);

//funkcja usuwajaca macierz z pamieci(zwalniajaca pamiec w ktorej była macierz)
void deleteAll(const Matrix* mat);

//funckaj zmieniajaca rozmiar wektora na podany jako drugi argument
void setNewDimension(Vector &wek,int rozm);

//funckcja dodajaca dwa wektory,
bool addFirstToSecond(Vector &,Vector &);