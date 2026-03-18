#include <iostream>
#include <fstream>
using namespace std;

class Thermometer {
	double celsius;
public:

	Thermometer(double celsius) : celsius(celsius) {}

	void setTemperature(double temp) {
		if (temp < -273.15) {
			cerr << "Invalid value!";
		}
		this->celsius = temp;
	}

	double getFahrenheit() const {
		return (this->celsius * 1.8) + 32;
	}

	void logTemperature(const std::string& filename) const {
		ofstream out(filename, std::ios::app);
		if (!out.is_open()) {
			cerr << "Cannot open this file!" << endl;
			return;
		}
		out << this->celsius << " " << getFahrenheit()<< endl;
	}
};


int main()
{
	
}
