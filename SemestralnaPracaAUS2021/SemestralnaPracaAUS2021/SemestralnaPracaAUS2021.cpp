#pragma once
#include "LinkedArrayTest.h"
#include "PriorityQueueTest.h"
#include "Matrix.h"
#include "structures/list/array_list.h"
#include "structures/heap_monitor.h"
#include <iostream>
#include <fstream>

using namespace structures;

void SpustiListTest(int test, int scenar)
{
	LinkedArrayTest* objekt = new LinkedArrayTest();
	objekt->VyberListTest(test);
	objekt->VyberScenar(scenar);
	objekt->Spusti(test);
	delete objekt;
}

void SpustiTestQueue(int test, int scenar)
{
	PriorityQueueTest* objekt = new PriorityQueueTest();
	objekt->VyberTest(test);
	objekt->VyberScenar(scenar);
	objekt->Spusti(test);
	delete objekt;
}

void SpustiTestMaticaSpocitaj(int test, int scenar)
{
	Matrix* objekt = new Matrix();
	objekt->VyberTest(test);
	objekt->VyberScenar(scenar);
	objekt->Spocitaj(test);
	delete objekt;
}

void SpustiTestMaticaVynasob(int test, int scenar)
{
	Matrix* objekt = new Matrix();
	objekt->VyberTest(test);
	objekt->VyberScenar(scenar);
	objekt->Vynasob(test);
	delete objekt;
}

int main(char* arc, char** argv) {
	initHeapMonitor();
	int x = 1, y;

	while (x != 0)
	{
		std::cout << "\nVyber test!\n"
				  << "1 = ArrayList || 2 = LinkedList || 3 = CyclicList\n"
				  << "4 = Matica - suvisla pamat || 5 = Matica - nesuvisla pamat\n"
				  << "6 = Heap || 7 = Zoznam podla priorit\n"
				  << "0 = Koniec" << endl;
		cin >> x;

		switch (x)
		{
			case 0:
				std::cout << "Koniec..." << endl;
				break;

			case 1:
				std::cout << "Vyber scenar!" << endl;
				std::cout << "stlac 1 pre scenar A || 2 pre scenar B || 3 pre scenar C" << endl;
				cin >> y;

				switch (y)
				{
				case 1:
					SpustiListTest(1, 0);
					break;

				case 2:
					SpustiListTest(1, 1);
					break;

				case 3:
					SpustiListTest(1, 2);
					break;

				default:
					std::cout << "Zadali ste zlu hodnotu!" << endl;
					break;
				}
				break;

			case 2:
				std::cout << "Vyber scenar!" << endl;
				std::cout << "stlac 1 pre scenar A || 2 pre scenar B || 3 pre scenar C" << endl;
				cin >> y;

				switch (y)
				{
				case 1:
					SpustiListTest(2, 0);
					break;

				case 2:
					SpustiListTest(2, 1);
					break;

				case 3:
					SpustiListTest(2, 2);
					break;

				default:
					std::cout << "Zadali ste zlu hodnotu!" << endl;
					break;
				}
				break;

			case 3:
				std::cout << "Vyber scenar!" << endl;
				std::cout << "stlac 1 pre scenar A || 2 pre scenar B || 3 pre scenar C" << endl;
				cin >> y;

				switch (y)
				{
				case 1:
					SpustiListTest(3, 0);
					break;

				case 2:
					SpustiListTest(3, 1);
					break;

				case 3:
					SpustiListTest(3, 2);
					break;

				default:
					std::cout << "Zadali ste zlu hodnotu!" << endl;
					break;
				}
				break;

			case 4:
				std::cout << "Vyber scenar!" << endl;
				std::cout << "stlac 1 pre scenar A = sucet matic || 2 pre scenar B = nasobenie matic" << endl;
				cin >> y;

				switch (y)
				{
				case 1:
					SpustiTestMaticaSpocitaj(1, 1);
					break;

				case 2:
					SpustiTestMaticaVynasob(1, 2);
					break;

				default:
					std::cout << "Zadali ste zlu hodnotu!" << endl;
					break;
				}
				break;

			case 5:
				std::cout << "Vyber scenar!" << endl;
				std::cout << "stlac 1 pre scenar A = sucet matic || 2 pre scenar B = nasobenie matic" << endl;
				cin >> y;

				switch (y)
				{
				case 1:
					SpustiTestMaticaSpocitaj(2, 1);
					break;

				case 2:
					SpustiTestMaticaVynasob(2, 2);
					break;

				default:
					std::cout << "Zadali ste zlu hodnotu!" << endl;
					break;
				}
				break;

			case 6:
				std::cout << "Vyber scenar pre Heap!" << endl;
				std::cout << "stlac 1 pre scenar A || 2 pre scenar B || 3 pre scenar C" << endl;
				cin >> y;

				switch (y)
				{
				case 1:
					SpustiTestQueue(1, 1);
					break;

				case 2:
					SpustiTestQueue(1, 2);
					break;

				case 3:
					SpustiTestQueue(1, 3);
					break;

				default:
					std::cout << "Zadali ste zlu hodnotu!" << endl;
					break;
				}
				break;

			case 7:
				std::cout << "Vyber scenar pre zoznam implementovany polom!" << endl;
				std::cout << "stlac 1 pre scenar A || 2 pre scenar B || 3 pre scenar C" << endl;
				cin >> y;

				switch (y)
				{
				case 1:
					SpustiTestQueue(2, 1);
					break;

				case 2:
					SpustiTestQueue(2, 2);
					break;

				case 3:
					SpustiTestQueue(2, 3);
					break;

				default:
					std::cout << "Zadali ste zlu hodnotu!" << endl;
					break;
				}
				break;

			default:
				std::cout << "Zadali ste zlu hodnotu!" << endl;
				break;
		}
	}
	
	return 0;
}
