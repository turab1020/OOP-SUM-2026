// Name: Turab Haider
// Roll No: 23L-0995
// Task 2: 2D Dynamic Arrays (Matrix Operations)

#include <iostream>
using namespace std;

void createMatrix(int*** matrix, int rows, int cols) {
	*matrix = new int*[rows];
	
	for (int i = 0; i < rows; i++) {
		(*matrix)[i] = new int[cols];
	}
}

void inputMatrix(int** matrix, int rows, int cols) {
	cout << "Enter matrix elements (" << rows << "x" << cols << "):" << endl;
	
	for (int i = 0; i < rows; i++) {
		cout << "Row " << i + 1 << ": ";
		
		for (int j = 0; j < cols; j++) {
			cin >> matrix[i][j];
			
			// Input validation
			if (cin.fail()) {
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Invalid input. Enter integer: ";
				j--;
			}
		}
	}
}

void displayMatrix(int** matrix, int rows, int cols) {
	cout << "\nMatrix:" << endl;
	
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << matrix[i][j] << " ";
		}
		
		cout << endl;
	}
}

void calculateRowSum(int** matrix, int rows, int cols) {
	cout << "\nRow Sums:" << endl;
	
	for (int i = 0; i < rows; i++) {
		int sum = 0;
		
		for (int j = 0; j < cols; j++) {
			sum += matrix[i][j];
		}
		
		cout << "Row " << i + 1 << " Sum = " << sum << endl;
	}
}

void calculateColumnSum(int** matrix, int rows, int cols) {
	cout << "\nColumn Sums:" << endl;
	
	for (int j = 0; j < cols; j++) {
		int sum = 0;
		
		for (int i = 0; i < rows; i++) {
			sum += matrix[i][j];
		}
		
		cout << "Column " << j + 1 << " Sum = " << sum << endl;
	}
}

void destroyMatrix(int*** matrix, int rows) {
	for (int i = 0; i < rows; i++) {
		delete[] (*matrix)[i];
	}
	
	delete[] *matrix;
	*matrix = nullptr;
}

int main() {
	int rows, cols;
	int** matrix = nullptr;
	
	cout << "Enter number of rows: ";
	cin >> rows;
	
	cout << "Enter number of columns: ";
	cin >> cols;
	
	// Input validation
	if (cin.fail() || rows <= 0 || cols <= 0) {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Invalid dimensions. Exiting." << endl;
		return 1;
	}
	
	createMatrix(&matrix, rows, cols);
	inputMatrix(matrix, rows, cols);
	displayMatrix(matrix, rows, cols);
	calculateRowSum(matrix, rows, cols);
	calculateColumnSum(matrix, rows, cols);
	
	destroyMatrix(&matrix, rows);
	
	return 0;
}
