#include <iostream>
using namespace std;

void remSwap(int& a, int& b) {
	a = a + b;
	b = a - b;
	a = a - b;
}

int main() {
	int a, b;

	cout << "Num 1: ";
	cin >> a;

	cout << "Num 2: ";
	cin >> b;

	remSwap(a, b);

	cout << "\n--- Swapped ---\n";
	cout << "Num 1: " << a << endl;
	cout << "Num 2: " << b << endl;
}