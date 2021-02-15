#pragma once

#include <cstring>
#include <iostream>
namespace mystring{

#define String MyString

class MyString
{
	private:
	//przechowuje tekst
	char *word;

	public:
		//kosntruktor domyslny
		MyString();
		//konstruktor jednoargumentowy
		MyString(const char *tekst);

		MyString(const MyString &oldMyStr);
		//konstrukot przenoszacy
		MyString(MyString&& oldMyStr);
		//destruktor
		~MyString();
		//metoda ktora wypisuje "text" a potem "word"
		void print(const char* text) const;
		//wstawia tekst anotherS do obiektu na ktorym operator zostal wywolany
		//usuwa takze stary "word " z obiektu
		void operator=(const char *anotherS);

		//porownuje czy "word" z obiektu jest takie same jak z "anotherS"
		//wykorzystuje funckje z <cstring> strcmp
		bool operator==(const MyString &anotherS) const;

		//zwraca obiekt z tekstem z obiektu anotherS dodanym na końcu
		MyString operator+(const char* anotherS) const;
		//zwraca obiekt z tekstem z obiektu dodanym ze znakiem anotherS
		MyString operator+(const char anotherS) const;

		MyString operator+(const MyString anotherS) const;
		//potrzebne do konwersji obiektu na char*
		operator char*() const;

};
//zewnetrzna funkcja operatorowa niezaprzyjazniona 
//potrzebna m.in do dzialania "4 * s5"
MyString operator*(const int number,const MyString& RightStr);
//zewnetrzna funkcja operatorowa niezaprzyjazniona 
// potrzebna do porownania "s2 == "Sesja juz niedlugo"
bool operator==(const MyString& oldStr,const char* newStr);
}