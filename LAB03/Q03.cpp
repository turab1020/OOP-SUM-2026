// Name: Turab Haider
// Roll No: 23L-0995
// Task 3: Jagged Arrays (Course Student Marks)

#include <iostream>
using namespace std;

void createJaggedArray(int*** jagged, int* sizes, int courses) {
	*jagged = new int*[courses];
	
	for (int i = 0; i < courses; i++) {
		(*jagged)[i] = new int[sizes[i]];
	}
}

void inputCourseMarks(int** jagged, int* sizes, int courses) {
	for (int i = 0; i < courses; i++) {
		cout << "\nEnter marks for Course " << i + 1 << " (" << sizes[i] << " students): ";
		
		for (int j = 0; j < sizes[i]; j++) {
			cin >> jagged[i][j];
			
			// Input validation
			if (cin.fail()) {
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Invalid input. Enter integer marks: ";
				j--;
			}
		}
	}
}

void displayCourseMarks(int** jagged, int* sizes, int courses) {
	cout << "\n--- Course Marks ---" << endl;
	
	for (int i = 0; i < courses; i++) {
		cout << "Course " << i + 1 << " Marks: ";
		
		for (int j = 0; j < sizes[i]; j++) {
			cout << jagged[i][j] << " ";
		}
		
		cout << endl;
	}
}

double calculateCourseAverage(int* courseMarks, int size) {
	int sum = 0;
	
	for (int i = 0; i < size; i++) {
		sum += courseMarks[i];
	}
	
	return (double)sum / size;
}

int findHighestMark(int* courseMarks, int size) {
	int highest = courseMarks[0];
	
	for (int i = 1; i < size; i++) {
		if (courseMarks[i] > highest) {
			highest = courseMarks[i];
		}
	}
	
	return highest;
}

void displayStatistics(int** jagged, int* sizes, int courses) {
	cout << "\n--- Course Averages ---" << endl;
	
	int overallHighest = 0;
	
	for (int i = 0; i < courses; i++) {
		double avg = calculateCourseAverage(jagged[i], sizes[i]);
		cout << "Course " << i + 1 << " Average = " << avg << endl;
	}
	
	cout << "\n--- Highest Mark in Each Course ---" << endl;
	
	for (int i = 0; i < courses; i++) {
		int highest = findHighestMark(jagged[i], sizes[i]);
		
		cout << "Highest mark in Course " << i + 1 << " = " << highest << endl;
		
		if (highest > overallHighest) {
			overallHighest = highest;
		}
	}
	
	cout << "\nOverall Highest Mark = " << overallHighest << endl;
}

void destroyJaggedArray(int*** jagged, int courses) {
	for (int i = 0; i < courses; i++) {
		delete[] (*jagged)[i];
	}
	
	delete[] *jagged;
	*jagged = nullptr;
}

int main() {
	int courses;
	
	cout << "Enter number of courses: ";
	cin >> courses;
	
	// Input validation
	if (cin.fail() || courses <= 0) {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Invalid number of courses. Exiting." << endl;
		return 1;
	}
	
	int* sizes = new int[courses];
	
	// Input number of students for each course
	for (int i = 0; i < courses; i++) {
		cout << "Students in Course " << i + 1 << ": ";
		cin >> sizes[i];
		
		// Input validation
		if (cin.fail() || sizes[i] <= 0) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Invalid number of students. Exiting." << endl;
			delete[] sizes;
			return 1;
		}
	}
	
	int** jagged = nullptr;
	createJaggedArray(&jagged, sizes, courses);
	inputCourseMarks(jagged, sizes, courses);
	displayCourseMarks(jagged, sizes, courses);
	displayStatistics(jagged, sizes, courses);
	
	destroyJaggedArray(&jagged, courses);
	delete[] sizes;
	
	return 0;
}
