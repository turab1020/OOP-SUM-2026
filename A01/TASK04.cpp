#include <iostream>
using namespace std;

class MyString {
private:
    char* data;
    int length;

public:
    MyString(const char* str = "") {
        if (str == nullptr) {
            str = "";
        }

        length = 0;

        while (*(str + length) != '\0') {
            length++;
        }

        data = new char[length + 1];

        for (int i = 0; i <= length; i++) {
            *(data + i) = *(str + i);
        }
    }

    MyString(const MyString& other) {
        length = other.length;
        data = new char[length + 1];

        for (int i = 0; i <= length; i++) {
            *(data + i) = *(other.data + i);
        }
    }

    char operator[](int index) {
        if (index < 0 || index >= length) {
            return '\0';
        }

        return *(data + index);
    }

    MyString operator+(const MyString& other) {
        char* buffer = new char[length + other.length + 1];

        for (int i = 0; i < length; i++) {
            *(buffer + i) = *(data + i);
        }

        for (int i = 0; i < other.length; i++) {
            *(buffer + length + i) = *(other.data + i);
        }

        *(buffer + length + other.length) = '\0';

        MyString result(buffer);
        delete[] buffer;
        return result;
    }

    bool operator==(const MyString& other) {
        if (length != other.length) {
            return false;
        }

        for (int i = 0; i < length; i++) {
            if (*(data + i) != *(other.data + i)) {
                return false;
            }
        }

        return true;
    }

    friend ostream& operator<<(ostream& out, const MyString& str) {
        out << str.data;
        return out;
    }

    ~MyString() {
        delete[] data;
    }
};

int main() {
    MyString first("FAST");
    MyString second(" OOP");
    MyString third = first + second;

    cout << "String 1: " << first << "\n";
    cout << "String 2: " << second << "\n";
    cout << "Concatenated String: " << third << "\n";
    cout << "Character at Index 1 of String 1: " << first[1] << "\n";
    cout << "Equality Check Between String 1 and String 2: " << (first == second ? "Yes" : "No") << "\n";

    return 0;
}