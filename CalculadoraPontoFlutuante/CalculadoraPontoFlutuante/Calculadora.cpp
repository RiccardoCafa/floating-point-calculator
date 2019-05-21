#include "pch.h"
#include "Calculadora.h"
#include <iostream>
#include <vector>

void Calculadora::decimal_para_binario(long decimal, int tamanhoBits, short bina[])
{
	long n = decimal;
	int count = 0;

	do {
		if (n != 0) {
			bina[tamanhoBits - 1 - count] = n & 1;
			n >>= 1;
		}
		else {
			bina[tamanhoBits - 1 - count] = 0;
		}
		count++;
	} while (count < tamanhoBits);
}

std::vector<char> Calculadora::convert_binario_hexa(short bina[], int Tamanho)
{
	std::vector<char> hexa;
	int i = 0;
	int count = 0;
	int aux[4];
	int calc = 0;
	for (i = 0; i <= Tamanho - 1; i++) {
		/*if (i == 0) {
			do {
				count++;
				aux[count] = 0;
			} while (count < 3);
		}*/
		aux[count] = bina[i];
		if (count == 3) {
			calc += 8 * aux[0]; 
			calc += 4 * aux[1]; 
			calc += 2 * aux[2]; 
			calc += aux[3]; 
			if (calc > 9) {
				hexa.push_back(calc + 55);
				calc = 0;
			}
			else {
				hexa.push_back(48 + calc);
				calc = 0;
			}
			count = -1;
		}
		count++;
	}
	return hexa;
}

long Calculadora::complementoDois(long numero)
{
	return complementoUm(numero) + 1;
}

long Calculadora::complementoUm(long numero)
{
	return ~numero;
}

Calculadora::Calculadora()
{

}


Calculadora::~Calculadora()
{

}
