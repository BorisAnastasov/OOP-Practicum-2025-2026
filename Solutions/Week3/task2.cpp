#include <iostream>
using namespace std;

class Character {
	std::string name;
	int level;
	int health;
	int mana;
	int strength;
	int agility;

	Character(std::string& name, int level, int health, int mana, int strength, int agility)
		: name(name), level(level), health(health), mana(mana), strength(strength), agility(agility) {
	}

public:
	static class Builder {
	private:
		std::string name_;
		int level_;
		int health_;
		int mana_;
		int strength_;
		int agility_;
	public:
		Builder(const std::string name) : name_(name), level_(1), health_(100), mana_(50), strength_(10), agility_(10) {}

		Builder& setLevel(int level) {
			this->level_ = level;
			return *this;
		}
		Builder& setHealth(int health) {
			this->health_ = health;
			return *this;
		}
		Builder& setMana(int mana) {
			this->mana_ = mana;
			return *this;
		}
		Builder& setStrength(int strength) {
			this->strength_ = strength;
			return *this;
		}
		Builder& setAgility(int agility) {
			this->agility_ = agility;
			return *this;
		}
		Character build() {
			Character ch(name_, level_, health_, mana_, strength_, agility_);
			return ch;
		}
	};

};

int main() {
	Character character = Character::Builder("Name")
		.setAgility(30)
		.setHealth(20)
		.build();
}