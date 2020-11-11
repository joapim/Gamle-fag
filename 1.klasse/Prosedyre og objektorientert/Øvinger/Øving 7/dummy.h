#pragma once
#include <iostream>
using namespace std;
class Dummy;
class Dummy {
public:
	int *num;
	Dummy() {
		num = new int(0);
	}
	~Dummy() {
		delete num;
	}
	int get() const { return *num; }

	Dummy(const Dummy &dum) : num(nullptr) {
		this->num = new int();
		*num = dum.get();
	}

	Dummy &operator=(Dummy rhs) {
		swap(num, rhs.num);
		return *this;
	}
};



void dummyTest();
