#pragma once
#include <iostream>
#include <cstring>

typedef struct node{

	node *next;
	char* data;

}node;
//struktura OneWayList przechowuje wskaznik na pierwszy wezel, czyli poczatek listy 
typedef struct OneWayList{

	node*head;
}OneWayList;


//funkcja przyjmujaca jako argument wskaznik na strukture OneWayList
void prepare(OneWayList*);

//funckja przyjmujaca jako argument wskaznik na strukture oraz dane slowo(czyli wskaznik na tablice)
void add(OneWayList*,const char*);

//funkcja przyjmujaca jako argument wskaznik na strukture OneWayList,funkcja zwraca true jezeli lista jest pusta i false w przeciwnym wypadku
bool empty(const OneWayList*);

//funkcja przyjmujaca jako argument wskaznik na strukture OneWayList,wypisuje elementy listy 
void dump(const OneWayList*);

//funkcja przyjmujaca jako argument wskaznik na strukture OneWayList, funkcja usuwa zaalokowane wczesniej elementy w tablicy 
void clear(OneWayList*);
