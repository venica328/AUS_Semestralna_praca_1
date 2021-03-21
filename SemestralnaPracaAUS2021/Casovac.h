#pragma once
#include <chrono>

class Casovac
{
public:
	Casovac() {};
	~Casovac() {};


	void spolu() {
		auto start = std::chrono::high_resolution_clock::now();
		auto koniec = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, std::milli> vysledok = start - koniec;
	}
	


private:

};





