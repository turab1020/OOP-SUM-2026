// Name: Turab Haider
// Roll No: 23L-0995
// Task 4: Jagged Arrays (Monthly Sales Data)

#include <iostream>
using namespace std;

void createJaggedArray(double*** jagged, int* sizes, int months) {
	*jagged = new double*[months];
	
	for (int i = 0; i < months; i++) {
		(*jagged)[i] = new double[sizes[i]];
	}
}

void inputMonthlySales(double** jagged, int* sizes, int months) {
	for (int i = 0; i < months; i++) {
		cout << "\nEnter sales for Month " << i + 1 << " (" << sizes[i] << " days): ";
		
		for (int j = 0; j < sizes[i]; j++) {
			cin >> jagged[i][j];
			
			// Input validation
			if (cin.fail() || jagged[i][j] < 0) {
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Invalid input. Enter positive sales value: ";
				j--;
			}
		}
	}
}

void displayMonthlySales(double** jagged, int* sizes, int months) {
	cout << "\n--- Monthly Sales Data ---" << endl;
	
	for (int i = 0; i < months; i++) {
		cout << "Month " << i + 1 << " Sales: ";
		
		for (int j = 0; j < sizes[i]; j++) {
			cout << jagged[i][j] << " ";
		}
		
		cout << endl;
	}
}

double calculateMonthlyTotal(double* monthlySales, int size) {
	double sum = 0;
	
	for (int i = 0; i < size; i++) {
		sum += monthlySales[i];
	}
	
	return sum;
}

double calculateMonthlyAverage(double* monthlySales, int size) {
	double sum = calculateMonthlyTotal(monthlySales, size);
	return sum / size;
}

double findBestSalesDay(double* monthlySales, int size) {
	double highest = monthlySales[0];
	
	for (int i = 1; i < size; i++) {
		if (monthlySales[i] > highest) {
			highest = monthlySales[i];
		}
	}
	
	return highest;
}

void displaySalesStatistics(double** jagged, int* sizes, int months) {
	cout << "\n--- Monthly Statistics ---" << endl;
	
	double overallTotal = 0;
	
	for (int i = 0; i < months; i++) {
		double total = calculateMonthlyTotal(jagged[i], sizes[i]);
		double avg = calculateMonthlyAverage(jagged[i], sizes[i]);
		
		cout << "\nMonth " << i + 1 << " Total Sales = " << total << endl;
		cout << "Month " << i + 1 << " Average = " << avg << endl;
		
		overallTotal += total;
	}
	
	cout << "\nOverall Company Sales = " << overallTotal << endl;
	
	cout << "\n--- Best Sales Day ---" << endl;
	
	for (int i = 0; i < months; i++) {
		double bestDay = findBestSalesDay(jagged[i], sizes[i]);
		cout << "Month " << i + 1 << " = " << bestDay << endl;
	}
}

void destroyJaggedArray(double*** jagged, int months) {
	for (int i = 0; i < months; i++) {
		delete[] (*jagged)[i];
	}
	
	delete[] *jagged;
	*jagged = nullptr;
}

int main() {
	int months;
	
	cout << "Enter number of months: ";
	cin >> months;
	
	// Input validation
	if (cin.fail() || months <= 0) {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Invalid number of months. Exiting." << endl;
		return 1;
	}
	
	int* sizes = new int[months];
	
	// Input number of days for each month
	for (int i = 0; i < months; i++) {
		cout << "Days in Month " << i + 1 << ": ";
		cin >> sizes[i];
		
		// Input validation
		if (cin.fail() || sizes[i] <= 0) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Invalid number of days. Exiting." << endl;
			delete[] sizes;
			return 1;
		}
	}
	
	double** jagged = nullptr;
	createJaggedArray(&jagged, sizes, months);
	inputMonthlySales(jagged, sizes, months);
	displayMonthlySales(jagged, sizes, months);
	displaySalesStatistics(jagged, sizes, months);
	
	destroyJaggedArray(&jagged, months);
	delete[] sizes;
	
	return 0;
}
