#include <iostream>
using namespace std;

void addItem(int* inventory, int& count, int capacity) {
    if (count < capacity) {
        int code;

        cout << "1. Mshrooms\n";
        cout << "2. Freballs\n";
        cout << "3. Stars\n";

        cout << "\nEnter Item code to add: ";
        cin >> code;

        while (code <= 0 || code > 3) {
            cout << "Invalid Itm Code!..." << endl;
            cout << "\nEnter Item code to add: ";
            cin >> code;
        }

        inventory[count] = code;
        count++;

        cout << "(" << count << "/" << capacity << ") " << "Item Added Successfully!\n";
        cout << "---------------------------\n";
    }

    else {
        cout << "(" << count << "/" << capacity << ") " << "Inventory Full, Regrow first to add items!...\n";
        cout << "---------------------------\n";
    }
}

void removeItem(int& count) {
    if (count > 0) {
        count--;

        cout << "Last item removed.\n";
        cout << "---------------------------\n";
    }

    else {
        cout << "Inventory is empty.\n";
        cout << "---------------------------\n";
    }
}

void displayInventory(int* inventory, int count, int capacity) {

    cout << "Inventory (" << count << "/" << capacity << "): ";

    if (count == 0) {
        cout << "<empty>";
        cout << "\n---------------------------\n";
    }

    else {
        for (int i = 0; i < count; i++) {
            cout << inventory[i] << " ";
        }
        cout << "\n---------------------------\n";
    }
    cout << "\n";
}

int* shrinkInventory(int* inventory, int& capacity, int& count, int newCap) {
    if (newCap >= capacity) {
        cout << "New capacity must be smaller than current.\n";
        cout << "---------------------------\n";

        return inventory;
    }

    else if (newCap < 0) {
        cout << "New Capacity cannot be less than zero.\n";
        cout << "---------------------------\n";

        return inventory;
    }

    if (newCap < count) {
        cout << "Shrinking will discard " << (count - newCap) << " item(s).\n";
        count = newCap;
    }

    int* temp = new int[newCap];

    for (int i = 0; i < newCap; i++) {
        temp[i] = inventory[i];
    }

    delete[] inventory;
    capacity = newCap;

    cout << "Inventory Size Shrunk to " << capacity << endl;
    cout << "---------------------------\n";


    return temp;
}

int* regrowInventory(int* inventory, int& capacity, int newCap) {
    if (newCap <= capacity) {
        cout << "New capacity must be greater than current.\n";
        cout << "---------------------------\n";

        return inventory;
    }

    else if (newCap < 0) {
        cout << "New Capacity cannot be less than zero.\n";
        cout << "---------------------------\n";

        return inventory;
    }

    int* temp = new int[newCap];

    for (int i = 0; i < newCap; i++) {
        temp[i] = inventory[i];
    }

    delete[] inventory;
    capacity = newCap;

    cout << "Inventory Size Grew to " << capacity << endl;
    cout << "---------------------------\n";

    return temp;
}

int main() {
	int capacity;

	cout << "Enter initial Inventory size: ";
	cin >> capacity;

	while (capacity <= 0) {
		cout << "Invalide Size!..." << endl;
		cout << "\nEnter initial Inventory size: ";
		cin >> capacity;
	}

    int* inventory = new int[capacity];
    int count = 0;

    int choice;
    do {
        cout << "\n--- Mario's Inventory ---\n\n";
        cout << "1. Add item\n";
        cout << "2. Remove last item\n";
        cout << "3. Display inventory\n";
        cout << "4. Shrink inventory\n";
        cout << "5. Regrow inventory\n";
        cout << "6. Exit\n";
        cout << "\nEnter choice: ";
        cin >> choice;
        cout << "\n---------------------------\n";

        switch (choice) {

        case 1: {
            addItem(inventory, count, capacity);
            break;
        }

        case 2: {
            removeItem(count);
            break;
        }

        case 3: {
            displayInventory(inventory, count, capacity);
            break;
        }

        case 4: {
            int newCap;

            cout << "Enter new smaller capacity: ";
            cin >> newCap;
            cout << endl;

            inventory = shrinkInventory(inventory, capacity, count, newCap);

            break;
        }

        case 5: {
            int newCap;

            cout << "Enter new larger capacity: ";
            cin >> newCap;
            cout << endl;

            inventory = regrowInventory(inventory, capacity, newCap);

            break;
        }

        case 6: {
            cout << "Exiting...\n";
            break;
        }

        default:
            cout << "Invalid choice!\n";
            break;
        }
    } while (choice != 6);

    delete[] inventory;
}