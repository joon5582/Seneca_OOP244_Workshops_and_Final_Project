// Workshop 5:
// Version: 1.0
// Date: 2021-06-03
// Author: Fardad Soleimanloo
// Description:
// This file tests the DIY section of your workshop
/////////////////////////////////////////////

#include <iostream>
#include "Mark.h"
using namespace std;

int val = 3;
class Foo {
	int data;
public:
	Foo() {
		cout << (data = val++);
	}
	~Foo() {
		cout << data;
	}
	void operator+=(int d) {
		cout << (data += d);
	}
};
int main() {
	Foo* p = new Foo[2];
	for (int i = 0; i < 2; i++)
		p[i] += (i + 1);
   return 0;
}