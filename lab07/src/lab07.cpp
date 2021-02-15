#include "lab07.h"
#include <iostream>


Vector *form_Vector(int a,int dane){

	Vector *nowy=new Vector; //alokacja nowego wskaznika na strukture"Vector" o nazwie "nowy"
	nowy->nDim=a;
	nowy->licz=new int[a];
	for(int i=0;i<a;i++)
	{
		nowy->licz[i]=dane;//przypisanie wartosci
	}
	return nowy;

}

const Matrix *form_Matrix(int a,int b,int dane){

	Matrix *nowyM=new Matrix;//alokacja nowego wskaznika na strukture "Matrix" o nazwie"nowyM"
 	nowyM->dim1=a;
	nowyM->dim2=b;
	nowyM->liczMat=new int*[a];

	for(int i=0;i<a;i++)
	{
		nowyM->liczMat[i]=new int[b];//alokacja wszystkich nowych "pól" w macierzy

	}

	for(int i=0;i<a;i++)//dwie pętle idące "pionowo" oraz "poziomo"
	{
			for(int j=0;j<b;j++){

			nowyM->liczMat[i][j]=dane;
			}
	}

	return nowyM;


}

void print(Vector &wek){

	std::cout<<"[";

	for(int i=0;i<wek.nDim;i++)
	{
		std::cout<<wek.licz[i]<<",";//wypisanie wartosci wektora 
	}

	std::cout<<"]";
}

void print(const Matrix &mat){

	for(int i=0;i<mat.dim1;i++){//dwie pętle idące "pionowo" oraz "poziomo"
		std::cout<<"[";
					for(int k=0;k<mat.dim2;k++)
					{
							std::cout<<*mat.liczMat[i]<<" ";//wypisanie wartosci macierzy
					}
		std::cout<<"]";
		std::cout<<std::endl;

	}


}


void deleteAll(Vector* wek)
{
		delete []wek->licz;
		delete wek;
}

void deleteAll(const Matrix* mat){
	for(int i=0;i<mat->dim1;i++){
		delete []mat->liczMat[i];
	}

		delete [] mat->liczMat;
		delete mat;

}

void setNewDimension(Vector &wsk,int rozm){
	for(int i=wsk.nDim;i<rozm;i++){

			wsk.licz[i]=0;//wszystkie dodane pola mają wartość 0
	}
wsk.nDim=rozm;//ustawinie nowego rozmiaru
}

bool addFirstToSecond(Vector &wek1,Vector &wek2){
	
	if(wek1.nDim != wek2.nDim){//sprawdzam czy rozmiary są takie same, jeżeli się różnią to odrazu zwracam 0=nie da się wykonać dodawania
		return 0;
	}
else{

	for(int i=0;i<wek1.nDim;i++)
	{
		wek2.licz[i]=wek2.licz[i]+wek1.licz[i];//dodaje elementy wektora wek1 do wektora wek2
	}
}

return 1;

}
