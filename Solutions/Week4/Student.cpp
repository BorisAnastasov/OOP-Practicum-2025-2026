#pragma once
#include "Student.h"

Student::Student() = default;

Student::Student(int id, std::string name, std::string facultyNumber)
	:id(id), name(name), facultyNumber(facultyNumber) {
}
int Student::getId() const {
	return this->id;
}
void Student::setId(int id){
	this->id = id;
}
std::string Student::getName()const {
	return this->name;
}
void Student::setName(std::string name) {
	this->name = name;
}
std::string Student::getFacultyNumber() const {
	return this->facultyNumber;
}
void Student::setFacultyNumber(std::string fN) {
	this->facultyNumber = fN;
}
void Student::print() const {
	std::print("Name: {}\n", name);
	std::print("Faculty Number: {}\n", facultyNumber);
}