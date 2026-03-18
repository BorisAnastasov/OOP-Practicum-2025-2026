#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class StreamWrapper {
private:
	 string path;
	 string convertPath(string filename) {
		 return this->path + "/" + filename;
	 }
public:
	StreamWrapper(string filename) : path(filename) {}

	string read(string filename) {
		string fullpath = convertPath(filename);

		ifstream in(fullpath, std::ios::app);
		if (!in.is_open()) {
			cerr << "Cannot open this file!" << endl;
			return "";
		}
		string temp;
		while (in.eof()) {
			temp = in.getline('\n', 1000);
		}
		in.close();
	}

	void write(string filename, const string& str)  {
		string fullpath = convertPath(filename);

		ofstream out(fullpath, std::ios::app);
		if (!out.is_open()) {
			cerr << "Cannot open this file!" << endl;
			return;
		}
		out << str << endl;

		out.close();
	}
};
int main() {
	StreamWrapper s("D:\University\GitHub\OOP-Practicum-2025-2026\Solutions\Solutions.slnx");

	string str = s.read("text.txt");
	s.write("text.txt","Something");
}