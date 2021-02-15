#include "Book.h"
//using namespace std;
int Book::liczbaKsiazek=0;

Book::Book(string nazwa)
{
	name=nazwa;
	id=liczbaKsiazek;
	liczbaKsiazek++;


}

void Book::Print()
{

cout<<name<<endl;

}