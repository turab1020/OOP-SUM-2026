#include <iostream>
using namespace std;

class DeepBox
{
public:
    int* value;

    DeepBox(int v = 0)
    {
        value = new int(v);
        cout << "DeepBox ctor\n";
    }

    DeepBox(const DeepBox& other)
    {
        value = new int(*other.value);
        cout << "DeepBox copy ctor\n";
    }

    DeepBox& operator=(const DeepBox& other)
    {
        cout << "DeepBox assignment\n";
        if (this != &other)
        {
            delete value;
            value = new int(*other.value);
        }
        return *this;
    }

    ~DeepBox()
    {
        delete value;
    }

    void print() const
    {
        cout << *value << endl;
    }
};

int main()
{
    DeepBox first(10);
    DeepBox second = first;
    *second.value = 99;

    cout << "first: ";
    first.print();
    cout << "second: ";
    second.print();

    DeepBox third(5);
    third = first;
    cout << "third: ";
    third.print();

    return 0;
}

/*
Dry run summary:
- second = first uses the copy constructor because second is newly created.
- third = first uses assignment because both objects already exist.
- Changing second.value does not change first.value because each object owns separate memory.
*/
