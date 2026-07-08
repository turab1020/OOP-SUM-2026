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

	SpyAgent operator%(const SpyAgent& other) {
		SpyAgent temp;
		temp.name = name;
		temp.missions = missions % other.missions;

		return temp;
	}

	SpyAgent& operator+=(int value) {
		missions += value;
		cout << "Agent " << name << " missions updated: " << missions << endl;

		return *this;
	}

	SpyAgent& operator-=(int value) {
		missions -= value;
		cout << "Agent " << name << " missions updated: " << missions << endl;

		return *this;
	}

	SpyAgent& operator*=(int value) {
		missions *= value;
		cout << "Agent " << name << " missions multiplied: " << missions << endl;

		return *this;
	}

	SpyAgent& operator/=(int value) {
		if (value != 0) {
			missions /= value;
			cout << "Agent " << name << " missions divided: " << missions << endl;
		}
		else {
			cout << "Division by zero not allowed." << endl;
		}

		return *this;
	}

	SpyAgent& operator%=(int value) {
		if (value != 0) {
			missions %= value;
			cout << "Agent " << name << " missions remainder: " << missions << endl;
		}
		else {
			cout << "Modulo by zero not allowed." << endl;
		}

		return *this;
	}

	SpyAgent operator++(int) {
		SpyAgent temp = *this;
		missions += 1;
		cout << "Agent " << name << " promoted. Missions: " << missions << endl;

		return temp;
	}

	SpyAgent operator--(int) {
		SpyAgent temp = *this;
		missions -= 1;
		cout << "Agent " << name << " demoted. Missions: " << missions << endl;

		return temp;
	}

	SpyAgent& operator++() {
		missions += 1;
		cout << "Agent " << name << " promoted. Missions: " << missions << endl;

		return *this;
	}

	SpyAgent& operator--() {
		missions -= 1;
		cout << "Agent " << name << " demoted. Missions: " << missions << endl;

		return *this;
	}

	void display() {
		cout << "Agent " << name << " missions: " << missions << endl;
	}

	int getMissions() const {
		return missions;
	}
};

int main() {
	SpyAgent panther("Panther", 10);
	SpyAgent clouseau("Clouseau", 3);

	SpyAgent result = panther % clouseau;
	cout << "Mission Remainder: " << result.getMissions() << endl;

	SpyAgent a1("Panther", 10);

	a1 += 5;
	cout << "Agent Panther missions updated: " << a1.getMissions() << endl;
	a1 -= 2;
	cout << "Agent Panther missions updated: " << a1.getMissions() << endl;
	a1 *= 2;
	cout << "Agent Panther missions updated: " << a1.getMissions() << endl;
	a1 /= 3;
	cout << "Agent Panther missions updated: " << a1.getMissions() << endl;
	a1 %= 4;
	cout << "Agent Panther missions updated: " << a1.getMissions() << endl;

	SpyAgent a2("Panther", 10);
	a2++;
	++a2;
	a2--;
	--a2;

	return 0;
}
