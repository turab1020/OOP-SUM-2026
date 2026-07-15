#include <iostream>
using namespace std;

class Point
{
public:
    int* x;
    int y;
    static int count;

    Point(int x = 0, int y = 0)
    {
        this->x = new int(x);
        this->y = y;
        count++;
        cout << "ctor " << *this->x << ' ' << this->y << endl;
    }

    Point(const Point& other)
    {
        x = new int(*other.x);
        y = other.y;
        count++;
        cout << "copy ctor\n";
    }

    ~Point()
    {
        delete x;
        count--;
        cout << "dtor\n";
    }

    void set(int x, int y)
    {
        this->x[0] = x;
        this->y = y;
    }

    void print() const
    {
        cout << *x << ' ' << y << endl;
    }

    static void showCount()
    {
        cout << "count = " << count << endl;
    }
};

int Point::count = 0;

class Student
{
private:
    int rollno;
    string name;
    float cgpa;

public:
    Student() : rollno(0), name("xyz"), cgpa(0.0f)
    {
        cout << "Student default ctor\n";
    }

    Student(int rollno, string name, float cgpa) : rollno(rollno), name(name), cgpa(cgpa)
    {
        cout << "Student parameterized ctor\n";
    }

    void setData(int rollno, string name, float cgpa);
    void printData() const;
    void setRollNo(int rollno) { this->rollno = rollno; }
    int getRollNo() const { return rollno; }
    float calculate(float marks) const { return marks / 300.0f * 100.0f; }
};

void Student::setData(int rollno, string name, float cgpa)
{
    cout << "Student::setData this=" << this << endl;
    this->rollno = rollno;
    this->name = name;
    this->cgpa = cgpa;
}

void Student::printData() const
{
    cout << rollno << ' ' << name << ' ' << cgpa << endl;
}

int main()
{
    Point p1(1, 10);
    Point p2 = p1;
    p2.set(2, 20);
    p1.print();
    p2.print();
    Point::showCount();

    Student s1;
    Student s2(7, "Ali", 3.5f);
    s1.setData(1, "Sara", 3.2f);
    s1.printData();
    s2.printData();
    s2.setRollNo(8);
    cout << s2.getRollNo() << endl;
    cout << s2.calculate(250.0f) << endl;

    return 0;
}

/*
Dry run summary:
- Constructor with default arguments handles both default and parameterized calls.
- this-> disambiguates member names from parameters.
- static count is shared by all objects.
- initializer list is shown in Student.
*/
