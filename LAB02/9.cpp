#include <iostream>
using namespace std;

float average(const float* arr, int size) {
	float avg = 0;

	for (int i = 0; i < size; i++) {
		avg = avg + *(arr + i);
	}

	return avg / size;
}

int main() {
	int size;
	float* arr;

	cout << "No. of Readings: ";
	cin >> size;

	arr = new float[size];

	cout << "Enter " << size << " Readings: ";

	for (int i = 0; i < size; i++) {
		cin >> *(arr + i);
	}

	cout << "\nAverage: " << average(arr, size) << endl;

	delete[] arr;
	arr = nullptr;
}