#pragma once
#include "structures/priority_queue/priority_queue_list.h"
#include "structures/priority_queue/heap.h"
#include "structures/priority_queue/priority_queue_sorted_array_list.h"

class PriorityQueueTest
{
private:
	structures::PriorityQueueList<int>* queue = nullptr;
public:
	PriorityQueueTest();
	~PriorityQueueTest();

	int VyberTest(int volba);
	int VyberScenar(int scenar);
	void Spusti(int test);
	bool ExistujeSubor(const std::string fileName);
};

