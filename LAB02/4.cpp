#include <iostream>
using namespace std;

int* resetToZero(int* p) {
	*p = 0;

	return p;
}

int main() {
	int p = 10;

	cout << "Before reset: " << p << endl;

	resetToZero(&p);

	cout << "Ater reset: " << p << endl;
}