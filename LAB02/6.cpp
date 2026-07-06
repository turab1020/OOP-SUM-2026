#include <iostream>
using namespace std;

int& Power(int &a) {
	a = a + 10;

	return a;
}

int main() {
	int a = 12;

	cout << "original: " << a << endl;

	Power(a);

	cout << "(power +10) returned reference: " << a << endl;

	int& b = Power(a);
	b = 100;

	cout << "modified returned reference: " << b << endl;
}