#include <iostream>
using namespace std;

void cubeByPtr(int* p) {
	*p = *p * *p * *p;
}

void cubeByRef(int &r) {
	r = r * r * r;
}

int main() {
	int aPtr = 2;
	int	aRef = 2;

	cout << "--- Cube By Pointer ---\n";
	cubeByPtr(&aPtr);
	cout << "aPtr: " << aPtr << endl;

	cout << "\n--- Cube By Reference ---\n";
	cubeByRef(aRef);
	cout << "aRef: " << aRef << endl;
}