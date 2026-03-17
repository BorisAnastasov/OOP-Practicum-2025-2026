#include "ValidationUtils.h"

ValidationUtils::ValidationUtils() = delete;

bool ValidationUtils::isEmpty(const std::string& value) {
	return value.empty();
}
bool ValidationUtils::isNumber(const std::string& value) {
	for (const char& c : value) {
		if ('0' < c || c > '9') {
			return false;
		}
	}
	return true;
}

bool ValidationUtils::isValidEmail(const std::string& email) {
	//regex
}

bool ValidationUtils::isValidLength(const std::string& value, size_t min, size_t max) {
	return min <= value.size() <= max;
}

bool ValidationUtils::isAlphabetic(const std::string& value) {
	for (const char& c : value) {
		if (('A' >= c || c >= 'Z') && ('a' >= c || c >= 'z')) {
			return true;
		}
	}
	return false;
}

bool ValidationUtils::isAlphanumeric(const std::string& value) {
	for (const char& c : value) {
		if ((('A' >= c || c >= 'Z') && ('a' >= c || c >= 'z')) || '0'>=c||c>='9') {
			return true;
		}
	}
	return false;
}
bool ValidationUtils::isInRange(int value, int min, int max) {
	if (value >= min && value <= max) {
		return true;
	}
	return false;
}

bool ValidationUtils::isValidFacultyNumber(const std::string& fn) {
	//regex
}

bool ValidationUtils::startsWith(const std::string& value, const std::string& prefix) {
	if (value.size() < prefix.size()) return false;
	
	for (int i = 0; i < prefix.length(); i++){
		if (prefix[i] != value[i]) {
			return false;
		}
	}
	return true;
}

bool ValidationUtils::endsWith(const std::string& value, const std::string& suffix) {
	if (value.size() < suffix.size()) return false;

	for (int i = suffix.length()-1; i >=0 ; i++) {
		if (suffix[i] != value[i]) {
			return false;
		}
	}
	return true;
}
