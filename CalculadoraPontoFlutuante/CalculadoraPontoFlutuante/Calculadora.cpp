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
			if (n & 1) {
				bina[tamanhoBits - 1 - count] = 1;
			}
			else {
				bina[tamanhoBits - 1 - count] = 0;
			}
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
	for (i = Tamanho; i > 0; i--) {
		aux[count] = bina[i];
		if (i == 0 && count < 3) {
			do {
				aux[count + 1] = 0;
			} while (count == 3);
		}
		if (count == 3) {
			calc += 8 * aux[0];
			calc += 4 * aux[1];
			calc += 2 * aux[2];
			calc += 1 * aux[3];
			if (calc > 9) {
				hexa.push_back(calc + 55);
				calc = 0;
			}
			else {
				hexa.push_back((char)calc);
				calc = 0;
			}
			count = 0;
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
