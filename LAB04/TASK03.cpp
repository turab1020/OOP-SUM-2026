#include <iostream>
using namespace std;
void displayIndex(int** garden, int rows, int cols) {
    cout << "Diagonal Index Order:\n";

    for (int k = 0; k < rows; k++) {
        int i = k;
        int j = 0;

        while (i >= 0 && j < cols) {
            cout << "(" << i << ", " << j << ") ";
            i--;
            j++;
        }

        cout << endl;
    }

    for (int k = 1; k < cols; k++) {
        int i = rows - 1;
        int j = k;

        while (i >= 0 && j < cols) {
            cout << "(" << i << ", " << j << ") ";
            i--;
            j++;
        }

        cout << endl;
    }

    cout << "\n---------------------------\n";
}

void displayDiagonalOrder(int** garden, int rows, int cols) {
    cout << "Output:\n";

    for (int k = 0; k < rows; k++) {
        int i = k;
        int j = 0;

        while (i >= 0 && j < cols) {
            cout << garden[i][j] << " ";
            i--;
            j++;
        }

        cout << endl;
    }

    for (int k = 1; k < cols; k++) {
        int i = rows - 1;
        int j = k;

        while (i >= 0 && j < cols) {
            cout << garden[i][j] << " ";
            i--;
            j++;
        }

        cout << endl;
    }

    cout << "\n---------------------------\n";
}

int main() {
    int rows, cols;

    cout << "Enter the size (number of rows and columns): ";
    cin >> rows >> cols;

    int** garden = new int* [rows];

    for (int i = 0; i < rows; i++) {
        garden[i] = new int[cols];
    }

    cout << "\nEnter input for each tile:\n";

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter value for tile (" << i << "," << j << "): ";
            cin >> garden[i][j];
        }
    }
    cout << "\n---------------------------\n";

    displayIndex(garden, rows, cols);

    displayDiagonalOrder(garden, rows, cols);

    for (int i = 0; i < rows; i++) {
        delete[] garden[i];
    }

    delete[] garden;
}