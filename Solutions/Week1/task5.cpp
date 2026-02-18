#include <iostream>
#include <vector>
using namespace std;

enum class Position
{
	Software_Engineer,
	Senior_Software_Engineer,
	Engineer_Manager,
	Lead_Software_Engineer
};

struct Employee
{
	char name[100];
	Position position;
	double salary;
	int mark;


	static string enumToString(const Position& position)
	{
		switch (position) {
		case Position::Software_Engineer:       return "Software Engineer";
		case Position::Senior_Software_Engineer: return "Senior Software Engineer";
		case Position::Engineer_Manager:        return "Engineer Manager";
		case Position::Lead_Software_Engineer:   return "Lead Software Engineer";
		default:                              return "Unknown";
		}
	}

	static void initializeEmployee(Employee& employee) {
		int choice = 0;
		cout << "Enter name: ";
		cin >> employee.name;
		cout << endl << "Enter position: ";
		cin >> choice;
		cout << endl << "Enter salary";
		cin >> employee.salary;
		cout << endl << "Enter mark: ";
		cin >> employee.mark;

		employee.position = (Position)choice;
	}

	void print(const Employee& employee) {
		cout << "Employee's Name: " << employee.name << endl;
		cout << "Position: " << enumToString(employee.position) << endl;
		cout << "Salary: " << employee.salary << endl;
		cout << "Mark" << employee.mark << endl;
	}
};

struct Company
{
	static const int MAX_EMPLOYEES = 100;

	Employee employees[MAX_EMPLOYEES];
	double averageSalary;
	int count;

	static void initializeCompany(Company& company) {
		int count = 0;
		cin >> count;
		company.count = count;

		double sum = 0;
		for (int i = 0; i < company.count; i++) {
			Employee::initializeEmployee(company.employees[i]);
			sum += company.employees[i].salary;
		}

		company.averageSalary = sum / company.count;
	}

	static vector<string> getNamesAboveAverage(const Company& company) {
		vector<string> result{};
		for (int i = 0; i < company.count; i++)
		{
			if (company.employees[i].salary >= company.averageSalary) {
				result.push_back(company.employees[i].name);
			}
		}

		//Selection Sort
		for (int i = 0; i < result.size() - 1; i++)
		{
			int minIndex = i;

			for (int j = i + 1; j < result.size(); j++)
			{
				if (result[j] < result[minIndex]) {
					minIndex = j;
				}
			}
			if (minIndex != i) {
				string temp = result[i];
				result[i] = result[minIndex];
				result[minIndex] = temp;
			}
		}
		return result;
	}

	static void printSmallestMarkPerPosition(const Company& company) {
		for (int i = 0; i < 4; i++)
		{
			int min = INT_MAX;
			int max = INT_MIN;
			for (int i = 0; i < company.count; i++)
			{
				if ((int)company.employees[i].position == i) {
					if (company.employees[i].mark > max)
					{
						max = company.employees[i].mark;
					}
					if (company.employees[i].mark < max)
					{
						min = company.employees[i].mark;
					}
				}
			}

			cout << Employee::enumToString(company.employees[i].position) << ": " << endl;
			cout << "Min: " << (min == INT_MAX) ? 0 : min;
			cout << "Max: " << (max == INT_MIN) ? 0 : max;
		}
	}
};

void printVectorString(vector<string> vec) {
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << endl;
	}
}

int main()
{
	Company company{};
	Company::initializeCompany(company);

	vector<string> result = Company::getNamesAboveAverage(company);

	printVectorString(result);
	Company::printSmallestMarkPerPosition(company);

}