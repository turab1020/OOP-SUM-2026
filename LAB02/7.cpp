#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cout << "Enter values for a, b, c: ";
    cin >> a >> b >> c;

    const int* ptr1 = &a;
    int* const ptr2 = &b;
    const int* const ptr3 = &c;

    cout << "ptr1 points to a = " << *ptr1 << endl;
    cout << "ptr2 points to b = " << *ptr2 << endl;
    cout << "ptr3 points to c = " << *ptr3 << endl;

    // Invalid operations:

    // *ptr1 = 50;   // we can modify the address in point but cannot modify value through ptr1
    // ptr2 = &a;    // we can modify the value at that address but cannot change address of const pointer
    // *ptr3 = 100;  // we cannot modify niether the value nor the address
}