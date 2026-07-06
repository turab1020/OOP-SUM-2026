#include <iostream>
using namespace std;

char** createChest(char** chest, int itemCount) {
    cin.ignore();

    for (int i = 0; i < itemCount; i++) {
        char temp[100];

        cout << "Enter name of item " << (i + 1) << ": ";
        cin.getline(temp, 100);

        int len = 0;

        while (temp[len] != '\0') {
            len++;
        }

        chest[i] = new char[len + 1];

        for (int j = 0; j <= len; j++) {
            chest[i][j] = temp[j];
        }
    }
}


void displayChest(char** chest, int numItems) {
    cout << "\nMario's Item Chest:\n";

    for (int i = 0; i < numItems; i++) {
        cout << (i + 1) << ". " << chest[i] << "\n";
    }
}

void freeChest(char** chest, int numItems) {

    for (int i = 0; i < numItems; i++) {
        delete[] chest[i];
    }

    delete[] chest;
}

int main() {
    int itemCount;

    cout << "How many items do you want to store: ";
    cin >> itemCount;

    char** chest = new char* [itemCount];

    createChest(chest,itemCount);

    cout << "\nNumber of items recorded: " << itemCount << "\n";

    displayChest(chest, itemCount);

    freeChest(chest, itemCount);
}