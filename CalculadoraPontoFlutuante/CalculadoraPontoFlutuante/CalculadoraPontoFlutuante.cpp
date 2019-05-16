// CalculadoraPontoFlutuante.cpp : Este arquivo contém a função 'main'.
//

#include "pch.h"
#include "Calculadora.h"
#include <iostream>
#include <vector>

int main()
{
	Calculadora calc;
	short bina[5];
	calc.dec_to_bin(29, 5, bina);
	for (int i = 0; i < 5; i++) {
		std::cout << bina[i];
	}
	std::cout << std::endl;
	std::vector<char> as;
	as = calc.convert_binario_hexa(bina, 4);
	for (int j = 0; j < as.size(); j++) {
		std::cout << as[j];
	}
	std::cout << std::endl;
	calc.float_notation(3, 8, 3);
	calc.float_notation(34.76, 32, 8);
	calc.float_notation(782.38573, 64, 11);
}