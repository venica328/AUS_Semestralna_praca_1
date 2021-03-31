#pragma once
#include "structures/array/array.h";
#include "matica.h"

class Matrix
{
private:
	structures::Matica<int>* maticaSuvisla1;
	structures::Matica<int>* maticaSuvisla2;
	structures::Matica<int>* maticaSuvisla3;
	structures::Matica<int>* maticaSuvislaA;
	structures::Matica<int>* maticaSuvislaB;
	structures::Matica<int>* maticaSuvislaC;

	structures::Array<int>* array;
public:
	Matrix();
	~Matrix();

	int VyberArrayTest(int volba);
	int VyberScenar(int scenar);
	void Spocitaj(int test);
	void SpocitajPolePoli(int test);
	void Vynasob(int test);
	void VynasobPolePoli();


};

