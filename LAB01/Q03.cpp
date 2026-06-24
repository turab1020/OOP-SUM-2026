#include <iostream>
#include <fstream>

using namespace std;

int absoluteValue(int number) {
	if (number < 0) {
		return -number;
	}

	return number;
}

int countIncreasingTriplets(int row[], int cols) {
	int count = 0;

	for (int i = 0; i < cols - 2; i++) {
		if (row[i] < row[i + 1] && row[i + 1] < row[i + 2]) {
			count++;
		}
	}

	return count;
}

int countValuesAbove80(int row[], int cols) {
	int count = 0;

	for (int i = 0; i < cols; i++) {
		if (row[i] > 80) {
			count++;
		}
	}

	return count;
}

int findAnomalousHours(int matrix[][20], int rows, int cols, int hours[]) {
	int count = 0;

	for (int i = 0; i < rows; i++) {
		int triplets = countIncreasingTriplets(matrix[i], cols);
		int above80 = countValuesAbove80(matrix[i], cols);

		if (triplets >= 3 && above80 >= 2) {
			hours[count] = i;
			count++;
		}
	}

	return count;
}

void calculateStabilityScores(int matrix[][20], int rows, int cols, int scores[]) {
	for (int col = 0; col < cols; col++) {
		int score = 0;

		for (int row = 1; row < rows; row++) {
			if (absoluteValue(matrix[row][col] - matrix[row - 1][col]) <= 2) {
				score++;
			}
		}

		scores[col] = score;
	}
}

void calculateQuadrantAverages(int matrix[][20], double averages[]) {
	double sum[4] = { 0, 0, 0, 0 };
	int count = 0;

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 10; j++) {
			sum[0] += matrix[i][j];
			count++;
		}
	}

	averages[0] = sum[0] / count;
	count = 0;

	for (int i = 0; i < 12; i++) {
		for (int j = 10; j < 20; j++) {
			sum[1] += matrix[i][j];
			count++;
		}
	}

	averages[1] = sum[1] / count;
	count = 0;

	for (int i = 12; i < 24; i++) {
		for (int j = 0; j < 10; j++) {
			sum[2] += matrix[i][j];
			count++;
		}
	}

	averages[2] = sum[2] / count;
	count = 0;

	for (int i = 12; i < 24; i++) {
		for (int j = 10; j < 20; j++) {
			sum[3] += matrix[i][j];
			count++;
		}
	}

	averages[3] = sum[3] / count;
}

int main() {
	int matrix[24][20];
	int anomalousHours[24];
	int stabilityScores[20];
	double quadrantAverages[4];

	ifstream fin("Manual/heat.txt");

	if (!fin.is_open()) {
		fin.open("heat.txt");
	}

	if (!fin.is_open()) {
		cout << "Error opening heat.txt" << endl;
		return 1;
	}

	int rows;
	int cols;

	fin >> rows >> cols;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			fin >> matrix[i][j];
		}
	}

	fin.close();

	int anomalousCount = findAnomalousHours(matrix, rows, cols, anomalousHours);
	calculateStabilityScores(matrix, rows, cols, stabilityScores);
	calculateQuadrantAverages(matrix, quadrantAverages);

	int highestScore = stabilityScores[0];

	for (int i = 1; i < cols; i++) {
		if (stabilityScores[i] > highestScore) {
			highestScore = stabilityScores[i];
		}
	}

	int highScoreCount = 0;

	for (int i = 0; i < cols; i++) {
		if (stabilityScores[i] >= 20) {
			highScoreCount++;
		}
	}

	int dominantQuadrant = 0;

	for (int i = 1; i < 4; i++) {
		if (quadrantAverages[i] > quadrantAverages[dominantQuadrant]) {
			dominantQuadrant = i;
		}
	}

	ofstream fout("analysis.txt");

	if (!fout.is_open()) {
		cout << "Error creating analysis.txt" << endl;
		return 1;
	}

	fout << "Anomalous hours count: " << anomalousCount << endl;
	fout << "Anomalous hours: ";

	for (int i = 0; i < anomalousCount; i++) {
		fout << anomalousHours[i] << " ";
	}

	fout << endl << endl;
	fout << "Highest stability sensor:" << endl;

	for (int i = 0; i < cols; i++) {
		if (stabilityScores[i] == highestScore) {
			fout << i << " with score " << highestScore << endl;
		}
	}

	fout << "Sensors with score >= 20: " << highScoreCount << endl;
	fout << "Quadrant averages:" << endl;
	fout << "Q1: " << quadrantAverages[0] << endl;
	fout << "Q2: " << quadrantAverages[1] << endl;
	fout << "Q3: " << quadrantAverages[2] << endl;
	fout << "Q4: " << quadrantAverages[3] << endl;
	fout << "Dominant quadrant: Q" << dominantQuadrant + 1 << endl;

	fout.close();

	cout << "analysis.txt generated successfully." << endl;

	return 0;
}