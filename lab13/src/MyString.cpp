#include "MyString.h"
// #include <iostream>
// #include <cstring>
namespace mystring
{


 MyString::MyString()
 {}
MyString::MyString(const char*tekst)
{
	word=new char[strlen(tekst)+1];
	strcpy(word,tekst);
}

MyString::MyString(const MyString &oldMyStr)
{
	word=new char[strlen(oldMyStr.word)+1];
	strcpy(word,oldMyStr.word);
}

MyString::MyString(MyString&& oldMyStr)
{
	word=oldMyStr.word;
	oldMyStr.word=nullptr;

	//wykomentowane bo przenioslem do operator=
	//word=new char[strlen(oldMyStr.word)+1];
	// strcpy(word,oldMyStr.word);
	// delete[] oldMyStr.word;
}

MyString::~MyString()
	{
		delete[] word;
	}

void MyString::print(const char*text) const
{
	std::cout<<text<<word<<std::endl;
}

void MyString::operator=(const char*anotherS)
{	//usuwanie starego wyrazu
	delete[] word;
	//alokacja pamieci na nowy wyraz +(1) znak konca linii
	word=new char[strlen(anotherS)+1];
	strcpy(word,anotherS);
}

bool MyString::operator==(const MyString &anotherS) const
{
	if(strcmp(word,anotherS.word)==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
	MyString MyString::operator+(const MyString anotherS) const
	{
		MyString tempString;
		tempString.word=new char[strlen(word)+strlen(anotherS.word)+1];
		strcat(tempString.word,word);
		strcat(tempString.word,anotherS.word);
		return tempString;

	}
		MyString MyString::operator+(const char* anotherS) const
		{
			return *this+MyString(anotherS);
		}

		MyString MyString::operator+(const char anotherS) const
		{
			//dodanie znaku konca linii 
			char tempString[2]={anotherS,'\0'};
			return *this+tempString;
		}
		MyString::operator char*() const
		{
			return word;
		}

	MyString operator*(const int number,const MyString& RightStr)
	{
 //alokacja nowego elementu o dlugosci iloczynu dwoch elementow
	char *newText=new char[strlen(RightStr)*number];
	for(int i=0;i<number;i++)
	{	
		strcat(newText,RightStr);
	}

	return *new MyString(newText);
	} 

	bool operator==(const MyString& oldStr,const char* newStr)
	{
		if(strcmp(oldStr,newStr)==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	}
}
