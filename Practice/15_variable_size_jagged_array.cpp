#include <iostream>
using namespace std;

int* makeRow(int length, int startValue)
{
    int* row = new int[length];
    for (int index = 0; index < length; index++)
        row[index] = startValue + index;
    return row;
}

int main()
{
    int rowLengths[4] = {2, 5, 3, 6};
    int* table[4];

    for (int row = 0; row < 4; row++)
        table[row] = makeRow(rowLengths[row], (row + 1) * 10);

    for (int row = 0; row < 4; row++)
    {
        for (int col = 0; col < rowLengths[row]; col++)
            cout << table[row][col] << ' ';
        cout << endl;
    }

    for (int row = 0; row < 4; row++)
        delete[] table[row];

    return 0;
}

/*
Dry run summary:
- Every row length comes from rowLengths, so the jagged array can change shape per row.
- This is the variable-size version of a jagged array.
*/
