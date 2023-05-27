#pragma once
#include <iostream>
#include "list.h"
using namespace std;

class Hashtable{
private:
	LList* HTable;
	int HashFunction(int);
	int cap;
public:
	Hashtable();
	Hashtable(int);
	Hashtable(Hashtable&);
	~Hashtable();
	void insert(int);
	void erase(int);
	bool lookup(int);
};

