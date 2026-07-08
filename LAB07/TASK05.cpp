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

    SpyAgent& operator=(const SpyAgent& other) {
        if (this != &other) {
            name = other.name;
            missions = other.missions;
        }

        return *this;
    }

    int getMissions() const {
        return missions;
    }

    friend SpyAgent& operator++(SpyAgent& agent);
    friend SpyAgent& operator--(SpyAgent& agent);
    friend SpyAgent operator+(const SpyAgent& lhs, const SpyAgent& rhs);
    friend SpyAgent operator-(const SpyAgent& lhs, const SpyAgent& rhs);
    friend SpyAgent operator*(const SpyAgent& lhs, const SpyAgent& rhs);
    friend SpyAgent operator/(const SpyAgent& lhs, const SpyAgent& rhs);
    friend SpyAgent& operator+=(SpyAgent& lhs, const SpyAgent& other);
    friend SpyAgent& operator-=(SpyAgent& lhs, const SpyAgent& other);
    friend ostream& operator<<(ostream& os, const SpyAgent& agent);
    friend istream& operator>>(istream& is, SpyAgent& agent);

    bool operator==(const SpyAgent& other) const {
        return missions == other.missions;
    }

    bool operator!=(const SpyAgent& other) const {
        return missions != other.missions;
    }

    bool operator<(const SpyAgent& other) const {
        return missions < other.missions;
    }

    bool operator>(const SpyAgent& other) const {
        return missions > other.missions;
    }

    bool operator<=(const SpyAgent& other) const {
        return missions <= other.missions;
    }

    bool operator>=(const SpyAgent& other) const {
        return missions >= other.missions;
    }
};

SpyAgent& operator++(SpyAgent& agent) {
    agent.missions += 1;

    cout << "Agent " << agent.name << " promoted. Missions: " << agent.missions << endl;

    return agent;
}

SpyAgent& operator--(SpyAgent& agent) {
    agent.missions -= 1;

    cout << "Agent " << agent.name << " demoted. Missions: " << agent.missions << endl;

    return agent;
}

SpyAgent operator+(const SpyAgent& lhs, const SpyAgent& rhs) {
    SpyAgent temp;
    temp.missions = lhs.missions + rhs.missions;

    return temp;
}

SpyAgent operator-(const SpyAgent& lhs, const SpyAgent& rhs) {
    SpyAgent temp;
    temp.missions = lhs.missions - rhs.missions;

    return temp;
}

SpyAgent operator*(const SpyAgent& lhs, const SpyAgent& rhs) {
    SpyAgent temp;
    temp.missions = lhs.missions * rhs.missions;

    return temp;
}

SpyAgent operator/(const SpyAgent& lhs, const SpyAgent& rhs) {
    SpyAgent temp;
    temp.missions = lhs.missions / rhs.missions;

    return temp;
}

SpyAgent& operator+=(SpyAgent& lhs, const SpyAgent& other) {
    lhs.missions += other.missions;
    return lhs;
}

SpyAgent& operator-=(SpyAgent& lhs, const SpyAgent& other) {
    lhs.missions -= other.missions;
    return lhs;
}

ostream& operator<<(ostream& os, const SpyAgent& agent) {
    os << "Agent " << agent.name << " missions: " << agent.missions;
    return os;
}

istream& operator>>(istream& is, SpyAgent& agent) {
    is >> agent.name >> agent.missions;
    return is;
}

int main() {
    SpyAgent a1("Panther", 10);
    SpyAgent a2("Clouseau", 5);
    SpyAgent a3("NoName", 10);

    ++a1;
    --a2;

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

    if (a2 < a3) {
        cout << "a2 has less missions than a3" << endl;
    }

    a3 = a1;
    cout << "\nTesting Assignment Operator (a3 = a1):\n" << a3 << endl;

    cout << "\nTesting Compound Assignment Operators:" << endl;
    a1 += a2;
    cout << "After a1 += a2: \n" << a1 << endl;

    a1 -= a2;
    cout << "After a1 -= a2: \n" << a1 << endl;

    return 0;
}