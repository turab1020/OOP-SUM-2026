#include <iostream>
using namespace std;

char** filterByTag(char arr[][20], int n, int& rows, char tag)
{
    rows = 0;
    for (int i = 0; i < n; i++)
        if (arr[i][0] == tag)
            rows++;

    char** jag = new char*[rows];
    int out = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i][0] != tag)
            continue;

        int len = 0;
        for (int j = 1; arr[i][j] != '\0'; j++)
            if (arr[i][j] != ' ')
                len++;

        jag[out] = new char[len + 1];
        int k = 0;
        for (int j = 1; arr[i][j] != '\0'; j++)
            if (arr[i][j] != ' ')
                jag[out][k++] = arr[i][j];
        jag[out][len] = '\0';
        out++;
    }

    return jag;
}

char** splitByHash(char text[], int& rows)
{
    rows = 0;
    for (int i = 0; text[i] != '\0'; i++)
        if (text[i] == '#')
            rows++;

    char** jag = new char*[rows];
    int start = 0;
    int out = 0;

    for (int i = 0; ; i++)
    {
        if (text[i] != '#' && text[i] != '\0')
            continue;

        int len = i - start;
        jag[out] = new char[len + 1];
        for (int j = 0; j < len; j++)
            jag[out][j] = text[start + j];
        jag[out][len] = '\0';
        out++;

        if (text[i] == '\0')
            break;
        start = i + 1;
    }

    return jag;
}

void printJagged(char** jag, int rows)
{
    for (int i = 0; i < rows; i++)
        cout << jag[i] << endl;
}

int main()
{
    char arr[6][20] = { "Ahello how are you?", "BI am fine", "Awhats up", "A??", "BNothing", "AFine Thanks" };
    int rows = 0;
    char** filtered = filterByTag(arr, 6, rows, 'A');
    cout << "Filtered rows:" << endl;
    printJagged(filtered, rows);

    char text[] = "Ahmad Ali,A,23#Fahad Khan,B,344#Faran,B,67#Adnan Shahid,A,67#";
    int parts = 0;
    char** records = splitByHash(text, parts);
    cout << "Records:" << endl;
    printJagged(records, parts);

    return 0;
}

/*
Dry run summary:
- filterByTag keeps only rows starting with A and removes spaces.
- splitByHash breaks one flat string into separate rows at each '#'.
*/
