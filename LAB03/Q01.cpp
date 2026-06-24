// Name: Turab Haider
// Roll No: 23L-0995
// Task 1: Double Pointers and 1D Dynamic Array

#include <iostream>
using namespace std;

void createArray(int** arr, int size) {
	*arr = new int[size];
}

void inputMarks(int* arr, int size) {
	cout << "Enter " << size << " student marks: ";
	
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
		
		// Input validation
		if (cin.fail()) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Invalid input. Enter integer marks: ";
			i--;
		}
	}
}

void displayMarks(int* arr, int size) {
	cout << "\nStudent Marks: ";
	
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	
	cout << endl;
}

double calculateAverage(int* arr, int size) {
	int sum = 0;
	
	for (int i = 0; i < size; i++) {
		sum += arr[i];
	}
	
	return (double)sum / size;
}

void deleteArray(int** arr) {
	delete[] *arr;
	*arr = nullptr;
}

int main() {
	int n;
	int* marks = nullptr;
	
	cout << "Enter number of students: ";
	cin >> n;
	
	// Input validation
	if (cin.fail() || n <= 0) {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Invalid number of students. Exiting." << endl;
		return 1;
	}
	
	createArray(&marks, n);
	inputMarks(marks, n);
	displayMarks(marks, n);
	
	double avg = calculateAverage(marks, n);
	cout << "Average Marks: " << avg << endl;
	
	deleteArray(&marks);
	
	return 0;
}
