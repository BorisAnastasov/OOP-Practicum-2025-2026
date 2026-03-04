
### Теория - какво ще се изпечата?

```cpp
#include <iostream>

class A
{
public:
	A()
	{
		std::cout << "A()" << std::endl;
	}

	~A()
	{
		std::cout << "~A()" << std::endl;
	}
};

class B
{
public:
	B()
	{
		std::cout << "B()" << std::endl;
	}

	~B()
	{
		std::cout << "~B()" << std::endl;
	}
};

class X
{
private:
	A* obj1;
	B& obj2;

public:
	X(const A& a, B& b) : obj2(b)
	{
		obj1 = new A();
		std::cout << "X()" << std::endl;
	}

	~X()
	{
		delete obj1;
		std::cout << "~X()" << std::endl;
	}
};

int main()
{
	A obj1;
	B obj2;

	X obj(obj1, obj2);
}
```

```cpp
#include <iostream>

class A
{
public:
	A()
	{
		std::cout << "A()" << std::endl;
	}

	A(const A& other)
	{
		std::cout << "K.K A()" << std::endl;
	}

	~A()
	{
		std::cout << "~A()" << std::endl;
	}
};

class B
{
public:
	B()
	{
		std::cout << "B()" << std::endl;
	}

	B(const B& other)
	{
		std::cout << "K.K B()" << std::endl;
	}

	~B()
	{
		std::cout << "~B()" << std::endl;
	}
};

class X
{
private:
	A* obj1;
	B obj2;

public:
	X(const A& a, B& b) : obj2(b)
	{
		obj1 = new A(a);
		std::cout << "X()" << std::endl;
	}

	~X()
	{
		delete obj1;
		std::cout << "~X()" << std::endl;
	}
};

int main()
{
	A obj1;
	B obj2;

	X obj(obj1, obj2);
}
```

```cpp
#include <iostream>

class A
{
public:
	A()
	{
		std::cout << "A()" << std::endl;
	}

	A(const A& other)
	{
		std::cout << "K.K A()" << std::endl;
	}

	~A()
	{
		std::cout << "~A()" << std::endl;
	}
};

class B
{
public:
	B()
	{
		std::cout << "B()" << std::endl;
	}

	B(const B& other)
	{
		std::cout << "K.K B()" << std::endl;
	}

	~B()
	{
		std::cout << "~B()" << std::endl;
	}
};

class X
{
private:
	A* obj1;
	B& obj2;

public:
	X(const A& a, B* b) : obj1(new A(a)), obj2(*b)
	{
		std::cout << "X()" << std::endl;
	}

	~X()
	{
		delete obj1;
		std::cout << "~X()" << std::endl;
	}
};

int main()
{
	A obj1;
	B obj2;

	X obj(obj1, &obj2);
}
```

### Задача 1
Създайте клас `Book`, който показва различните видове конструктори и кога се извикват.  

* **Private полета:**  
  * `title` (std::string)  
  * `author` (std::string)  
  * `pages` (int)  

* **Конструктори:**  
  * **Default constructor** – задава празни стойности и 0 страници, извежда "Default constructor called"  
  * **Parameterized constructor** – задава заглавие, автор и брой страници, извежда "Parameterized constructor called"  
  * **Copy constructor** – копира друг обект `Book`, извежда "Copy constructor called"  

* **Деструктор:**  
  * Извежда "Destructor called for [title]"  

* **Методи:**  
  * `printInfo()` – извежда заглавие, автор и брой страници  

**Демонстрация в `main()`:**  
1. Създайте обект с default constructor  
2. Създайте обект с parameterized constructor  
3. Копирайте първия обект чрез copy constructor

### Задача 2
Създайте клас `Character`, който показва как да се използва **builder pattern** за конструктори с много опционални полета.  

* **Private полета:**  
  * `name` (std::string, задължително)  
  * `level` (int, по подразбиране 1)  
  * `health` (int, по подразбиране 100)  
  * `mana` (int, по подразбиране 50)  
  * `strength` (int, по подразбиране 10)  
  * `agility` (int, по подразбиране 10)  

* **Конструктори:**  
  * **Private constructor**, използван само от Builder  

* **Public static Builder клас:**  
  * Методи за задаване на всяко опционално поле (`setLevel()`, `setHealth()`, …)  
  * `build()` – създава `Character` обект  

* **Методи:**  
  * `printStats()` – извежда всички полета
    
### Задача 3
Създайте клас `LinkedList` с `Node` структура и покажете **copy constructor, destructor и push**  

* **Node структура:**  

```cpp
struct Node {
    int data;
    Node* next;

    Node() : data(0), next(nullptr) {};
    Node(int data) : data(data), next(nullptr) {};
};
```

* **Private поле:**  
  * `Node* head`  

* **Методи:**  
  * **Default constructor** – задава `head` на nullptr  
  * **Copy constructor**
  * **Destructor**
  * `pushFront(int data)` – добавя елемент отпред  
  * `pushBack(int data)` – добавя елемент отзад  
  * `print()` – извежда елементите на конзолата  

* **Допълнителни инструкции:**  
  1. Направете си помощни `void copyFrom(const LinkedList& other)` и `void free()` за правилна имплементация на Rule of 3  
