#pragma once
#include <iostream>
using namespace std;

class Arr2D{

	private:
	
	int rows;
	int columns;
	int **tab;

	public:
	Arr2D();
	Arr2D(int a ,int b);
	Arr2D(int **a,int b,int c);
	Arr2D(const Arr2D&);
	~Arr2D();

	void print() const;

	static Arr2D adopt(int [],int,int);

	//Arr2D operator=(const Arr2D&);
	int* operator [](int );
	friend void operator <<=(const char*,const Arr2D&);

};