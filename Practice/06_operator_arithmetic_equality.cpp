#include <iostream>
using namespace std;

class Point
{
public:
    int x;
    int y;

    Point(int x = 0, int y = 0) : x(x), y(y) {}

    bool operator==(Point other) const
    {
        return x == other.x && y == other.y;
    }

    bool equalByRef(const Point& other) const
    {
        return x == other.x && y == other.y;
    }

    Point operator+(int n) const
    {
        return Point(x + n, y + n);
    }

    Point operator+(const Point& other) const
    {
        return Point(x + other.x, y + other.y);
    }

    Point& addInPlace(int n)
    {
        x += n;
        y += n;
        return *this;
    }

    void print() const
    {
        cout << x << ' ' << y << endl;
    }
};

Point addPointFriend(int n, const Point& p)
{
    return Point(p.x + n, p.y + n);
}

int main()
{
    Point p1(1, 2), p2(1, 2), p3(5, 7);

    cout << boolalpha;
    cout << "by value equality: " << (p1 == p2) << endl;
    cout << "by ref equality:   " << p1.equalByRef(p2) << endl;

    Point p4 = p1 + 10;
    Point p5 = p1 + p3;
    Point p6 = addPointFriend(10, p1);

    p4.print();
    p5.print();
    p6.print();

    p1.addInPlace(4).addInPlace(1);
    cout << "after chaining addInPlace: ";
    p1.print();

    return 0;
}

/*
Dry run summary:
- operator== by value makes a copy of the right-hand object.
- equalByRef avoids the copy.
- member operator+ handles Point + int and Point + Point.
- addInPlace returns *this so calls can chain.
*/
