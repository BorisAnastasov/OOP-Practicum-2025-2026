#include <iostream>
using namespace std;

class Book {
	std::string title;
	std::string author;
	int pages;
public:
	Book() :pages(0), title(""), author("") {
		cout << "Default constructor called" << endl;
	}

	Book(const std::string& title, const std::string& author, int pages)
		: title(title), author(author), pages(pages) {
		cout << "Parameterized constructor called" << endl;
	}

	Book(const Book& book)
		: title(book.title), author(book.author), pages(book.pages) {
		cout << "Copy constructor called" << endl;
	}
	~Book() {
		cout << "Destructor called for " << this->title << endl;
	}

	void printInfo()const {
		cout << "Title: " << this->title << endl;
		cout << "Author: " << this->author << endl;
		cout << "Pages: " << this->pages << endl;
	}

};

int main()
{
	Book book1;
	Book book2("Programming", "Ivan Ivanov", 120);
	Book book3(book1);
}