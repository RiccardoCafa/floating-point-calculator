#include "pch.h"
#include "Calculadora.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

void Calculadora::dec_to_bin(long decimal, int tamanhoBits, short bina[])
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

char* Calculadora::convert_binario_hexa(short bina[], int Tamanho)
{
	char* hexa = (char *) calloc(64, sizeof(char));
	int i = 0;
	int count = 0;
	int aux[4];
	int calc = 0;
	std::cout << std::endl << "0x";
	for (i = 0; i <= Tamanho - 1; i++) {
		aux[count] = bina[i];
		
		if (count == 3) {
			calc += 8 * aux[0];
			calc += 4 * aux[1];
			calc += 2 * aux[2];
			calc += aux[3];
			if (calc > 9) {
				hexa[i] = calc + 55;
				std::cout << hexa[i];
				calc = 0;
			}
			else {
				hexa[i] = 48 + calc;
				std::cout << hexa[i];
				calc = 0;
			}
			count = -1;
		}
		count++;
	}
	std::cout << std::endl;
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

short* Calculadora::float_notation(long double num_dec, int total_buffer, int exp_buffer)//retorna um vetor de 0 e 1 q representa a notaçao de ponto flutuante
{
	std::cout << "== notacao de ponto flutuante de " << total_buffer << " bits ==========" << std::endl << std::endl << "  " << num_dec << " = ";

	//tamanho da mantissa
	int mant_buffer = total_buffer - exp_buffer;

	//definiçao das 3 zonas e da palavra completa
	short* sign_note = (short*)calloc(1, sizeof(short));
	short* exp_note = (short*)calloc(exp_buffer, sizeof(short));
	short* mant_note = (short*)calloc(mant_buffer, sizeof(short));
	short* float_note = (short*)calloc(total_buffer, sizeof(short));

	//preenchimento da zona sign (sinal)
	sign_note[0] = num_dec < 0 ? 1 : 0;
	for (int i = 0; i < 1; i++) std::cout << sign_note[i];

	num_dec = num_dec < 0 ? -num_dec : num_dec;
	std::cout << " ";

	//preenchimento da zona exp (expoente)
	int int_part = num_dec;
	int zero = pow(2, exp_buffer) / 2 - 1;
	int i = 0; while (int_part >= pow(2, i)) i++;
	int exp = i - 1;
	if (num_dec == 0) dec_to_bin(0, exp_buffer, exp_note);
	else if (exp > zero * 2 + 1) dec_to_bin(zero * 2 + 1, exp_buffer, exp_note);
	else dec_to_bin(zero + exp, exp_buffer, exp_note);
	for (int i = 0; i < exp_buffer; i++) std::cout << exp_note[i];

	std::cout << " ";

	//preenchimento da zona mant (mantissa)
	int count = 0;
	num_dec /= pow(2, exp);
	int_part = num_dec;
	while (num_dec != 0 && count < mant_buffer) {
		mant_note[count] = int_part;
		num_dec -= int_part;
		num_dec *= 2;
		count++;
		int_part = num_dec;
	}
	for (int i = 1; i < mant_buffer; i++) std::cout << mant_note[i];

	std::cout << std::endl << std::endl;

	//concatenaçao das 3 zonas
	for (int i = 0; i < total_buffer; i++) {
		if (i == 0) float_note[i] = sign_note[0];
		else if (i <= exp_buffer) float_note[i] = exp_note[i - 1];
		else float_note[i] = mant_note[i - exp_buffer];
	}
	return float_note;
}

Calculadora::Calculadora()
{

}


Calculadora::~Calculadora()
{

}
