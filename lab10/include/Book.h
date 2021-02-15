#pragma once

#include <string>
#include <iostream>
using namespace std;

class BooksShelf;

class Book{

		friend class BooksShelf;
     private:

     string name;
		 int id;
		static int liczbaKsiazek;
		//wskaznik na nastepna ksiazke
		Book *next;
		public:
	//konstruktor
		Book(string nazwa);

		void Print();
		

};