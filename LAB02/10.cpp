#include <iostream>
using namespace std;

int charSize(const char* arr) {
	int i = 0;
	int size = 0;

	while (arr[i] != '\0') {
		i++;
		size++;
	}

	return size;
}

void concat(const char* src, char* dest) {
	int srcLen = charSize(src);
	int destLen = charSize(dest);

	int shift = srcLen + 1;
	char* moveFrom = dest + destLen;
	char* moveTo = moveFrom + shift;

	while (moveFrom >= dest) {
		*moveTo = *moveFrom;
		moveTo--;
		moveFrom--;
	}

	const char* sPtr = src;
	char* dPtr = dest;

	while (*sPtr != '\0') {
		*dPtr = *sPtr;
		dPtr++;
		sPtr++;
	}

	*dPtr = ' ';
}

int main() {
	const char src[] = "Dexter";
	char dest[30] = "Laboratory";

	concat(src, dest);

	cout << dest;
}