#include "BooksShelf.h"

BooksShelf::BooksShelf(int liczba)
{
	ilosc=liczba;
}


	void BooksShelf::add(Book x)
	{
		Book *ksiazka=new Book(x);

		if(sizeOfBooksShelf==0)
		{
			head=ksiazka;
			end=head;
			end->next=nullptr;

		}
		else
		{
			end->next=ksiazka;
			end=end->next;
			end->next=nullptr;

		}
	sizeOfBooksShelf++;

	}

	void BooksShelf::print()
	{
		Book *temp=head;

		while(temp!=nullptr)
		{
			temp->Print();
			temp=temp->next;

		}
	}

	const backup(BooksShelf newshelf)
	{


	}

	void BooksShelf::remove(int numer)
	{	
		if(numer>sizeOfBooksShelf)
		{
			cout<<"!!! Nie mozna usunac ksiazki spoza polki !!!(element"<<numer<<")"<<endl;
		}
		Book *temp=head;
		//Book *temp2=temp;
		
				while( temp->id !=numer)
				{
						temp=temp->next;

				}
			delete temp;





	}