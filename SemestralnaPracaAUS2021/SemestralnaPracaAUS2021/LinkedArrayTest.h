#pragma once
#include "structures/list/array_list.h";
#include "structures/list/list.h";
#include "ADT.h";
#include "../Casovac.h";


class LinkedArrayTest
{
private:
	structures::List<int>* list;
public:
	LinkedArrayTest();
	~LinkedArrayTest() {};

	int VyberListTest(int volba);
	int VyberScenar(int scenar);

	void Spusti(int test);
	


};

