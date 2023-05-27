#include "Hashtable.h"
#include <iostream>
#include "list.h"
using namespace std;

int main() {
	Hashtable Ht(17);
	for (int i = 0; i < 20; i++) {
		Ht.insert(i);
	}
	cout << Ht.lookup(18);
	Ht.erase(18);
	cout << endl;
	cout << Ht.lookup(18);
	return 0;
}