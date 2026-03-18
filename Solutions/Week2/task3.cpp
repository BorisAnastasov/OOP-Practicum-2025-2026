#include <iostream>
#include <fstream>
using namespace std;

class AgentInventory {
	std::string agentName;
	size_t healthLevel;
	size_t handgunAmmo;
	size_t greenHerbs;

public:
	void takeDamage(int damage) {
		if (this->healthLevel - damage == 0) {
			this->healthLevel = 0;
			cout << "YOU ARE DEAD" << endl;
			return;
		}
		this->healthLevel -= damage;
	}

	void useHerb() {
		if (this->greenHerbs == 0) {
			cout << "No more herbs!";
			return;
		}
		this->greenHerbs--;
		this->healthLevel += 30;
		if (this->healthLevel > 100) this->healthLevel = 100;
	}
	void shoot() {
		if (this->handgunAmmo == 0) {
			cout << "No more ammo" << endl;
			return;
		}
		this->handgunAmmo--;
	}
	void loot(int ammo, int herbs) {
		if (ammo <= 0 || herbs <= 0) {
			cout << "Must be positive number!" << endl;
			return;
		}
		this->handgunAmmo += ammo;
		this->greenHerbs += herbs;
	}

	void saveProgress(const std::string& filename)const {
		ofstream out(filename);
		if (!out.is_open()) {
			cerr << "Cannot open this file!" << endl;
			return;
		}
		out << "Agent's name: " << this->agentName;
		out << "HealthLevel: " << this->healthLevel;
		out << "Handgun's ammo: " << this->handgunAmmo;
		out << "Green herbs: " << this->greenHerbs;

		out.close();
	}

	void loadProgress(const std::string& filename) {
		ifstream in(filename);
		if (!in.is_open()) {
			cerr << "Cannot open this file!" << endl;
			return;
		}
		in >> this->agentName;
		in >> this->healthLevel;
		in >> this->handgunAmmo;
		in >> this->greenHerbs;

		in.close();
	}
};

int main() {

}