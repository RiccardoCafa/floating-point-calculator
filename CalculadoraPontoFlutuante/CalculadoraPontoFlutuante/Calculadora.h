#pragma once
#include <vector>
class Calculadora
{
public:
	void decimal_para_binario(long decimal, int tamanhoBits, short bina[]);
	std::vector<char> convert_binario_hexa(short bina[], int Tamanho);
	long complementoDois(long numero);
	long complementoUm(long numero);
	Calculadora();
	~Calculadora();
};

