#include <iostream>
#include <string>

using namespace std;

class SpyAgent {

private:
    string name;
    int missions;

public:
    SpyAgent() {
        name = "Unknown";
        missions = 0;
    }

    SpyAgent(string n, int m) {
        name = n;
        missions = m;
    }

    SpyAgent& operator++() {
        this->missions += 1;

        cout << "Agent " << this->name << " promoted. Missions: " << this->missions << endl;

        return *this;
    }

    SpyAgent& operator--() {
        this->missions -= 1;

        cout << "Agent " << this->name << " demoted. Missions: " << this->missions << endl;

        return *this;
    }

    SpyAgent operator+(const SpyAgent& rhs) {
        SpyAgent temp;
        temp.missions = this->missions + rhs.missions;

        return temp;
    }

    SpyAgent operator-(const SpyAgent& rhs) {
        SpyAgent temp;
        temp.missions = this->missions - rhs.missions;

        return temp;
    }

    SpyAgent operator*(const SpyAgent& rhs) {
        SpyAgent temp;
        temp.missions = this->missions * rhs.missions;

        return temp;
    }

    SpyAgent operator/(const SpyAgent& rhs) {
        SpyAgent temp;
        temp.missions = this->missions / rhs.missions;

        return temp;
    }

    friend ostream& operator<<(ostream& os, const SpyAgent& agent) {
        os << "Agent " << agent.name << " missions: " << agent.missions;
        return os;
    }

    friend istream& operator>>(istream& is, SpyAgent& agent) {
        is >> agent.name >> agent.missions;
        return is;
    }

    bool operator==(const SpyAgent& other) const {
        return missions == other.missions;
    }

    bool operator!=(const SpyAgent& other) const {
        return missions != other.missions;
    }

    bool operator>(const SpyAgent& other) const {
        return missions > other.missions;
    }

    int getMissions() const {
        return missions;
    }
};

int main() {
    SpyAgent a1("Panther", 10);
    SpyAgent a2("Clouseau", 5);
    SpyAgent a3("NoName", 10);

    ++a1;
    --a2;
    ++a3;

    SpyAgent sum = a1 + a2;
    SpyAgent diff = a1 - a2;
    SpyAgent prod = a1 * a2;
    SpyAgent div = a1 / a2;

    cout << "\nCombined Missions: " << sum.getMissions() << endl;
    cout << "Mission Difference: " << diff.getMissions() << endl;
    cout << "Multiplied Missions: " << prod.getMissions() << endl;
    cout << "Division: " << div.getMissions() << endl;

    cout << "\nTesting Stream Insertion:\n" << a1 << endl;

    cout << "\nTesting Comparison Operators:" << endl;

    if (a1 > a2) {
        cout << "a1 has more missions than a2" << endl;
    }

    if (a1 == a3) {
        cout << "a1 is equal to a3" << endl;
    }

    if (a1 != a2) {
        cout << "a1 is not equal to a2" << endl;
    }

    return 0;
}