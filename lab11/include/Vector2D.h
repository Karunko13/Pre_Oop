#pragma once 
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Vector2D
{
	private:
  //wspl. kartezjanskie
	double x,y; 
	//prywatny konstruktor ustawiajcy wartosci w1,w2, wywoływany przez fromCarthesian i fromPolar
	Vector2D(double w1,double w2);

	public:

  //zmienna statyczna reprezentujaca licznik, ile jest wektorow
	static int count;
	
	//konstruktor domyslny, ustawia wartosci x oraz y na 0
	Vector2D();

	//konstruktor przenoszacy
  Vector2D(Vector2D && newVector);
	
	//konstruktor kopiujący
	Vector2D(const Vector2D &srcVector);

  //(named constructor idiom) metoda zwracajaca obiekt klasy Vector2D,przyjmuje dwie zmienne typu double,
  static Vector2D fromCarthesian(double x, double y);

  //(named constructor idiom)metoda zwracajaca obiekt klasy Vector 2D,przyjmuje dwie zmienne typu double, przelicza wspolrzedne biegunowe na wspolrzedne kartezjanskie, 
	//r i phi to odpowiednio promien i kąt w stopniach 
  static Vector2D fromPolar(double r, double phi);
	
	//metoda wyliczajaca sume dwoch wektorow, zwraca obiekt klasy Vector2D, jako argument przyjmuje stala referencje na obiekt klasy Vector2D
	Vector2D add(const Vector2D &) const;
	
	//metoda przyjmujaca  jako argument  stala refenecje na obiekt klasy vector 2D wyliczajaca iloczyn skalarny dwoch wektorow, zwraca double, 
	double dot(const Vector2D &) const; 

	//metoda do wypisania wektora, typu void
	void print(const string vectorN) const;

  //destruktor, zmniejsza licznik o 1
	~Vector2D();


};