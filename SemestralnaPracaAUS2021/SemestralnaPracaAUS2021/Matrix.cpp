#include "Matrix.h"
#include "structures/array/array.h"
#include "suvislaMatica.h"
#include "nesuvislaMatica.h"
#include "matica.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace structures;
using namespace std;

int pocRiadkov = (rand() % 20 + 1);
int pocStlpcov = (rand() % 20 + 1);
int pocStlpcov2 = (rand() % 20 + 1);
int spolu = 0;

Matrix::Matrix()
{
}

Matrix::~Matrix()
{
}

int Matrix::VyberArrayTest(int volba)
{
	switch (volba) {
	case 0:
		maticaSuvisla1 = new SuvislaMatica<int>(pocRiadkov, pocStlpcov);
		maticaSuvisla2 = new SuvislaMatica<int>(pocRiadkov, pocRiadkov);
		maticaSuvisla3 = new SuvislaMatica<int>(pocRiadkov, pocRiadkov);
		maticaSuvislaA = new SuvislaMatica<int>(pocRiadkov, pocStlpcov2);
		maticaSuvislaB = new SuvislaMatica<int>(pocStlpcov2, pocStlpcov);
		maticaSuvislaC = new SuvislaMatica<int>(pocRiadkov, pocStlpcov);
		return 0;
		break;
	case 1:
		maticaSuvisla1 = new NesuvislaMatica<int>(pocRiadkov, pocRiadkov);
		maticaSuvisla2 = new NesuvislaMatica<int>(pocRiadkov, pocRiadkov);
		maticaSuvisla3 = new NesuvislaMatica<int>(pocRiadkov, pocRiadkov);
		maticaSuvislaA = new NesuvislaMatica<int>(pocRiadkov, pocStlpcov2);
		maticaSuvislaB = new NesuvislaMatica<int>(pocStlpcov2, pocStlpcov);
		maticaSuvislaC = new NesuvislaMatica<int>(pocRiadkov, pocStlpcov);
		array = new Array<int>(5);
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
	for (int i = 0; i < maticaSuvisla1->getPocetRiadkov(); i++)
	{
		for (int j = 0; j < maticaSuvisla1->getPocetStlpcov(); j++)
		{
			int cislo = rand() % 2000 + 1;
			maticaSuvisla1->set(i, j, cislo);
			cout << maticaSuvisla1->get(i, j) << " " ;
		}
		cout << endl;
	}

	cout << endl;
	cout << "MATICA 2" << endl;
	for (int i = 0; i < maticaSuvisla2->getPocetRiadkov(); i++)
	{
		for (int j = 0; j < maticaSuvisla2->getPocetStlpcov(); j++)
		{
			int cislo = rand() % 2000 + 1;
			maticaSuvisla2->set(i, j, cislo);
			cout << maticaSuvisla2->get(i, j) << " ";
		}
		cout << endl;
	}

	cout << endl;
	cout << "MATICA sucet" << endl;
	for (int i = 0; i < maticaSuvisla3->getPocetRiadkov(); i++)
	{
		for (int j = 0; j < maticaSuvisla3->getPocetStlpcov(); j++)
		{
			int A = maticaSuvisla1->get(i,j);
			int B = maticaSuvisla2->get(i, j);
			int sucet = A + B;
			maticaSuvisla3->set(i, j, sucet);
			cout << maticaSuvisla3->get(i, j) << " ";
			sucet = 0;
			A = 0;
			B = 0;
		}
		cout << endl;
	}
	cout << endl;
}
void Matrix::SpocitajPolePoli(int test)
{
	VyberArrayTest(1);
	cout << "MATICA pole poli " << endl;
	for (int i = 0; i < maticaSuvisla1->getPocetRiadkov(); i++)
	{
		for (int j = 0; j < maticaSuvisla1->getPocetStlpcov(); j++)
		{
			int cislo = rand() % 2000 + 1;
			maticaSuvisla1->set(i, j, cislo);
			cout << maticaSuvisla1->get(i, j) << " ";
		}
		cout << endl;
	}

	cout << endl;
	cout << "MATICA 2" << endl;
	for (int i = 0; i < maticaSuvisla2->getPocetRiadkov(); i++)
	{
		for (int j = 0; j < maticaSuvisla2->getPocetStlpcov(); j++)
		{
			int cislo = rand() % 2000 + 1;
			maticaSuvisla2->set(i, j, cislo);
			cout << maticaSuvisla2->get(i, j) << " ";
		}
		cout << endl;
	}

	cout << endl;
	cout << "MATICA sucet" << endl;
	for (int i = 0; i < maticaSuvisla3->getPocetRiadkov(); i++)
	{
		for (int j = 0; j < maticaSuvisla3->getPocetStlpcov(); j++)
		{
			int A = maticaSuvisla1->get(i, j);
			int B = maticaSuvisla2->get(i, j);
			int sucet = A + B;
			maticaSuvisla3->set(i, j, sucet);
			cout << maticaSuvisla3->get(i, j) << " ";
			sucet = 0;
			A = 0;
			B = 0;
		}
		cout << endl;
	}
	cout << endl;
	
	
}

void Matrix::Vynasob(int test)
{
	VyberArrayTest(0);
	cout << "MATICA A " << endl;
	for (int i = 0; i < maticaSuvislaA->getPocetRiadkov(); i++)
	{
		for (int j = 0; j < maticaSuvislaA->getPocetStlpcov(); j++)
		{
			int cislo = rand() % 2 + 1;
			maticaSuvislaA->set(i, j, cislo);
			cout << maticaSuvislaA->get(i, j) << " ";
		}
		cout << endl;
	}

	cout << endl;
	cout << "MATICA B " << endl;
	for (int i = 0; i < maticaSuvislaB->getPocetRiadkov(); i++)
	{
		for (int j = 0; j < maticaSuvislaB->getPocetStlpcov(); j++)
		{
			int cislo = rand() % 2 + 1;
			maticaSuvislaB->set(i, j, cislo);
			cout << maticaSuvislaB->get(i, j) << " ";
		}
		cout << endl;
	}

	cout << endl;
	cout << "MATICA C sucin" << endl;
	for (int i = 0; i < maticaSuvislaA->getPocetRiadkov(); i++)
	{
		for (int j = 0; j < maticaSuvislaB->getPocetStlpcov(); j++)
		{
			for (int k = 0; k < maticaSuvislaB->getPocetRiadkov(); k++)
			{
				int sucet = maticaSuvislaA->get(i, k) * maticaSuvislaB->get(k, j);
				spolu += sucet;
				maticaSuvislaC->set(i, j, spolu);
				
			}
			cout << maticaSuvislaC->get(i, j) << " ";
			spolu = 0;
		}
		cout << endl;
	}
	cout << endl;
}


