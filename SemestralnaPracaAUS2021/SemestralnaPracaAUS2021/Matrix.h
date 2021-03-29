#pragma once
#include "structures/array/array.h";

class Matrix
{
private:
	structures::Array<int>* array1;
	structures::Array<int>* array11;
	structures::Array<int>* array111;
	structures::Array<int>* array1111;
	structures::Array<int>* array11111;
	structures::Array < structures::Array<int>*> * array2;
public:
	Matrix();
	~Matrix() {};

	int VyberArrayTest(int volba);
	int VyberScenar(int scenar);
	void Spocitaj(int test);
	void Vynasob(int test);


};

