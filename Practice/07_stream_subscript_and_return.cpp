#include <iostream>
using namespace std;

class IntBox
{
    int data[5];

public:
    IntBox()
    {
        for (int i = 0; i < 5; i++)
            data[i] = i + 1;
    }

    int& operator[](int index)
    {
        return data[index];
    }

    const int& operator[](int index) const
    {
        return data[index];
    }

    friend ostream& operator<<(ostream& out, const IntBox& box)
    {
        for (int i = 0; i < 5; i++)
            out << box.data[i] << ' ';
        return out;
    }

    friend istream& operator>>(istream& in, IntBox& box)
    {
        for (int i = 0; i < 5; i++)
            in >> box.data[i];
        return in;
    }
};

int& pickRef(int& a, int& b)
{
    (void)b;
    return a;
}

int* pickPtr(int& a)
{
    return &a;
}

int main()
{
    IntBox box;
    cout << box << endl;
    box[2] = 99;
    cout << box << endl;

    int a = 5, b = 9;
    int& ref = pickRef(a, b);
    int* ptr = pickPtr(b);
    ref = 11;
    *ptr = 22;
    cout << a << ' ' << b << endl;

    return 0;
}

/*
Dry run summary:
- operator[] returns a reference, so the left side can be assigned to.
- operator<< and operator>> are chained by returning the stream reference.
- return-by-reference and return-by-pointer both expose the original storage.
*/
