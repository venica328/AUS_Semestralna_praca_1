#pragma once
#include "LinkedArrayTest.h"
#include "PriorityQueueTest.h"
#include "Matrix.h"
#include "structures/list/array_list.h"
#include "structures/heap_monitor.h"
#include <iostream>
#include <fstream>

using namespace structures;

int main(char* arc, char** argv) {
	initHeapMonitor();
	
	int x;
	std::cout << "Vyber test!" << endl;
	std::cout << "1 = ArrayList || 2 = LinkedList || 3 = CyclicList" << endl;
	std::cout << "4 = Matica - suvisla pamat || 5 = Matica - nesuvisla pamat" << endl;
	std::cout << "6 = Heap || 7 = Zoznam podla priorit" << endl;
	cin >> x;
	if (x == 1) {
		int y;
		std::cout << "Vyber scenar!" << endl;
		std::cout << "stlac 1 pre scenar A || 2 pre scenar B || 3 pre scenar C" << endl;
		cin >> y;
		if(y == 1) {
			LinkedArrayTest *objekt = new LinkedArrayTest();
			objekt->VyberListTest(1);
			objekt->VyberScenar(0);
			objekt->Spusti(1);
			delete objekt;
		}
		if (y == 2) {
			LinkedArrayTest* objekt = new LinkedArrayTest();
			objekt->VyberListTest(1);
			objekt->VyberScenar(1);
			objekt->Spusti(1);
			delete objekt;
		}
		if (y == 3) {
			LinkedArrayTest* objekt = new LinkedArrayTest();
			objekt->VyberListTest(1);
			objekt->VyberScenar(2);
			objekt->Spusti(1);
			delete objekt;
		}
		
	}
	if(x == 2)
	{
		int y;
		std::cout << "Vyber scenar!" << endl;
		std::cout << "stlac 1 pre scenar A || 2 pre scenar B || 3 pre scenar C" << endl;
		cin >> y;
		if (y == 1) {
			LinkedArrayTest* objekt = new LinkedArrayTest();
			objekt->VyberListTest(2);
			objekt->VyberScenar(0);
			objekt->Spusti(2);
			delete objekt;
		}
		if (y == 2) {
			LinkedArrayTest* objekt = new LinkedArrayTest();
			objekt->VyberListTest(2);
			objekt->VyberScenar(1);
			objekt->Spusti(2);
			delete objekt;
		}
		if (y == 3) {
			LinkedArrayTest* objekt = new LinkedArrayTest();
			objekt->VyberListTest(2);
			objekt->VyberScenar(2);
			objekt->Spusti(2);
			delete objekt;
		}
	}
	if (x == 3)
	{
		int y;
		std::cout << "Vyber scenar!" << endl;
		std::cout << "stlac 1 pre scenar A || 2 pre scenar B || 3 pre scenar C" << endl;
		cin >> y;
		if (y == 1) {
			LinkedArrayTest* objekt = new LinkedArrayTest();
			objekt->VyberListTest(3);
			objekt->VyberScenar(0);
			objekt->Spusti(3);
			delete objekt;
		}
		if (y == 2) {
			LinkedArrayTest* objekt = new LinkedArrayTest();
			objekt->VyberListTest(3);
			objekt->VyberScenar(1);
			objekt->Spusti(3);
			delete objekt;
		}
		if (y == 3) {
			LinkedArrayTest* objekt = new LinkedArrayTest();
			objekt->VyberListTest(3);
			objekt->VyberScenar(2);
			objekt->Spusti(3);
			delete objekt;
		}
	}
	if (x == 4)
	{
		int y;
		std::cout << "Vyber scenar!" << endl;
		std::cout << "stlac 1 pre scenar A = sucet matic || 2 pre scenar B = nasobenie matic" << endl;
		cin >> y;
		if (y == 1) {
			Matrix* objekt = new Matrix();
			objekt->VyberTest(1);
			objekt->VyberScenar(1);
			objekt->Spocitaj(1);
			delete objekt;
		}
		if (y == 2) {
			Matrix* objekt = new Matrix();
			objekt->VyberTest(1);
			objekt->VyberScenar(2);
			objekt->Vynasob(1);
			delete objekt;
		}
	}
	if (x == 5)
	{
		int y;
		std::cout << "Vyber scenar!" << endl;
		std::cout << "stlac 1 pre scenar A = sucet matic || 2 pre scenar B = nasobenie matic" << endl;
		cin >> y;
		if (y == 1) {
			Matrix* objekt = new Matrix();
			objekt->VyberTest(2);
			objekt->VyberScenar(1);
			objekt->Spocitaj(2);
			delete objekt;
		}
		if (y == 2) {
			Matrix* objekt = new Matrix();
			objekt->VyberTest(2);
			objekt->VyberScenar(2);
			objekt->Vynasob(2);
			delete objekt;
		}
	}
	if (x == 6)
	{
		int y;
		std::cout << "Vyber scenar pre Heap!" << endl;
		std::cout << "stlac 1 pre scenar A || 2 pre scenar B || 3 pre scenar C" << endl;
		cin >> y;
		if (y == 1) {
			PriorityQueueTest* objekt = new PriorityQueueTest();
			objekt->VyberTest(1);
			objekt->VyberScenar(1);
			objekt->Spusti(1);
			delete objekt;
		}
		if (y == 2) {
			PriorityQueueTest* objekt = new PriorityQueueTest();
			objekt->VyberTest(1);
			objekt->VyberScenar(2);
			objekt->Spusti(1);
			delete objekt;
		}
		if (y == 3) {
			PriorityQueueTest* objekt = new PriorityQueueTest();
			objekt->VyberTest(1);
			objekt->VyberScenar(3);
			objekt->Spusti(1);
			delete objekt;
		}
	}
	if (x == 7)
	{
		int y;
		std::cout << "Vyber scenar pre zoznam implementovany polom!" << endl;
		std::cout << "stlac 1 pre scenar A || 2 pre scenar B || 3 pre scenar C" << endl;
		cin >> y;
		if (y == 1) {
			PriorityQueueTest* objekt = new PriorityQueueTest();
			objekt->VyberTest(2);
			objekt->VyberScenar(1);
			objekt->Spusti(2);
			delete objekt;
		}
		if (y == 2) {
			PriorityQueueTest* objekt = new PriorityQueueTest();
			objekt->VyberTest(2);
			objekt->VyberScenar(2);
			objekt->Spusti(2);
			delete objekt;
		}
		if (y == 3) {
			PriorityQueueTest* objekt = new PriorityQueueTest();
			objekt->VyberTest(2);
			objekt->VyberScenar(3);
			objekt->Spusti(2);
			delete objekt;
		}
	}
	else if(x != 1 || x!= 2 || x!= 3)
	{
		std::cout << "Nevybrali ste si ziadny test!" << endl;
	}
	
	return 0;
}


