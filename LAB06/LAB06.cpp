#include <iostream>
using namespace std;

class Minion {
private:
    char* name;
    int bananaPower;
    static int totalMinions;

    int getStringLength(const char* str) const {
        if (!str) {
			return 0;
		}

        int len = 0;

        while (str[len] != '\0') {
            len++;
        }

        return len;
    }

    void copyString(char* dest, const char* src) {
        if (!dest || !src) {
			return;
		}

        int i = 0;

        while (src[i] != '\0') {
            dest[i] = src[i];
            i++;
        }

        dest[i] = '\0';
    }

    int validatePower(int power) const {
        if (power < 0) {
			return 0;
		
		}

        if (power > 1000) {
			return 1000;
		}

        return power;
    }

public:
    static void showTotalMinions() {
        cout << "Total Minions Created: " << totalMinions << endl;
    }

    Minion() {
        const char* defaultName = "N/A";
        int len = getStringLength(defaultName);
        name = new char[len + 1];
        copyString(name, defaultName);
        
        bananaPower = 0;
        totalMinions++;
    }

    Minion(const char* providedName, int power) {
        if (!providedName || providedName[0] == '\0') {
            providedName = "N/A";
        }

        int len = getStringLength(providedName);
        name = new char[len + 1];
        copyString(name, providedName);

        bananaPower = validatePower(power);
        totalMinions++;
    }

    Minion(const Minion& other) {
        int len = getStringLength(other.name);
        name = new char[len + 1];
        copyString(name, other.name);

        bananaPower = other.bananaPower;
        totalMinions++;
    }

    ~Minion() {
        cout << "Destructor Called" << endl;
        delete[] name;
    }

    const char* getName() const {
        return name;
    }

    int getBananaPower() const {
        return bananaPower;
    }

    Minion* setName(const char* newName) {
        if (!newName || newName[0] == '\0') {
            return this; 
        }
        
        delete[] name;

        int len = getStringLength(newName);
        name = new char[len + 1];
        copyString(name, newName);
        
        return this;
    }

    Minion& setBananaPower(int power) {
        bananaPower = validatePower(power);

        return *this;
    }

    void operator-() {
        bananaPower = 0;
    }

    Minion& operator++() {
        bananaPower = validatePower(bananaPower + 50);

        return *this;
    }

    Minion operator++(int) {
        Minion temp(*this);
        bananaPower = validatePower(bananaPower + 20);
        return temp;
    }

    Minion& operator--() {
        bananaPower = validatePower(bananaPower - 50);
        return *this;
    }

    Minion operator--(int) {
        Minion temp(*this);
        bananaPower = validatePower(bananaPower - 20);
        return temp;
    }

    void display() const {
        cout << "Minion Name : " << name << endl;
        cout << "Banana Power : " << bananaPower << " [";
        
        if (bananaPower <= 100) cout << "Sleepy Minion";
        else if (bananaPower <= 400) cout << "Worker Minion";
        else if (bananaPower <= 800) cout << "Super Minion";
        else cout << "Mega Minion";
        
        cout << "]" << endl << "------------------------" << endl;
    }
};

int Minion::totalMinions = 0;

int main() {
    cout << "=== 1. Dynamic Object Creation ===" << endl;

    Minion* m = new Minion("Kevin", 450);
    m->display();

    delete m;

    cout << "\n=== 2. Array of Objects (Size 5) ===" << endl;
    Minion team[5];

    team[0].setName("Stuart")->setBananaPower(150);
    team[1].setName("Bob")->setBananaPower(850);

    for (int i = 0; i < 2; i++) {
        team[i].display();
    }

    cout << "\n=== 3. Dynamic Array of Objects ===" << endl;
    int size = 0;

    while (size <= 0) {
        cout << "Enter Number of Minions: ";
        cin >> size;

        if (size <= 0) {
            cout << "Validation Error: Number must be greater than zero." << endl;
        }
    }

    cin.ignore();

    Minion* army = new Minion[size];
    
    for (int i = 0; i < size; i++) {
        char tempName[100];
        int power = 0;

        cout << "Enter Minion Name [" << i + 1 << "]: ";
        cin.getline(tempName, 100);
        
        cout << "Enter Banana Power [" << i + 1 << "]: ";
        cin >> power;

        cin.ignore();

        army[i].setName(tempName)->setBananaPower(power);
    }

    cout << "\nDisplaying Dynamic Army:" << endl;

    for (int i = 0; i < size; i++) {
        army[i].display();
    }

    cout << "\n=== 4. Demonstrate Cascaded Function Calls ===" << endl;

    if (size >= 2) {
        cout << "Testing Mixed Complex Chaining Syntax..." << endl;

        army[0].setName("Kevin")->setBananaPower(300).setBananaPower(600);
        
        (*army[1].setName("Bob")).setBananaPower(250).setBananaPower(700);
        
        army[0].display();
        army[1].display();
    } 
    
    else {
        cout << "Skipped: Provide at least 2 minions in the dynamic array to see this demo." << endl;
    }

    cout << "\n=== 5. Demonstrate Unary Operator Overloading ===" << endl;
    if (size >= 3) {
        cout << "Original state of army[0], army[1], army[2]:" << endl;
        army[0].display();
        army[1].display();
        army[2].display();

        cout << "Applying operations: ++army[0], army[0]++, --army[1], army[1]--, -army[2]..." << endl;
        ++army[0];
        army[0]++;
        --army[1];
        army[1]--;
        -army[2];

        cout << "\nState after Unary modification:" << endl;
        army[0].display();
        army[1].display();
        army[2].display();
    } 
    
    else {
        cout << "Skipped: Provide at least 3 minions in the dynamic array to see this demo." << endl;
    }

    cout << "\n=== 6. Demonstrate Copy Constructor ===" << endl;
    Minion original("Dave", 520);
    Minion copied(original);
    cout << "Original:" << endl;
    original.display();
    cout << "Copied Copy:" << endl;
    copied.display();

    cout << "\n=== 7. Demonstrate Static Members ===" << endl;
    Minion::showTotalMinions();

    cout << "\n=== 8. Cleaning Dynamic Arrays (Destructors) ===" << endl;
    delete[] army; 

    return 0;
}