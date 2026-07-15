#include <iostream>
using namespace std;

void print2D(int arr[][3], int rows)
{
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < 3; col++)
            cout << arr[row][col] << ' ';
        cout << endl;
    }
}

void multiply2D(int arr[][3], int rows, int factor)
{
    for (int row = 0; row < rows; row++)
        for (int col = 0; col < 3; col++)
            arr[row][col] *= factor;
}

int main()
{
    int matrix[2][3] = { {1, 2, 3}, {4, 5, 6} };

    print2D(matrix, 2);
    multiply2D(matrix, 2, 10);
    cout << endl;
    print2D(matrix, 2);

    return 0;
}

/*
Dry run summary:
- The column count is fixed at 3 in the function signature.
- matrix elements are changed in place because the array decays to a pointer to rows.
*/
