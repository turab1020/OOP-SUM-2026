#include <iostream>
using namespace std;

int* comPow(int* arr, int n) {
	int* temp = new int[n];
	int sum = 0;

	for (int i = 0; i < n; i++) {
		sum += arr[i];
		temp[i] = sum;
	}

	return temp;
}

int main() {
	int n;
	int* powLvl;

	cout << "No. of Bananas eaten: ";
	cin >> n;

	powLvl = new int[n];

	cout << "Enter " << n << " Power Levels: ";

	for (int i = 0; i < n; i++) {
		cin >> powLvl[i];
	}

	int* result = comPow(powLvl, n);


	cout << "\nResult: ";

	for (int i = 0; i < n; i++) {
		cout << result[i] << " ";
	}
	cout << endl;

	delete[] powLvl;
	delete[] result;

	return 0;
}