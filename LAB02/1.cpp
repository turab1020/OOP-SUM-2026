#include <iostream>
using namespace std;

int main() {
	int a, b, s;

	cout << "Num 1: ";
	cin >> a;

	cout << "Num 2: ";
	cin >> b;

	s = a + b;

	cout << "\nSum: " << s << endl;

	cout << "\n--- ADDRESSES ---\n";

	cout << "Num 1: " << &a << endl;
	cout << "Num 2: " << &b << endl;

	cout << "\nSum: " << &s << endl;
}