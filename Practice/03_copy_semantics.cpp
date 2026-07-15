#include <iostream>
using namespace std;

class DeepPoint
{
public:
    int* x;
    int y;

    DeepPoint(int vx = 0, int vy = 0)
    {
        x = new int(vx);
        y = vy;
        cout << "DeepPoint ctor\n";
    }

    DeepPoint(const DeepPoint& other)
    {
        x = new int(*other.x);
        y = other.y;
        cout << "DeepPoint copy ctor\n";
    }

    DeepPoint& operator=(const DeepPoint& other)
    {
        cout << "DeepPoint assignment\n";
        if (this != &other)
        {
            delete x;
            x = new int(*other.x);
            y = other.y;
        }
        return *this;
    }

    ~DeepPoint()
    {
        delete x;
    }

    void print() const
    {
        cout << *x << ' ' << y << endl;
    }
};

class SharedPoint
{
public:
    int* x;

    SharedPoint(int vx = 0)
    {
        x = new int(vx);
    }

    // Intentionally shallow for comparison. No delete in destructor to keep the sample safe.
    // In the original crash scenario, both objects would own the same pointer and double delete.
    SharedPoint(const SharedPoint&) = default;
    SharedPoint& operator=(const SharedPoint&) = default;

    void print() const
    {
        cout << *x << endl;
    }
};

DeepPoint makePointByValue(DeepPoint p)
{
    p.y += 1;
    return p;
}

void assignAndShow()
{
    DeepPoint p1(5, 10);
    DeepPoint p2 = p1;   // copy constructor
    DeepPoint p3(1, 1);
    p3 = p1;             // assignment operator

    p2.print();
    p3.print();

    DeepPoint p4 = makePointByValue(p1); // copy constructor into parameter, then return copy
    p4.print();
}

int main()
{
    assignAndShow();

    SharedPoint a(7);
    SharedPoint b = a;   // shallow copy, both point to same int in this demo
    *b.x = 42;
    cout << "shared a: ";
    a.print();
    cout << "shared b: ";
    b.print();

    return 0;
}

/*
Dry run summary:
- p2 = p1 calls copy constructor because p2 is being created.
- p3 = p1 calls assignment operator because p3 already exists.
- Passing DeepPoint by value also calls the copy constructor.
- The shallow-copy example shows both objects observing the same pointed-to int.
*/
