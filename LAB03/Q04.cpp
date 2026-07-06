// Name: Turab Haider
// Roll No: 23L-0995
// Task 4: Jagged Arrays (Monthly Sales Data)

#include <iostream>
using namespace std;

int main() {
	int months;
	
	cout << "Enter number of months: ";
	cin >> months;
	
	// Input validation for months
	if (cin.fail() || months <= 0) {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Invalid number of months. Exiting." << endl;
		return 1;
	}
	
	// Allocate sizes array
	int* sizes = new int[months];
	
	// Input number of days for each month with validation
	for (int i = 0; i < months; i++) {
		cout << "Days in Month " << i + 1 << ": ";
		cin >> sizes[i];
		
		if (cin.fail() || sizes[i] <= 0) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Invalid number of days. Exiting." << endl;
			delete[] sizes;
			return 1;
		}
	}
	
	// Create jagged array for sales data
	double** jagged = new double*[months];
	
	for (int i = 0; i < months; i++) {
		jagged[i] = new double[sizes[i]];
	}
	
	// Input sales data for each month
	for (int i = 0; i < months; i++) {
		cout << "Enter sales for Month " << i + 1 << " (" << sizes[i] << " days): ";
		
		for (int j = 0; j < sizes[i]; j++) {
			cin >> jagged[i][j];
		}
	}
	
	// Display sales data
	cout << "\n--- Monthly Sales Data ---" << endl;
	
	for (int i = 0; i < months; i++) {
		cout << "Month " << i + 1 << " Sales: ";
		
		for (int j = 0; j < sizes[i]; j++) {
			cout << jagged[i][j] << " ";
		}
		
		cout << endl;
	}
	
	// Calculate and display statistics
	cout << "\n--- Monthly Statistics ---" << endl;
	
	double overallTotal = 0;
	
	for (int i = 0; i < months; i++) {
		double monthTotal = 0;
		
		// Calculate total for this month
		for (int j = 0; j < sizes[i]; j++) {
			monthTotal += jagged[i][j];
		}
		
		double monthAvg = monthTotal / sizes[i];
		
		cout << "\nMonth " << i + 1 << " Total Sales = " << monthTotal << endl;
		cout << "Month " << i + 1 << " Average = " << monthAvg << endl;
		
		overallTotal += monthTotal;
	}
	
	cout << "\nOverall Company Sales = " << overallTotal << endl;
	
	// Find and display best sales day for each month
	cout << "\n--- Best Sales Day ---" << endl;
	
	for (int i = 0; i < months; i++) {
		double bestDay = jagged[i][0];
		
		for (int j = 1; j < sizes[i]; j++) {
			if (jagged[i][j] > bestDay) {
				bestDay = jagged[i][j];
			}
		}
		
		cout << "Month " << i + 1 << " = " << bestDay << endl;
	}
	
	// Deallocate memory
	for (int i = 0; i < months; i++) {
		delete[] jagged[i];
	}
	
	delete[] jagged;
	delete[] sizes;
	
	return 0;
}
