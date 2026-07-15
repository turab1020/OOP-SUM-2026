#include <iostream>
using namespace std;

class BasePublic
{
public:
    int a;
    BasePublic(int a = 0) : a(a) {}
    void show() const { cout << a << endl; }
};

class DerivedPublic : public BasePublic
{
public:
    int b;
    DerivedPublic(int a = 0, int b = 0) : BasePublic(a), b(b) {}
    void show() const { cout << a << ' ' << b << endl; }
};

class BaseProtected
{
protected:
    int value;

public:
    BaseProtected(int value = 0) : value(value) {}
};

class DerivedProtected : public BaseProtected
{
public:
    DerivedProtected(int value = 0) : BaseProtected(value) {}
    void show() const { cout << value << endl; }
};

class BasePrivate
{
private:
    int secret;

public:
    BasePrivate(int secret = 0) : secret(secret) {}

    int reveal() const { return secret; }
};

int main()
{
    DerivedPublic dp(5, 9);
    dp.show();

    DerivedProtected dpro(7);
    dpro.show();

    // BasePrivate access is intentionally not shown directly.
    // Private members are not accessible from derived classes.
    BasePrivate bp(11);
    cout << bp.reveal() << endl;
    (void)bp;

    return 0;
}

/*
Dry run summary:
- public inheritance keeps public data public.
- protected data can be used inside the derived class but not from main.
- private data in the base stays hidden from derived classes.
*/
