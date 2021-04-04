#pragma once
#include "structures/array/array.h";
#include "matica.h"

class Matrix
{
private:
	structures::Matica<int>* matica1;
	structures::Matica<int>* matica2;
	structures::Matica<int>* matica3;
	structures::Matica<int>* maticaA;
	structures::Matica<int>* maticaB;
	structures::Matica<int>* maticaC;

	structures::Array<int>* array;
public:
	Matrix();
	~Matrix();

	int VyberTest(int volba);
	int VyberScenar(int scenar);
	void Spocitaj(int test);
	void Vynasob(int test);


};

