#pragma once
#include <vector>
#include <string>

class Calculadora
{
public:
	void dec_to_bin(long decimal, int tamanhoBits, short bina[]);
	std::vector<char> convert_binario_hexa(short bina[], int Tamanho);
	long complementoDois(long numero);
	long complementoUm(long numero);
	short* float_notation(long double num_dec, int total_buffer, int exp_buffer);
	Calculadora();
	~Calculadora();
};

