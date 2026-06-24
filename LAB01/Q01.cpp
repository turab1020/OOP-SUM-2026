#include <iostream>
using namespace std;

int cleanData(int arr[], int n) {
	int new_n = 0;

	for (int i = 0; i < n; i++) {
		if (arr[i] != -999) {
			arr[new_n] = arr[i];
			new_n++;
		}
	}

	return new_n;
}

int longestDecreasingSeq(int arr[], int n) {
	if (n <= 0) {
		return 0;
	}

	int max = 1;
	int count = 1;

	for (int i = 1; i < n; i++) {
		if (arr[i] < arr[i - 1]) {
			count++;

			if (count > max) {
				max = count;
			}
		}

		else{
			count = 1;
		}
	}

	return max;
}

int main() {
	int n;

	cout << "Enter total number of days (N): ";
	cin >> n;

	int temp[100];

	cout << "Enter " << n << " temperature values: ";

	for (int i = 0; i < n; i++) {
		cin >> temp[i];
	}

	int logical_size = cleanData(temp, n);

	int longest_seq = longestDecreasingSeq(temp, logical_size);

	cout << "\nCleaned Temperatures: ";

	for (int i = 0; i < logical_size; i++) {
		cout << temp[i] << " ";
	}

	cout << "\nLongest Decreasing Sequence Length: " << longest_seq << endl;
}