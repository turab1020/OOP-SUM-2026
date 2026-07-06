#include <iostream>
using namespace std;

void bubbleSort(int* arr, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int capacity;
    cout << "Enter Size: ";
    cin >> capacity;

    if (capacity <= 0) {
        capacity = 2;
    }

    int* cloneDB = new int[capacity];
    int count = 0;

    cout << "Initial IDs (Enter -1 to stop):\n";
    while (true) {
        int id;
        cin >> id;

        if (id == -1) {
            break;
        }

        if (count == capacity) {
            int oldCapacity = capacity;
            capacity *= 2;

            cout << "[Resizing] Array full. Expanding capacity from " << oldCapacity << " to " << capacity << ".\n";

            int* newDB = new int[capacity];
            
            for (int i = 0; i < count; i++) {
                newDB[i] = cloneDB[i];
            }

            delete[] cloneDB;
            cloneDB = newDB;
        }

        cloneDB[count] = id;
        count++;
    }

    if (count == 0) {
        cout << "\nDatabase is empty." << endl;

        delete[] cloneDB;

        return 0;
    }

    bubbleSort(cloneDB, count);

    cout << "\nAfter sorting:\n";

    for (int i = 0; i < count; i++) {
        cout << cloneDB[i] << " ";
    }
    cout << "\n";

    int uniqueCount = 0;

    if (count > 0) {
        uniqueCount = 1;

        for (int i = 1; i < count; i++) {
            if (cloneDB[i] != cloneDB[i - 1]) {
                cloneDB[uniqueCount] = cloneDB[i];
                uniqueCount++;
            }
        }
    }

    cout << "[Resizing] Shrinking array to match unique IDs exactly. Capacity set to: " << uniqueCount << ".\n";
    int* uniqueDB = new int[uniqueCount];

    for (int i = 0; i < uniqueCount; i++) {
        uniqueDB[i] = cloneDB[i];
    }

    delete[] cloneDB;

    cloneDB = uniqueDB;
    capacity = uniqueCount;

    cout << "\n--- Final Clone Database Status ---\n";
    cout << "Unique clone IDs: ";

    for (int i = 0; i < uniqueCount; i++) {
        cout << cloneDB[i] << " ";
    }

    cout << "\n";

    cout << "Size after duplicate removal: " << uniqueCount << "\n";
    cout << "Final array capacity: " << capacity << "\n";

    delete[] cloneDB;
    cloneDB = nullptr;

    return 0;
}