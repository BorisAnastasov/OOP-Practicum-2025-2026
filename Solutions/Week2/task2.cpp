#include <iostream>
#include <fstream>
using namespace std;

class BankAccount {
	std::string accountNumber;
	std::string ownerName;
	double balance;
public:
	BankAccount(const std::string& accountNumber,const std::string& ownerName, double balance)
	:accountNumber(accountNumber), ownerName(ownerName), balance(balance){}

	void deposit(double amount) {
		if (amount <= 0) {
			cerr << "Must be positive number!" << endl;
			return;
		}
		this->balance += amount;
	}

	void withdraw(double amount) {
		if (this->balance - amount < 0) {
			cerr << "Not enought money in the bank account!" << endl;
			return;
		}
		this->balance -= amount;
	}

	void exportStatement(const std::string& filename) {
		ofstream out(filename);
		if (!out.is_open()) {
			cerr << "Cannot open this file!" << endl;
			return;
		}
		out << "Account number: " << this->accountNumber << endl;
		out << "Owner's name: " << this->ownerName << endl;
		out << "Balance: " << this->balance << endl;

		out.close();
	}
};

int main() {

}