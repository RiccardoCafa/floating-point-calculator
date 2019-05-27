// CalculadoraPontoFlutuante.cpp : Este arquivo contém a função 'main'.
//

#include "pch.h"
#include "Calculadora.h"
#include <iostream>
#include <vector>

void PrintarVetor(short vet[], int tam);

int main()
{
	long double valor;
	Calculadora calc;
	int TamanhoBits = 8;
	while (1) {
		fflush(stdin);
		//std::cout << "Insira o tamanho de bits:: ";
		//std::cin >> tamas;
		short* bina8 = (short*)calloc(8, sizeof(short));
		short* bina32 = (short*)calloc(32, sizeof(short));
		short* bina64 = (short*)calloc(64, sizeof(short));

		std::cout << "Insira o valor:: ";
		std::cin >> valor;
		
		//std::cout << std::endl;
		std::cout << "=============  Transformando para binario...  =============" << std::endl;
		std::cout << std::endl;

		calc.dec_to_bin(valor, TamanhoBits, bina8);
		for (int i = 0; i < TamanhoBits; i++) {
			std::cout << bina8[i];
		}
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "=============  Complemento para dois...  =============" << std::endl;
		std::cout << std::endl;
		int p = 8;
		short* po8;
		po8 = (short*)calloc(p, sizeof(short));
		long valorComplemento = calc.complementoDois(valor);
		calc.dec_to_bin(valorComplemento, TamanhoBits, po8);
		for (int i = 0; i < TamanhoBits; i++) {
			std::cout << po8[i];
		} 
		std::cout << std::endl;
		std::cout << std::endl;
	
		std::cout << "=============  Ponto Flutuante  =============" << std::endl << std::endl;
		short* vemHexa8;
		short* vemHexa32;
		short* vemHexa64;
		vemHexa8 = calc.float_notation(valor, 8, 3);
		vemHexa32 = calc.float_notation(valor, 32, 8);
		vemHexa64 = calc.float_notation(valor, 64, 11);
		std::cout << std::endl;
		int f;

		std::cout << "=============  Valor em hexadecimal  =============" << std::endl << std::endl;
		
		std::cout << "=====  Valor em hexadecimal na base 8  =====" << std::endl;
		calc.convert_binario_hexa(vemHexa8, 8);
		std::cout << std::endl;

		std::cout << "=====  Valor em hexadecimal na base 32  =====" << std::endl;
		calc.convert_binario_hexa(vemHexa32, 32);
		std::cout << std::endl;

		std::cout << "=====  Valor em hexadecimal na bsae 64  =====" << std::endl;
		calc.convert_binario_hexa(vemHexa64, 64);
		std::cout << std::endl;
	}
	
}

void PrintarVetor(short vet[], int tam) {
	for (int j = 0; j < tam; j++) {
		std::cout << vet[j];
	}
}