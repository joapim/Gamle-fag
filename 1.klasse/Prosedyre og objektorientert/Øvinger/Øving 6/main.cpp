#include <iostream>
#include "Car.h"
#include "Person.h"
using namespace std;

int main() {
	Person a("Hans", "e-post");
	Person b("Olav", "e-post");

	if (a < b) {
		cout << b << endl;
	}
}
