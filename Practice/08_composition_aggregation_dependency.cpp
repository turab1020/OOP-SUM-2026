#include <iostream>
using namespace std;

class Address
{
public:
    string city;

    Address(string city = "") : city(city) {}

    Address(const Address& other) : city(other.city)
    {
        cout << "Address copy ctor\n";
    }
};

class Person
{
    Address address;

public:
    string name;

    Person(string name, Address address) : address(address), name(name) {}

    void print() const
    {
        cout << name << " lives in " << address.city << endl;
    }

    friend class Inspector;
};

class Inspector
{
public:
    void inspect(const Person& p)
    {
        cout << "Inspector sees: " << p.name << endl;
    }
};

class Team
{
public:
    Address* addr;

    Team(Address* addr = nullptr) : addr(addr) {}
};

void useByValue(Address a)
{
    cout << "by value: " << a.city << endl;
}

void useByReference(Address& a)
{
    a.city = "Changed";
}

void dependencyDemo()
{
    Address temp("Lahore");
    useByValue(temp);
    useByReference(temp);
    cout << temp.city << endl;
}

int main()
{
    Address addr("Karachi");
    Person p("Ali", addr);
    p.print();

    Inspector inspector;
    inspector.inspect(p);

    Team team(&addr);
    cout << team.addr->city << endl;

    dependencyDemo();
    return 0;
}

/*
Dry run summary:
- Composition stores Address as an actual member inside Person.
- Aggregation/association uses a pointer that points to external Address storage.
- Passing Address by value triggers a copy constructor.
- Passing by reference mutates the original object.
*/
