#include <iostream>
using namespace std;

class ShallowBox
{
public:
    int* value;

    ShallowBox(int v = 0)
    {
        value = new int(v);
        cout << "ShallowBox ctor\n";
    }

    ShallowBox(const ShallowBox& other)
    {
        value = other.value;
        cout << "ShallowBox shallow copy ctor\n";
    }

    ShallowBox& operator=(const ShallowBox& other)
    {
        cout << "ShallowBox shallow assignment\n";
        if (this != &other)
            value = other.value;
        return *this;
    }

    void print() const
    {
        cout << *value << endl;
    }
};

int main()
{
    ShallowBox first(10);
    ShallowBox second = first;
    *second.value = 77;

    cout << "first after change through second: ";
    first.print();
    cout << "second: ";
    second.print();

    ShallowBox third(5);
    third = first;
    *third.value = 42;
    cout << "first after third assignment: ";
    first.print();

    return 0;
}

/*
Dry run summary:
- second = first shares the same pointer, so changing one changes the other.
- third = first via assignment also shares the same pointer.
- This is the classic shallow-copy behavior that can lead to double delete bugs.
*/
