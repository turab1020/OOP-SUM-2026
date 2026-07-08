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

    friend SpyAgent operator++(SpyAgent& agent);
    friend SpyAgent operator--(SpyAgent& agent);
    friend SpyAgent operator+(const SpyAgent& lhs, const SpyAgent& rhs);
    friend SpyAgent operator-(const SpyAgent& lhs, const SpyAgent& rhs);
    friend SpyAgent operator*(const SpyAgent& lhs, const SpyAgent& rhs);
    friend SpyAgent operator/(const SpyAgent& lhs, const SpyAgent& rhs);

    int getMissions() const {
        return missions;
    }
};

SpyAgent operator++(SpyAgent& agent) {
    ++agent.missions;

    cout << "Agent " << agent.name << " promoted. Missions: " << agent.missions << endl;

    return agent;
}

SpyAgent operator--(SpyAgent& agent) {
    --agent.missions;

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