#include "Matrix.h"
#include "structures/array/array.h"
#include <iostream>
using namespace structures;
using namespace std;

int pocRiadkov = (rand() % 2000 + 1);
int pocStlpcov = (rand() % 2000 + 1);
int a = pocStlpcov;
int konstanta = (rand() % 2000 + 1);
int matica = pocRiadkov * pocStlpcov;
int maticaSucin = a * konstanta;
int maticaSucinVysledok = pocRiadkov * konstanta;

Matrix::Matrix()
{
}

int Matrix::VyberArrayTest(int volba)
{
	switch (volba) {
	case 0:
		array1 = new Array<int>(matica);
		array11 = new Array<int>(matica);
		array111 = new Array<int>(matica);
		array1111 = new Array<int>(maticaSucin);
		array11111 = new Array<int>(maticaSucinVysledok);
		return 0;
		break;
	case 1:
		array1 = new Array<int>(3);
		array2 = new Array<Array<int>*>(10);
		array1[0] = 3;
		array1[1] = 2;
		array1[2] = 5;
		array2[0] = *array1;
		return 1;
		break;
	default:
		return -1;
	}
	return 0;
}

int Matrix::VyberScenar(int scenar)
{
	return 0;
}

void Matrix::Spocitaj(int test)
{
	VyberArrayTest(0);
	cout << "MATICA 1 " << endl;
	for (int i = 0; i < array1->size(); i++)
	{
		int cislo = rand() % 2000 + 1;
		(*array1)[i] = cislo;
		if (i == pocStlpcov) 
		{
			cout << endl;
		}
		cout << (*array1)[i] << " ";
	}
	cout << endl;
	cout << "MATICA 2 " << endl;
	for (int i = 0; i < array11->size(); i++)
	{
		int cislo = rand() % 2000 + 1;
		(*array11)[i] = cislo;
		if (i == pocStlpcov)
		{
			cout << endl;
		}
		cout << (*array11)[i] << " ";
	}
	cout << endl;
	cout << "VYSLEDOK " << endl;
	for (int i = 0; i < array111->size(); i++)
	{
		(*array111)[i] = (*array1)[i] + (*array11)[i];
		if (i == pocStlpcov)
		{
			cout << endl;
		}
		cout <<(*array111)[i] << " ";
	}
	cout << endl;
}

void Matrix::Vynasob(int test)
{
	VyberArrayTest(0);
	cout << "MATICA 1 ";
	for (int i = 0; i < array1->size(); i++)
	{
		int cislo = rand() % 2 + 1;
		(*array1)[i] = cislo;
		if (i % pocStlpcov == 0)
		{
			cout << endl;
		}
		cout << (*array1)[i] << " ";
	}
	cout << endl;
	cout << endl;
	cout << "MATICA 2 ";
	for (int i = 0; i < array1111->size(); i++)
	{
		int cislo = rand() % 2 + 1;
		(*array1111)[i] = cislo;
		if (i % konstanta == 0)
		{
			cout << endl;
		}
		cout << (*array1111)[i] << " ";
	}
	cout << endl;
	cout << endl;
	cout << "VYSLEDOK NASOBENIA " << endl;

	for (int k = 0; k < pocRiadkov; k++)	
	{
		for (int i = 0; i < konstanta; i++)	
		{				
			(*array11111)[i + k * konstanta] = 0;
			for (int h = 0; h < pocStlpcov; h++)
			{
				(*array11111)[i + k * konstanta] += (*array1)[h + k * pocStlpcov] * (*array1111)[i + h * konstanta];
			}			
			cout << (*array11111)[i + k * konstanta] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

