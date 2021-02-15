#pragma once
#include "Book.h"

//using namespace std;


class BooksShelf{
	
	friend class Book;

	private:
	int ilosc;
	int sizeOfBooksShelf;
	Book *head;
	Book *end;

	public:

	//konstruktor
	BooksShelf(int liczba);

	void add(Book x);

	void print(); const

	//const backup(BooksShelf newshelf);

	void remove(int numer);
};