#include "Vector2D.h"
//definicja PI
#define PI 3.14159

int Vector2D::count=0;

//lista inicjalizacyjna
Vector2D::Vector2D(): x(0),y(0)
{count++;}

//lista inicjalizacyjna
Vector2D::Vector2D(double w1,double w2):x(w1),y(w2)
{
	//x=w1;
  //y=w2;
	count++;
}

Vector2D::Vector2D(const Vector2D &srcVector)
{
	
	cout<<"copying "<<"("<<srcVector.x<<", "<<srcVector.y<<")"<<endl;
	x=srcVector.x;
	y=srcVector.y;
	count++;
}


 Vector2D::Vector2D(Vector2D && newVector)
 {
	 
	 cout<<"moving "<<"("<<newVector.x<<", "<<newVector.y<<")"<<endl;
	 x=__exchange(newVector.x,0);
	 y=__exchange(newVector.y,0);
	count++;
 }

Vector2D Vector2D::fromCarthesian(double x, double y)
 {	// tworzac nowy obiekt wywołuje konstruktor 
	 return Vector2D(x,y);

 }

 Vector2D Vector2D::fromPolar(double r, double phi)
 {	//przeliczenie ze wspl biegunowych na kartezjanskie
	 double wsp1=r*cos((phi*PI)/180.0);
	 double wsp2=r*sin((phi*PI)/180.0);
	 return Vector2D(wsp1,wsp2);
 }


Vector2D Vector2D::add(const Vector2D &wektor2) const
{	//dodawanie wspolrzednych
	double wsp1=x+wektor2.x;
	double wsp2=y+wektor2.y;
	return Vector2D(wsp1,wsp2);

}


double Vector2D::dot(const Vector2D &wektor2) const
{		//wyliczenie iloczynu skalarnego czyli x1*x2,y1*y2
	double wsp1=x*wektor2.x;
	double wsp2=y*wektor2.y;
	return wsp1+wsp2;

}

void Vector2D::print(const string vectorN) const
{
	cout<<vectorN<<"("<<x<<", "<<y<<")"<<endl;
}

Vector2D::~Vector2D()
{
	count--;
}