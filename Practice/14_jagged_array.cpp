#include <iostream>
using namespace std;

int main()
{
    int* rows[3];

    rows[0] = new int[2]{1, 2};
    rows[1] = new int[3]{3, 4, 5};
    rows[2] = new int[4]{6, 7, 8, 9};

    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < row + 2; col++)
            cout << rows[row][col] << ' ';
        cout << endl;
    }

    for (int row = 0; row < 3; row++)
        delete[] rows[row];

    return 0;
}

/*
Dry run summary:
- Each row has a different number of columns.
- rows is an array of pointers, and each pointer targets a separate dynamic 1D array.
*/
