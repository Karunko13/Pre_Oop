#pragma once
#include <iostream>

struct Bits{

	int tab[32]={};
	int x;
};


void set(Bits* bit,int dane[],int x);

void print(const Bits* bit);

const Bits add_up(Bits* bit1,Bits* bit2);

void bit_and(Bits *bit,Bits *maska);

void bit_xor(Bits* bit1,Bits* bit2);

int to_decimal(const Bits* bit);

