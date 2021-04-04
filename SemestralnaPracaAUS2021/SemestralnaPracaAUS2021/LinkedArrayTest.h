#pragma once
#include "structures/list/list.h";
#include "ADT.h";
#include "../Casovac.h";

class LinkedArrayTest
{
private:
	structures::List<int>* list = nullptr;
public:
	LinkedArrayTest();
	int VyberListTest(int volba);
	int VyberScenar(int scenar);

	void Spusti(int test);
	bool ExistujeSubor(const std::string fileName);

	~LinkedArrayTest();
};

