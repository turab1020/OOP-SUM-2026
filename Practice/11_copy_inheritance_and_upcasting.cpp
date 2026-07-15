#include <iostream>
using namespace std;

class A
{
public:
    int a;
    A(int a = 0) : a(a) {}
    A(const A& other) : a(other.a)
    {
        cout << "A copy ctor\n";
    }
};

class B : public A
{
public:
    int b;
    B(int a = 0, int b = 0) : A(a), b(b) {}
    B(const B& other) : A(other.a), b(other.b)
    {
        cout << "B copy ctor\n";
    }
};

class C : public B
{
public:
    int c;
    C(int a = 0, int b = 0, int c = 0) : B(a, b), c(c) {}
    void print() const
    {
        cout << a << ' ' << b << ' ' << c << endl;
    }
};

void showAByValue(A a)
{
    cout << "showAByValue: " << a.a << endl;
}

void showAByRef(A& a)
{
    cout << "showAByRef: " << a.a << endl;
}

void showAByPtr(A* a)
{
    cout << "showAByPtr: " << a->a << endl;
}

int main()
{
    C obj(5, 6, 7);

    A base = obj; // slicing
    cout << base.a << endl;

    A& ref = obj;
    showAByRef(ref);

    A* ptr = &obj;
    showAByPtr(ptr);

    showAByValue(obj); // copy constructor of A is used for the parameter

    B copied = obj; // B copy constructor from derived object to base subobject copy path
    cout << copied.a << ' ' << copied.b << endl;

    return 0;
}

/*
Dry run summary:
- A base = obj slices off the derived part.
- A& and A* still point to the base subobject without copying.
- Passing by value triggers a copy.
*/
