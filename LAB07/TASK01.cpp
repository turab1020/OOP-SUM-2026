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

    int getMissions() const {
        return missions;
    }
};

int main() {
    SpyAgent a1("Panther", 10);
    SpyAgent a2("Clouseau", 5);

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

    return 0;
}