#pragma once
#include "LinkedArrayTest.h"
#include "Matrix.h"
#include "structures/list/array_list.h"
#include <iostream>
#include <fstream>

using namespace structures;

int main(char* arc, char** argv) {

	Matrix matica;
	//matica.Spocitaj(0);
	matica.Vynasob(0);

	int x;
	std::cout << "Vyber list test!" << endl;
	std::cout << "1 = ArrayList || 2 = LinkedList" << endl;
	cin >> x;
	if (x == 1) {
		int y;
		std::cout << "Vyber scenar!" << endl;
		std::cout << "stlac 1 pre scenar A || 2 pre scenar B || 3 pre scenar C" << endl;
		cin >> y;
		if(y == 1) {
			LinkedArrayTest objekt;
			objekt.VyberListTest(0);
			objekt.VyberScenar(0);
			objekt.Spusti(0);
		}
		if (y == 2) {
			LinkedArrayTest objekt;
			objekt.VyberListTest(0);
			objekt.VyberScenar(1);
			objekt.Spusti(0);
		}
		if (y == 3) {
			LinkedArrayTest objekt;
			objekt.VyberListTest(0);
			objekt.VyberScenar(2);
			objekt.Spusti(0);
		}
		
	}
	if(x == 2)
	{
		int y;
		std::cout << "Vyber scenar!" << endl;
		std::cout << "stlac 1 pre scenar A || 2 pre scenar B || 3 pre scenar C" << endl;
		cin >> y;
		if (y == 1) {
			LinkedArrayTest objekt;
			objekt.VyberListTest(1);
			objekt.VyberScenar(0);
			objekt.Spusti(1);
		}
		if (y == 2) {
			LinkedArrayTest objekt;
			objekt.VyberListTest(1);
			objekt.VyberScenar(1);
			objekt.Spusti(1);
		}
		if (y == 3) {
			LinkedArrayTest objekt;
			objekt.VyberListTest(1);
			objekt.VyberScenar(2);
			objekt.Spusti(1);
		}
	}
	else if(x != 1 || x != 2)
	{
		std::cout << "Nevybrali ste si ziadny test!" << endl;
	}
	return -1;


}


