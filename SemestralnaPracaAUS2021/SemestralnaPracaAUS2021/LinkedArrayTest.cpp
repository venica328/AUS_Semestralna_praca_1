#include "LinkedArrayTest.h"
#include "structures/list/array_list.h"
#include "structures/list/linked_list.h"
#include "structures/list/cyclic_list.h"
#include <chrono>
#include <fstream>

using namespace structures;
double timeInsert;
std::chrono::duration<double> insertVysledok;
std::chrono::duration<double> removeVysledok;
std::chrono::duration<double> setVysledok;
std::chrono::duration<double> indexVysledok;

double defaultLow = 0;
double A;
double Aa;
double Aaa;
double defaultHigh;
int podielA;
int podielAa;
int podielAaa;
int podielAaaa;


string fileName = "";
ofstream MyFile(fileName);


LinkedArrayTest::LinkedArrayTest()
{
}

LinkedArrayTest::~LinkedArrayTest()
{
	cout << "idem do destructure" << endl;
	list->clear();
	delete list;
	list = nullptr;
	
}

int LinkedArrayTest::VyberListTest(int volba)
{
	switch (volba) {
	case 1:
		list = new ArrayList<int>();
		return 1;
		break;
	case 2:
		list = new LinkedList<int>();
		return 2;
		break;
	case 3:
		list = new CyclicList<int>();
		return 3;
		break;
	default:
		return 0;
	}
	return -1;
}

int LinkedArrayTest::VyberScenar(int scenar)
{
	switch (scenar) {
	case 0:
		defaultLow = 0;
		A = 0.2;
		Aa = 0.4;
		Aaa = 0.9;
		defaultHigh = 1;
		podielA = 20000;
		podielAa = 20000;
		podielAaa = 50000;
		podielAaaa = 10000;
		return 0;
		break;
	case 1:
		defaultLow = 0;
		A = 0.35;
		Aa = 0.70;
		Aaa = 0.90;
		defaultHigh = 1;
		podielA = 35000;
		podielAa = 35000;
		podielAaa = 20000;
		podielAaaa = 10000;
		return 1;
		break;
	case 2:
		defaultLow = 0;
		A = 0.45;
		Aa = 0.90;
		Aaa = 0.95;
		defaultHigh = 1;
		podielA = 45000;
		podielAa = 45000;
		podielAaa = 5000;
		podielAaaa = 5000;
		return 2;
		break;
	default:
		return -1;
	}
	return 0;
}

void LinkedArrayTest::Spusti(int test)
{
	int pocetInsert = 0;
	int pocetZmaz = 0;
	int pocetNastav = 0;
	int pocetIndex = 0;

	//VyberListTest(test);
	if (test == 1) {
		std::cout << "Zvoleny test: ArrayList" << endl;
		fileName = "ArrayListTest.csv";
	}
	else if(test == 2)
	{
		std::cout << "Zvoleny test: LinkedList" << endl;
		fileName = "LinkedListTest.csv";
	}
	else if (test == 3)
	{
		std::cout << "Zvoleny test: CyclicList" << endl;
		fileName = "CyclicListTest.csv";
	}
	
	ofstream MyFile(fileName);	
	auto start = std::chrono::high_resolution_clock::now();

	while(pocetInsert+pocetZmaz+pocetNastav+pocetIndex < 100000 && (pocetInsert < podielA || pocetZmaz < podielAa)) {

		int random = (rand() % 3) + 1;
		int randomSet = (rand() % 2) + 1;
		int nastavCislo = (rand() % 100 + 1);
		double randomChoose = (rand() % 100) / 100.0;
		
		if (randomChoose >= defaultLow && randomChoose < A && pocetInsert < podielA) {
			auto insertStartTime = std::chrono::high_resolution_clock::now();
			switch (random)
			{
			case 1:
				list->insert(nastavCislo, 0);
				std::cout << "vlozilo sa cislo na index 0.. velkost listu: " << list->size() << endl;
				break;
			case 2:
				list->add(nastavCislo);
				std::cout << "vlozilo sa cislo na koniec.. velkost listu: " << list->size() << endl;
				break;
			case 3:
				list->insert(nastavCislo, (list->size() == 0 ? 0 : rand() % list->size()));
				std::cout << "vlozilo sa cislo na nahodny index.. velkost listu: " << list->size() << endl;
				break;
			default:
				break;
			}
			auto insertKoniecTime = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> vysledokInsert = std::chrono::duration_cast<std::chrono::microseconds>(insertKoniecTime - insertStartTime);
			insertVysledok = insertVysledok + vysledokInsert;
			pocetInsert++;
			
		}
		else if ((randomChoose >= A && randomChoose < Aa) && list->size() > 0 && pocetZmaz < podielAa)
		{
			auto removeStartTime = std::chrono::high_resolution_clock::now();
			switch (random)
			{
			case 1:
				list->removeAt(0);
				std::cout << "zmazalo sa cislo na indexe 0.. velkost listu: " << list->size() << endl;
				break;
			case 2:
				list->removeAt(list->size()-1);
				std::cout << "zmazalo sa cislo na poslednom indexe.. velkost listu: " << list->size() << endl;
				break;
			case 3:
				std::cout << "zmazalo sa cislo na tomto random indexe: " << list->removeAt(rand() % list->size()) << endl;
				break;
			default:
				break;
			}
			auto removeKoniecTime = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> vysledokRemove = std::chrono::duration_cast<std::chrono::microseconds>(removeKoniecTime - removeStartTime);
			removeVysledok = removeVysledok + vysledokRemove;
			pocetZmaz++;
		}
		 else if ((randomChoose >= Aa && randomChoose < Aaa) && list->size() > 0 && pocetNastav < podielAaa)
		{
			auto setStartTime = std::chrono::high_resolution_clock::now();
			int index = rand() % list->size();
			switch (randomSet)
			{
			case 1:
				std::cout << "cislo na tomto indexe sa spristupnilo: " << (*list)[index] << endl;
				break;
			case 2:
				(*list)[index] = nastavCislo;
				std::cout << "cislo sa nastavilo na tomto indexe: " << index << endl;
				break;
			default:
				break;
			}
			auto setKoniecTime = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> vysledokSet = std::chrono::duration_cast<std::chrono::microseconds>(setKoniecTime - setStartTime);
			setVysledok = setVysledok + vysledokSet;
			pocetNastav++;
		}
		 else if ((randomChoose >= Aaa && randomChoose < defaultHigh) && list->size() > 0 && pocetIndex < podielAaaa)
		{
			auto indexStartTime = std::chrono::high_resolution_clock::now();
			std::cout << "zistilo ci sa cislo nachadza v poli" << list->getIndexOf(rand() % list->size()) << endl;

			auto indexKoniecTime = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> vysledokIndex = std::chrono::duration_cast<std::chrono::microseconds>(indexKoniecTime - indexStartTime);
			indexVysledok = indexVysledok + vysledokIndex;
			pocetIndex++;
		}
		
	}

	auto koniec = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> vysledok = koniec - start;

	std::cout << endl;
	std::cout << "Celkovy cas: " << vysledok.count() << " vykonanych operacii spolu: " << pocetInsert + pocetZmaz + pocetNastav + pocetIndex << endl;
	std::cout << "Celkovy cas operacie insert: " << insertVysledok.count() << " vykonanych operacii insert bolo: " << pocetInsert<< endl;
	std::cout << "Celkovy cas operacie remove: " << removeVysledok.count() << " vykonanych operacii remove bolo: " << pocetZmaz<< endl;
	std::cout << "Celkovy cas operacie set: " << setVysledok.count() << " vykonanych operacii nastav bolo: " << pocetNastav<< endl;
	std::cout << "Celkovy cas operacie index: " << indexVysledok.count() << " vykonanych operacii index bolo: " << pocetIndex<< endl;
	/**
	MyFile << "Po�et v�etk�ch oper�ci�: " << ";" << pocetInsert + pocetZmaz + pocetNastav + pocetIndex << ";" << "�asov� n�ro�nos�: " << ";" << vysledok.count() << endl;
	MyFile << "Po�et insert oper�ci�: " << ";" <<pocetInsert << ";" << "�asov� n�ro�nos�: " << ";" << insertVysledok.count() <<endl;
	MyFile << "Po�et remove oper�ci�: " << ";" <<pocetZmaz << ";" << "�asov� n�ro�nos�: " << ";" << removeVysledok.count() <<endl;
	MyFile << "Po�et set oper�ci�: " << ";" <<pocetNastav << ";" << "�asov� n�ro�nos�: " << ";" << setVysledok.count() <<endl;
	MyFile << "Po�et index oper�ci�: " << ";" <<pocetIndex << ";" << "�asov� n�ro�nos�: " << ";" << indexVysledok.count() <<endl;
	**/

	MyFile << "Po�et v�etk�ch oper�ci�: " << ";" << "Po�et insert oper�ci�: " << ";" << "Po�et remove oper�ci�: " << ";" << "Po�et set oper�ci�: " << ";" << "Po�et index oper�ci�: " << endl;
	MyFile << pocetInsert + pocetZmaz + pocetNastav + pocetIndex << ";" << pocetInsert << ";" << pocetZmaz << ";" << pocetNastav << ";" << pocetIndex << endl;
	MyFile << endl;
	MyFile << "�asov� n�ro�nos�: " << ";" << "V�ETKY OPER�CIE: " << ";" << "INSERT: " << ";" << "REMOVE: " << ";" << "SET: " << ";" << "INDEX: " << endl;
	MyFile << "" << ";" << vysledok.count() << ";" << insertVysledok.count() << ";" << removeVysledok.count() << ";" << setVysledok.count() << ";" << indexVysledok.count() << endl;

	MyFile.close();
}




	
