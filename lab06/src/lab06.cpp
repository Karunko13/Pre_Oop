#include <iostream>
#include "lab06.h"
#include <cmath>

//przygotowanie
void set(Bits* bit,int data[],int x){

bit->x=x;
int i;
int j=x-1;
			for(i=31;i>=0;i--){
				if(j>=0)
				{
					bit->tab[i]=data[j];
					j--;
				}
				else{
					bit->tab[i]=0;
				}
		}

}
//wypisanie
void print(const Bits* bit){
int i;
int tym=0;

	for(i=0;i<32;i++)
	{
		if(bit->tab[i]!=0 && tym==0)
		{
			tym=1;
			std::cout<<bit->tab[i];

		}
		else if(tym==1)
		{
			std::cout<<bit->tab[i];
		}



	}
	std::cout<<std::endl;
}

//dodawania
const Bits add_up(Bits* bit1,Bits* bit2){

Bits bit3;

int i;
		for(i=31;i>=0;i--)
			{

				bit3.tab[i]=bit3.tab[i]+bit1->tab[i]+bit2->tab[i];
				if(bit3.tab[i]==2)
				{
				bit3.tab[i]=0;
				bit3.tab[i-1]=0;

				}
				else if(bit3.tab[i]==3)
				{

					bit3.tab[i]=1;
					bit3.tab[i-1]=1;
				}
			}

return bit3;

}


//koniunkcja
void bit_and(Bits *bit,Bits *maska){

int i;
		for(i=31;i>=0;i--){

			if(bit->tab[i]==1 && maska->tab[i]==0)
			{
					bit->tab[i]=0;
			}
			else if(bit->tab[i]==0 && maska->tab[i]==1){
					bit->tab[i]=0;
		}
	}
}

//alternatywa wykluczajaca
void bit_xor(Bits* bit1,Bits* bit2){
	int i;
		for(i=31;i>=0;i--){

			if(bit1->tab[i]==1 && bit2->tab[i]==1)
			{
					bit1->tab[i]=0;
			}
			else if(bit1->tab[i]==0 && bit2->tab[i]==1){
					bit1->tab[i]=1;
		}
	}
}




//na dziesietne
int to_decimal(const Bits* bit){


	int decimal=0;
	int i;

	for(i=31;i>=0;i--){
		decimal+=pow(2,31-i)*bit->tab[i];

	}
return decimal;
}

