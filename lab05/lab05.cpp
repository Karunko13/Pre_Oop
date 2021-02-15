#include "lab05.h"
const int kBufferSize = 500;

void prepare(OneWayList* lista)
{
	lista->head=nullptr;
}

void add(OneWayList* lista  ,const char* tekst )
{
	node *element=(node*)malloc(sizeof(node));//utworzenie nowego wskaznika"element" na strukture
	element->data=(char*)malloc(sizeof(char)* kBufferSize);
	if(element==NULL) exit(1);//sprawdzenie czy mallock sie powiodl
	if(element->data==NULL) exit(1);//sprawdzenie czy mallock sie powiodl

	strcpy(element->data,tekst);//kopiowanie stringa"tekst"
	element->next=NULL;
	if(lista->head==NULL){
		lista->head=element;//dopisanie na początek
	}
else{
	node * ost=lista->head;//nowy wskaznik na strukture
	while(ost->next!=NULL)//przejscie przez cala liste
	{
		ost=ost->next;
	}
	ost->next=element;//dodanie wezla do ostatniego elementu listy
}


}



void dump(const OneWayList* lista){//wypisanie elementow listy w kolejnosci od pierwszego

node* tym = lista->head;
	while(tym!=NULL){
		std::cout<<tym->data<<" ";
		tym=tym->next;//przejscie do nastepnego elementu
	}

}

void clear( OneWayList* lista){
	if(lista->head !=NULL){
		node* tym=lista->head;//utworzenie nwoego wskaznika na strukture
		node* next;
		while(tym !=NULL)
		{
			next=tym->next;
			free(tym->data);//zwalnianie pamieci
			free(tym);
			tym=next;
		}
	  (lista -> head) = NULL;


	}


}
bool empty(const OneWayList* lista){
	if(lista->head==NULL)//sprawdzenie czy lista jest pusta i zwrocenie wartosci true albo false
	{
		return true;
	}
	else
	{
		return false;
	}

}


