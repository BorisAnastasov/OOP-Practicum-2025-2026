#include "StudentRepository.h"

int StudentRepository::nextId = 0;

StudentRepository::StudentRepository(const std::string& filename) {
	std::ifstream in(filename);
	if (!in.is_open());
	std::string temp;

	while (!in.eof())
	{
		std::string name;
		std::string facultyNumber;
		in >> name >> facultyNumber;
		Student student(nextId++,name, facultyNumber);
		students.push_back(std::move(student));
	}

	in.close();
}

void StudentRepository::addStudent(const std::string& name, const std::string& facultyNumber) {
	Student student(nextId++, name, facultyNumber);
	students.push_back(std::move(student));
}

std::optional<Student> StudentRepository::findById(int id) const {
	for (const Student& student : students) {
		if (student.getId() == id) {
			return student;
		}
	}
	return std::nullopt;
}

bool StudentRepository::updateStudent(int id, const std::string& name, const std::string& facultyNumber) {
	for (Student& student : students) {
		if (student.getId() == id) {
			student.setName(name);
			student.setFacultyNumber(facultyNumber);
			return true;
		}
	}
	return false;
}

bool StudentRepository::deleteStudent(int id) {
	for (auto it = students.begin(); it != students.end(); it++) {
		if (it->getId() == id) {
			students.erase(it);
			return true;
		}
	}
	return false;
}

void StudentRepository::save() const {
	std::ofstream out(filename);
	if (!out.is_open()) return;

	for (const Student& student : students) {
		out << student.getName() << ' ';
		out << student.getFacultyNumber() << std::endl;
	}
	out.close();
}

void StudentRepository::load() {
	std::ifstream in(filename);
	if (!in.is_open()) return;

	while (!in.eof()) {
		std::string name;
		std::string facultyNumber;
		
		in >> name >> facultyNumber;
		addStudent(name, facultyNumber);
	}
	in.close();
}

std::vector<Student> StudentRepository::getAll() const {
	std::vector<Student> copy;
	for (const Student& student : students) {
		copy.push_back(student);
	}
	return copy;
}


