#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;

	Node() : data(0), next(nullptr) {};
	Node(int data) : data(data), next(nullptr) {};
};

class LinkedList {
	Node* head;
public:
	LinkedList() {
		this->head = nullptr;
	}

	LinkedList(const LinkedList& list) : head(list.head) {}

	~LinkedList() {
		Node* main = head;
		Node* temp = nullptr;
		while (main != nullptr) {
			temp = main->next;
			delete main;
			main = temp;
		}
		main = nullptr;
	}

	void pushFront(int data) {
		Node* node = new Node(data);
		node->next = head;
		head = node;
	}

	void pushBack(int data) {
		if (head == nullptr) {
			Node* newNode = new Node(data);
			head = newNode;
			return;
		}

		Node* node = head;
		while (node->next != nullptr)
		{
			node = node->next;
		}
		node->next = new Node(data);
	}

	void print() {
		Node* node = head;
		while (node->next != nullptr) {
			cout << node->data << endl;
			node = node->next;
		}
		cout << node->data << endl;
	}

	void copyFrom(const LinkedList& other) {
		Node* temp = this->head;
		if (temp != nullptr) {
			while (temp->next != nullptr) {
				Node* n = temp->next;
				delete temp;
				temp = n;
			}
		}
		temp = other.head;
		Node* node = new Node(temp->data);
		this->head = node;
		temp = temp->next;
		while (temp->next != nullptr)
		{
			this->pushBack(temp->data);
			temp = temp->next;
		}
		this->pushBack(temp->data);
	}
};




int main() {
	LinkedList list1;

	list1.pushBack(10);
	list1.pushBack(20);
	list1.pushFront(5);

	std::cout << "List 1 (original): " << endl;
	list1.print();

	LinkedList list2;
	list2.copyFrom(list1);

	std::cout << "List 2 (copied from List 1): " << endl;

	list2.pushBack(30);
	list2.pushFront(1);

	list2.print();

	return 0;
}