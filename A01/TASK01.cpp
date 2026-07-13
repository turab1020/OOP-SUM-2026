#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction(int numerator = 0, int denominator = 1) {
        this->numerator = numerator;

        if (denominator == 0) {
            this->denominator = 1;
        }

        else {
            this->denominator = denominator;
        }
    }

    Fraction operator+(const Fraction& other) {
        Fraction result((numerator * other.denominator) + (other.numerator * denominator), denominator * other.denominator);
        return result;
    }

    Fraction operator-(const Fraction& other) {
        Fraction result((numerator * other.denominator) - (other.numerator * denominator), denominator * other.denominator);
        return result;
    }

    bool operator==(const Fraction& other) {
        return numerator * other.denominator == other.numerator * denominator;
    }

    friend ostream& operator<<(ostream& out, const Fraction& fraction) {
        out << fraction.numerator << "/" << fraction.denominator;
        return out;
    }
};

int main() {
    Fraction first(1, 2);
    Fraction second(3, 4);
    Fraction third(2, 4);
    Fraction sum = first + second;
    Fraction difference = first - second;

    cout << "Fraction 1: " << first << "\n";
    cout << "Fraction 2: " << second << "\n";
    cout << "Sum: " << sum << "\n";
    cout << "Difference: " << difference << "\n";
    cout << "Equivalence Check Between Fraction 1 and Fraction 3: " << (first == third ? "Yes" : "No") << "\n";

    return 0;
}