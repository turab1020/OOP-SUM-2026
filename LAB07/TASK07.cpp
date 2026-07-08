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

	SpyAgent operator+(int value) {
		SpyAgent temp;
		temp.name = name;
		temp.missions = missions + value;

		return temp;
	}

	SpyAgent operator-(int value) {
		SpyAgent temp;
		temp.name = name;
		temp.missions = missions - value;

		return temp;
	}

	friend SpyAgent operator+(int value, const SpyAgent& agent);

	void display() {
		cout << "Agent " << name << " missions: " << missions << endl;
	}

	int getMissions() const {
		return missions;
	}
};

SpyAgent operator+(int value, const SpyAgent& agent) {
	SpyAgent temp;
	temp.name = agent.name;
	temp.missions = value + agent.missions;

	return temp;
}

int main() {
	SpyAgent a1("Panther", 10);

	SpyAgent result1 = a1 + 5;
	SpyAgent result2 = 5 + a1;
	SpyAgent result3 = a1 - 3;

	cout << "Original Agent: ";
	a1.display();

	cout << "After a1 + 5: ";
	result1.display();

	cout << "After 5 + a1: ";
	result2.display();

	cout << "After a1 - 3: ";
	result3.display();

	return 0;
}
