#include <iostream>
using namespace std;

void byValue(int x)
{
    x = 100;
    cout << "byValue inside: " << x << endl;
}

void byReference(int& x)
{
    x = 100;
    cout << "byReference inside: " << x << endl;
}

void byPointer(int* x)
{
    *x = 100;
    cout << "byPointer inside: " << *x << endl;
}

void repointPointerByValue(int* ptr)
{
    int local = 999;
    ptr = &local;
    cout << "repointPointerByValue inside: " << *ptr << endl;
}

void repointPointerByReference(int*& ptr)
{
    ptr = new int(999);
    cout << "repointPointerByReference inside: " << *ptr << endl;
}

void repointPointerByDoublePointer(int** ptr)
{
    *ptr = new int(888);
    cout << "repointPointerByDoublePointer inside: " << **ptr << endl;
}

void modifyChar(char* ch)
{
    *ch = 'Z';
}

int main()
{
    int a = 5, b = 5, c = 5;

    byValue(a);
    byReference(b);
    byPointer(&c);

    cout << "after value: " << a << endl;
    cout << "after ref:   " << b << endl;
    cout << "after ptr:   " << c << endl;

    int* p = &a;
    repointPointerByValue(p);
    cout << "after ptr by value still points to: " << *p << endl;

    repointPointerByReference(p);
    cout << "after ptr by ref now points to: " << *p << endl;
    delete p;

    p = &a;
    repointPointerByDoublePointer(&p);
    cout << "after ptr by double pointer now points to: " << *p << endl;
    delete p;

    char ch = 'A';
    modifyChar(&ch);
    cout << "char after pointer modify: " << ch << endl;

    return 0;
}

/*
Dry run summary:
- a stays 5 after byValue.
- b becomes 100 after byReference.
- c becomes 100 after byPointer.
- repointPointerByValue cannot change main's pointer.
- repointPointerByReference and repointPointerByDoublePointer can.
*/
