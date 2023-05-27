#include "Hashtable.h"
#include <iostream>
#include "list.h"
using namespace std;

Hashtable::Hashtable() {
	cap = 17;
	HTable = new LList[cap];
}

Hashtable::Hashtable(int c) {
	cap = c;
	HTable = new LList[cap];
}

Hashtable::Hashtable(Hashtable& H) {
	cap = H.cap;
	H.HTable = new LList[H.cap];
	for (int i = 0; i < cap; i++) {
		H.HTable[i] = HTable[i];
	}
}

Hashtable::~Hashtable() {
	delete[]HTable;
}

int Hashtable::HashFunction(int item) {
	return (item % cap);
}

void Hashtable::insert(int item) {
	HTable[HashFunction(item)].addAtEnd(item);
}

void Hashtable::erase(int item) {
	if (!lookup(item)) {
		cout << "Element does not exist for erasing\n";
	}
	else {
		HTable[HashFunction(item)].findToErase(item);
	}
}

bool Hashtable::lookup(int item) {
	return HTable[HashFunction(item)].find(item);
}
