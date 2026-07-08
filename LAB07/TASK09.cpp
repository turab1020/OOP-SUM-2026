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

	void operator()() {
		cout << "Agent " << name << " reporting..." << endl;
		cout << "Mission count: " << missions << endl;
		cout << "Status: Active" << endl;
	}

	void operator()(string command) {
		cout << "Agent " << name << " activated command:" << endl;
		cout << command << endl;
	}
};

int main() {
	SpyAgent panther("Panther", 10);

	panther();
	cout << endl;
	panther("Stealth Mode");

	return 0;
}