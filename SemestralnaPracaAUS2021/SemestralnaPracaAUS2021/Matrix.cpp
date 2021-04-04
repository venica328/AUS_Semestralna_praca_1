#include "Matrix.h"
#include "structures/array/array.h"
#include "suvislaMatica.h"
#include "nesuvislaMatica.h"
#include "matica.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <fstream>
#include <sys/stat.h>
#include <iomanip>
#include <string>
using namespace structures;
using namespace std;

std::chrono::duration<double> scenarA;
std::chrono::duration<double> scenarB;

Matrix::Matrix()
{
	
}

Matrix::~Matrix()
{
	delete matica1;
	delete matica2;
	delete matica3;
	delete maticaA;
	delete maticaB;
	delete maticaC;
	matica1 = nullptr;
	matica2 = nullptr;
	matica3 = nullptr;
	maticaA = nullptr;
	maticaB = nullptr;
	maticaC = nullptr;
}

int Matrix::VyberTest(int volba)
{
	int pocRiadkov = (rand() % 2000 + 1);
	int pocStlpcov = (rand() % 2000 + 1);
	int pocStlpcov2 = (rand() % 2000 + 1);

	switch (volba) {
	case 1:
		matica1 = new SuvislaMatica<int>(pocRiadkov, pocStlpcov);
		matica2 = new SuvislaMatica<int>(pocRiadkov, pocRiadkov);
		matica3 = new SuvislaMatica<int>(pocRiadkov, pocRiadkov);
		maticaA = new SuvislaMatica<int>(pocRiadkov, pocStlpcov2);
		maticaB = new SuvislaMatica<int>(pocStlpcov2, pocStlpcov);
		maticaC = new SuvislaMatica<int>(pocRiadkov, pocStlpcov);
		return 1;
		break;
	case 2:
		matica1 = new NesuvislaMatica<int>(pocRiadkov, pocRiadkov);
		matica2 = new NesuvislaMatica<int>(pocRiadkov, pocRiadkov);
		matica3 = new NesuvislaMatica<int>(pocRiadkov, pocRiadkov);
		maticaA = new NesuvislaMatica<int>(pocRiadkov, pocStlpcov2);
		maticaB = new NesuvislaMatica<int>(pocStlpcov2, pocStlpcov);
		maticaC = new NesuvislaMatica<int>(pocRiadkov, pocStlpcov);
		return 2;
		break;
	default:
		return 0;
	}
	return 0;
}

int Matrix::VyberScenar(int scenar)
{
	switch (scenar) {
	case 1:
		return 1;
		break;
	case 2:
		return 2;
		break;
	default:
		return 0;
	}
	return 0;
}

void Matrix::Spocitaj(int test)
{
	auto start = std::chrono::high_resolution_clock::now();
	cout << "MATICA 1 " << endl;
	for (int i = 0; i < matica1->getPocetRiadkov(); i++)
	{
		for (int j = 0; j < matica1->getPocetStlpcov(); j++)
		{
			int cislo = rand() % 2000 + 1;
			matica1->set(i, j, cislo);
			cout << matica1->get(i, j) << " " ;
		}
		cout << endl;
	}

	cout << endl;
	cout << "MATICA 2" << endl;
	for (int i = 0; i < matica2->getPocetRiadkov(); i++)
	{
		for (int j = 0; j < matica2->getPocetStlpcov(); j++)
		{
			int cislo = rand() % 2000 + 1;
			matica2->set(i, j, cislo);
			cout << matica2->get(i, j) << " ";
		}
		cout << endl;
	}

	cout << endl;
	cout << "MATICA sucet" << endl;
	for (int i = 0; i < matica3->getPocetRiadkov(); i++)
	{
		for (int j = 0; j < matica3->getPocetStlpcov(); j++)
		{
			int A = matica1->get(i,j);
			int B = matica2->get(i, j);
			int sucet = A + B;
			matica3->set(i, j, sucet);
			cout << matica3->get(i, j) << " ";
			sucet = 0;
			A = 0;
			B = 0;
		}
		cout << endl;
	}
	cout << endl;
	auto koniec = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> vysledok = koniec - start;

	std::cout << endl;
	if (test == 1) {
		std::cout << "Cas testu v suvislej pamati!" << endl;
	}
	else if (test == 2)
	{
		std::cout << "Cas testu v nesuvislej pamati!" << endl;
	}
	std::cout << "Celkovy cas: " << vysledok.count() << endl;

	ZapisDoSuboru("MaticaSpocitajTest.csv", vysledok);
}

void Matrix::Vynasob(int test)
{
	auto start = std::chrono::high_resolution_clock::now();
	cout << "MATICA A " << endl;
	for (int i = 0; i < maticaA->getPocetRiadkov(); i++)
	{
		for (int j = 0; j < maticaA->getPocetStlpcov(); j++)
		{
			int cislo = rand() % 2000 + 1;
			maticaA->set(i, j, cislo);
			cout << maticaA->get(i, j) << " ";
		}
		cout << endl;
	}

	cout << endl;
	cout << "MATICA B " << endl;
	for (int i = 0; i < maticaB->getPocetRiadkov(); i++)
	{
		for (int j = 0; j < maticaB->getPocetStlpcov(); j++)
		{
			int cislo = rand() % 2000 + 1;
			maticaB->set(i, j, cislo);
			cout << maticaB->get(i, j) << " ";
		}
		cout << endl;
	}

	cout << endl;
	cout << "MATICA C sucin" << endl;
	int spolu = 0;
	for (int i = 0; i < maticaA->getPocetRiadkov(); i++)
	{
		for (int j = 0; j < maticaB->getPocetStlpcov(); j++)
		{
			for (int k = 0; k < maticaB->getPocetRiadkov(); k++)
			{
				int sucet = maticaA->get(i, k) * maticaB->get(k, j);
				spolu += sucet;
				maticaC->set(i, j, spolu);
				
			}
			cout << maticaC->get(i, j) << " ";
			spolu = 0;
		}
		cout << endl;
	}
	cout << endl;
	auto koniec = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> vysledok = koniec - start;

	std::cout << endl;
	if (test == 1) {
		std::cout << "Cas testu v suvislej pamati!" << endl;
	}
	else if (test == 2)
	{
		std::cout << "Cas testu v nesuvislej pamati!" << endl;
	}
	std::cout << "Celkovy cas: " << vysledok.count() << endl;

	ZapisDoSuboru("MaticaVynasobTest.csv", vysledok);
}

void Matrix::ZapisDoSuboru(string fileName, std::chrono::duration<double> vysledok)
{
	if (!ExistujeSubor(fileName))
	{
		ofstream MyFile(fileName);
		MyFile << "Poèet riadkov: " << ";" << "Poèet ståpcov: " << ";" << "Celkový èas operácie: " << ";" << endl;
		MyFile.close();
	}

	ofstream MyFile(fileName, ios_base::app);
	string cas = to_string(vysledok.count());
	MyFile << matica3->getPocetRiadkov() << ";" << matica3->getPocetStlpcov() << ";" << cas.replace(cas.find("."), 1, ",") << endl;
	MyFile.close();
}

bool Matrix::ExistujeSubor(const string fileName) {
	ifstream subor;
	subor.open(fileName);
	return (bool)subor;
}
