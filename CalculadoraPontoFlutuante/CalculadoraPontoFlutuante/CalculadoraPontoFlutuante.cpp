// CalculadoraPontoFlutuante.cpp : Este arquivo contém a função 'main'.
//

#include "pch.h"
#include "Calculadora.h"
#include <iostream>
#include <vector>

int main()
{
	Calculadora calc;
	short bina[64];
	//long banana = ;
	long banana = 16;
	calc.decimal_para_binario(banana, 8, bina);
	for (int i = 0; i < 8; i++) {
		std::cout << bina[i];
	}
	std::cout << std::endl;
	std::vector<char> as;
	as = calc.convert_binario_hexa(bina, 8);
	for (int j = 0; j < as.size(); j++) {
		std::cout << "0x" << as[j];
	}
	std::cout << std::endl;
}
/*
*/