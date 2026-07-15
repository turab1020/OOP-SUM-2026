#include <iostream>
using namespace std;

class ChainBox
{
public:
    int value;

    ChainBox(int v = 0) : value(v) {}

    ChainBox& set(int v)
    {
        value = v;
        return *this;
    }

    ChainBox& add(int v)
    {
        value += v;
        return *this;
    }

    ChainBox operator++()
    {
        value++;
        return *this; // return by value: a copy is made
    }

    void postInc()
    {
        value++;
    }

    void print() const
    {
        cout << value << endl;
    }
};

class ChainBoxRef
{
public:
    int value;

    ChainBoxRef(int v = 0) : value(v) {}

    ChainBoxRef& set(int v)
    {
        value = v;
        return *this;
    }

    ChainBoxRef& add(int v)
    {
        value += v;
        return *this;
    }

    ChainBoxRef& preInc()
    {
        ++value;
        return *this;
    }

    void postInc()
    {
        value++;
    }
};

int main()
{
    ChainBox a;
    a.set(5).add(3);
    cout << "copy-return chain: ";
    a.print();

    ChainBoxRef b;
    b.set(5).add(3).preInc();
    cout << "ref-return chain:  " << b.value << endl;

    b.postInc();
    cout << "after postInc:     " << b.value << endl;

    return 0;
}

/*
Dry run summary:
- Returning by reference lets the next call reuse the same object.
- Returning by value creates a copy, which is slower and can break chaining patterns.
- The original source also shows unsafe post-increment / dangling-reference patterns; those are documented in README rather than executed here.
*/
