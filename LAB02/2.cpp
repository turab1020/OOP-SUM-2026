#include <iostream>
using namespace std;

void ptrSwap(int* a, int* b) {
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

int ptrMul(int* a, int* b) {
	int m;

	m = *a * *b;

	return m;
}

int main() {
	int a, b;

	cout << "Num 1: ";
	cin >> a;

	cout << "Num 2: ";
	cin >> b;

	ptrSwap(&a, &b);

	int m;

	m = ptrMul(&a, &b);

	cout << "\n--- Swapped ---\n";
	cout << "Num 1: " << a << endl;
	cout << "Num 2: " << b << endl;

	cout << "\n--- Multiplication ---\n";
	cout << a << " x " << b << ": " << m << endl;
}