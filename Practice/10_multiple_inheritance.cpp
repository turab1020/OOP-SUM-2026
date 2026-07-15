#include <iostream>
using namespace std;

class A
{
public:
    A(int v = 1) { cout << "A ctor " << v << endl; }
    void print() const { cout << "A\n"; }
};

class B
{
public:
    B(int v = 2) { cout << "B ctor " << v << endl; }
    void print() const { cout << "B\n"; }
};

class C : public B, public A
{
public:
    C(int x, int y) : B(x), A(y) {}
    void print() const
    {
        cout << "C\n";
    }
};

class Shape
{
public:
    virtual void draw() const { cout << "shape\n"; }
};

class InheritanceVsComposition
{
    A a;

public:
    B b;
    InheritanceVsComposition() : a(10), b(20) {}
};

int main()
{
    C obj(1, 2);
    obj.print();
    obj.B::print();
    obj.A::print();

    InheritanceVsComposition demo;
    (void)demo;

    return 0;
}

/*
Dry run summary:
- Base constructors run in the order of the inheritance list: B then A.
- Scope resolution removes ambiguity when both base classes have print().
- The child can override print() and hide the ambiguity.
*/
