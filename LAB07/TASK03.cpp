#include <iostream>
#include <string>

using namespace std;

class SpyLog {

private:
    string agentName;
    string operation;
    int clearance;

public:
    SpyLog() {
        agentName = "";
        operation = "";
        clearance = 0;
    }

    friend void printLog(const SpyLog& log);
    friend istream& operator>>(istream& is, SpyLog& log);
    friend ostream& operator<<(ostream& os, const SpyLog& log);
};

void printLog(const SpyLog& log) {
    cout << "Agent: " << log.agentName << " | Operation: " << log.operation << " | Clearance: " << log.clearance << endl;
}

istream& operator>>(istream& is, SpyLog& log) {
    cout << "Enter agent name: ";
    getline(is, log.agentName);

    cout << "Enter operation: ";
    getline(is, log.operation);

    cout << "Enter clearance level: ";
    is >> log.clearance;

    return is;
}

ostream& operator<<(ostream& os, const SpyLog& log) {
    os << "Agent: " << log.agentName << " | Operation: " << log.operation << " | Clearance: " << log.clearance;

    return os;
}

int main() {
    SpyLog log;
    cin >> log;

    cout << "Pink Panther is processing log..." << endl;
    printLog(log);

    return 0;
}