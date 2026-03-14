#include <iostream>
using namespace std;

class ComplexNumber {
	int a;
	int b;
public:
	ComplexNumber(int a, int b) : a(a), b(b) {}
	ComplexNumber() : a(0), b(0){}

	static ComplexNumber sum(const ComplexNumber& n1, const ComplexNumber& n2) {
		ComplexNumber number;
		number.a = n1.a + n2.a;
		number.b = n1.b + n2.b;
	}



};

int main() {

	
}