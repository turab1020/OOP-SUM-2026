#include <iostream>
using namespace std;

class Matrix {
private:
    int rows;
    int cols;
    int** data;

public:
    Matrix() {
        rows = 0;
        cols = 0;
        data = nullptr;
    }

    Matrix(int rows, int cols) {
        if (rows <= 0 || cols <= 0) {
            this->rows = 0;
            this->cols = 0;
            data = nullptr;
            return;
        }

        this->rows = rows;
        this->cols = cols;
        data = new int* [this->rows];

        for (int i = 0; i < this->rows; i++) {
            *(data + i) = new int[this->cols];

            for (int j = 0; j < this->cols; j++) {
                *(*(data + i) + j) = 0;
            }
        }
    }

    Matrix(const Matrix& other) {
        rows = other.rows;
        cols = other.cols;

        if (rows > 0 && cols > 0 && other.data != nullptr) {
            data = new int* [rows];

            for (int i = 0; i < rows; i++) {
                *(data + i) = new int[cols];

                for (int j = 0; j < cols; j++) {
                    *(*(data + i) + j) = *(*(other.data + i) + j);
                }
            }
        }

        else {
            data = nullptr;
        }
    }

    void setValue(int r, int c, int val) {
        if (data == nullptr || r < 0 || c < 0 || r >= rows || c >= cols) {
            return;
        }

        *(*(data + r) + c) = val;
    }

    int getValue(int r, int c) {
        if (data == nullptr || r < 0 || c < 0 || r >= rows || c >= cols) {
            return 0;
        }

        return *(*(data + r) + c);
    }

    Matrix operator+(const Matrix& other) {
        if (rows != other.rows || cols != other.cols) {
            cout << "\nError: Matrix dimensions do not match for addition!\n";
            return Matrix();
        }

        Matrix result(rows, cols);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.setValue(i, j, *(*(data + i) + j) + *(*(other.data + i) + j));
            }
        }

        return result;
    }

    Matrix operator*(const Matrix& other) {
        if (cols != other.rows) {
            cout << "\nError: Matrix dimensions do not match for multiplication!\n";
            return Matrix();
        }

        Matrix result(rows, other.cols);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                int sum = 0;

                for (int k = 0; k < cols; k++) {
                    sum += *(*(data + i) + k) * *(*(other.data + k) + j);
                }

                result.setValue(i, j, sum);
            }
        }

        return result;
    }

    bool operator==(const Matrix& other) {
        if (rows != other.rows || cols != other.cols) {
            return false;
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (*(*(data + i) + j) != *(*(other.data + i) + j)) {
                    return false;
                }
            }
        }

        return true;
    }

    friend ostream& operator<<(ostream& out, const Matrix& matrix) {
        for (int i = 0; i < matrix.rows; i++) {
            for (int j = 0; j < matrix.cols; j++) {
                out << *(*(matrix.data + i) + j) << " ";
            }

            out << "\n";
        }

        return out;
    }

    ~Matrix() {
        if (data != nullptr) {
            for (int i = 0; i < rows; i++) {
                delete[] *(data + i);
            }

            delete[] data;
        }
    }
};

int main() {
    Matrix first(2, 2);
    Matrix second(2, 2);

    first.setValue(0, 0, 1);
    first.setValue(0, 1, 2);
    first.setValue(1, 0, 3);
    first.setValue(1, 1, 4);

    second.setValue(0, 0, 5);
    second.setValue(0, 1, 6);
    second.setValue(1, 0, 7);
    second.setValue(1, 1, 8);

    Matrix sum = first + second;
    Matrix product = first * second;

    cout << "Matrix 1:\n" << first;
    cout << "Matrix 2:\n" << second;
    cout << "Sum:\n" << sum;
    cout << "Product:\n" << product;
    cout << "Equality Check Between Matrix 1 and Matrix 2: " << (first == second ? "Yes" : "No") << "\n";

    return 0;
}