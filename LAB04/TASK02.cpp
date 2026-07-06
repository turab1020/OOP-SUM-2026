#include <iostream>
using namespace std;

int** createMatrix(int** matrix, int N) {

    for (int i = 0; i < N; i++) {
        matrix[i] = new int[N];
    }

    return matrix;
}

void fillMatrix(int** matrix, int N) {

    cout << "Enter " << N * N << " integers to fill the matrix:\n";

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }
}


void displayMatrix(int** matrix, int N) {

    cout << "Matrix (" << N << "x" << N << "):\n";

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << " ";
        }

        cout << "\n";
    }
}

void displayTranspose(int** matrix, int N) {

    cout << "Transpose (" << N << "x" << N << "):\n";

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[j][i] << " ";
        }

        cout << "\n";
    }
}

void freeMatrix(int** matrix, int N) {

    for (int i = 0; i < N; i++) {
        delete[] matrix[i];
    }

    delete[] matrix;
}

int main() {
    int N;

    cout << "Enter size N for NxN matrix: ";
    cin >> N;

    int** matrix = new int* [N];

    createMatrix(matrix, N);

    fillMatrix(matrix, N);

    cout << "\nOriginal Matrix:\n";
    displayMatrix(matrix, N);

    cout << "\nTranspose Matrix:\n";
    displayTranspose(matrix, N);

    freeMatrix(matrix, N);
}
