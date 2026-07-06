#include <iostream>
using namespace std;

int main() {
    int* a = new int(100);
    int* b = a; // b points to the same memory as a

    delete a;   // Memory holding 100 is freed safely
    a = nullptr; // Prevent a from becoming a dangling pointer
    b = nullptr; // Prevent b from becoming a dangling pointer

    int* c = new int(200);

    delete c;   // Free the memory holding 200 before reassigning c

    c = new int(300);

    delete c;
    c = nullptr;

    return 0;
}