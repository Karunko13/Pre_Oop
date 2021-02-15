#pragma once

using namespace std;

class MyList{

	private:
	
	//wskaznik na poczatek
	Element *head;
	//wskaznik na koniec
	Element *tail;

	//dlugosc listy
   int _size;


	public:
	//konstruktor bezparametrowy/domyslny
	MyList();
	//konstrukor jednoargumentowy
	MyList(int x);
	//konstruktor kopiujacy
	MyList(MyList &srcList);
	//konstruktor przenoszacy
	MyList(MyList &&srcList);
	int empty();
	void print();
	int size();
	void clear();

};

class Element{

	private:
	int data;
	

	public:
	Element(int val);
Element *next;

};