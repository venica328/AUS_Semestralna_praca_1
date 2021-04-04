#include "PriorityQueueTest.h"
#include <chrono>
#include <fstream>
#include <iostream>


using namespace structures;
using namespace std;

std::chrono::duration<double> pushVysledok;
std::chrono::duration<double> popVysledok;
std::chrono::duration<double> peekVysledok;

double B;
double Bb;
double Bbb;
int podielB;
int podielBb;
int podielBbb;
int podielBbbb;

PriorityQueueTest::PriorityQueueTest()
{
}

int PriorityQueueTest::VyberTest(int volba)
{
	switch (volba) {
	case 1:
		queue = new Heap<int>();
		return 1;
		break;
	case 2:
		queue = new PriorityQueueSortedArrayList<int>();
		return 2;
		break;
	default:
		return 0;
	}
	return 0;
}

int PriorityQueueTest::VyberScenar(int scenar)
{
	switch (scenar) {
	case 1:
		B = 0.35;
		Bb = 0.7;
		Bbb = 1;
		podielB = 35000;
		podielBb = 35000;
		podielBbb = 30000;
		return 1;
		break;
	case 2:
		B = 0.5;
		Bb = 0.80;
		podielB = 50000;
		podielBb = 30000;
		podielBbb = 20000;
		return 2;
		break;
	case 3:
		B = 0.7;
		Bb = 0.95;
		podielB = 70000;
		podielBb = 25000;
		podielBbb = 5000;
		return 3;
		break;
	default:
		return -1;
	}
	return 0;
}

void PriorityQueueTest::Spusti(int test)
{
	int pocetPush = 0;
	int pocetPop = 0;
	int pocetPeek = 0;
	
	auto start = std::chrono::high_resolution_clock::now();
	while (pocetPush + pocetPop + pocetPeek < 100000 && (pocetPush < podielB || pocetPop < podielBb))
	{
		int priorita = rand() % 10000;
		int data = rand() % 100 + 1;
		double random = (rand() % 100) / 100.0;
		int operacia = rand() % 3;

		switch (operacia)
		{
		case 0:
			if (pocetPush < podielB) {
				auto pushStartTime = std::chrono::high_resolution_clock::now();

				queue->push(priorita, data);
				std::cout << "Vlozilo sa cislo: " << data << " s prioritou: " << priorita << endl;
				std::cout << queue->size() << endl;

				auto pushKoniecTime = std::chrono::high_resolution_clock::now();
				std::chrono::duration<double> vysledokPush = std::chrono::duration_cast<std::chrono::microseconds>(pushKoniecTime - pushStartTime);
				pushVysledok = pushVysledok + vysledokPush;
				pocetPush++;
			}
			else {
				break;
			}

		case 1:
			if (pocetPeek < podielBbb && queue->size() > 0)
			{
				auto peekStartTime = std::chrono::high_resolution_clock::now();
				queue->peek();
				std::cout << "Ukaz sa cislo: " << endl;
				std::cout << queue->size() << endl;

				auto peekKoniecTime = std::chrono::high_resolution_clock::now();
				std::chrono::duration<double> vysledokPeek = std::chrono::duration_cast<std::chrono::microseconds>(peekKoniecTime - peekStartTime);
				peekVysledok = peekVysledok + vysledokPeek;
				pocetPeek++;
			}
			break;

		case 2:
			if (pocetPop < podielBb && queue->size() > 0)
			{
				auto popStartTime = std::chrono::high_resolution_clock::now();

				queue->pop();
				std::cout << "Vybralo sa cislo!" << endl;
				std::cout << queue->size() << endl;

				auto popKoniecTime = std::chrono::high_resolution_clock::now();
				std::chrono::duration<double> vysledokPop = std::chrono::duration_cast<std::chrono::microseconds>(popKoniecTime - popStartTime);
				popVysledok = popVysledok + vysledokPop;
				pocetPop++;
			}
			break;
		default:
			break;
		}

	}
	auto koniec = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> vysledok = koniec - start;

	std::cout << endl;
	std::cout << "Celkovy cas: " << vysledok.count() << " vykonanych operacii spolu: " << pocetPush + pocetPop + pocetPeek << endl;
	std::cout << "Celkovy cas operacie push: " << pushVysledok.count() << " vykonanych operacii insert bolo: " << pocetPush << endl;
	std::cout << "Celkovy cas operacie pop: " << popVysledok.count() << " vykonanych operacii remove bolo: " << pocetPop << endl;
	std::cout << "Celkovy cas operacie peek: " << peekVysledok.count() << " vykonanych operacii nastav bolo: " << pocetPeek << endl;
}

PriorityQueueTest::~PriorityQueueTest()
{
	queue->clear();
	delete queue;
}
