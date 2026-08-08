
//Constructors Vs Member Functions


1)
Constructor name must be same as the class name, but functions cannot have same name as class name.

C++ Code example :

class Car {
	int count;
public:
	//This constructor has same name as class name
	Car() { }

	//function cannot have same name as class 
	void CarAvailable() {
	}
};

Constructor does not have return type whereas functions must have.

C++ code example

class Car {
	int count;
public:
	//Constructor :- No return type
	Car() {
	}
	//@return type int, in C++ function must have return type
	// it can also be void type, means return nothing,
	//but must mention its type.
	int CarAvailable() {
		return count;
	}
	void CarSold() {
	}
};

Member function can be virtual, but, there is no concept of virtual - constructor in C++. (NOTE: virtual destructor to maintain destructor call in inheritance is available in C++ language)

C++ code example

class Car {
	int count;
public:
	//Constructor :- Can never be VIRTUAL,No provision. 
	Car() {
		// 
	}
	//Function can be virtual, so that it can be overriden in derived classes.
	virtual void CarAvailable() {
	}
};

Constructors are invoked at the time of object creation automaticallyand cannot be called explicitly but functions are called explicitly using class objects.

C++ code example

#include<iostream>
using namespace std;

class Car {
public:
	Car() {
		cout << "Car's Constructor\n";
	}
	void CarAvailable() {
		cout << "Car's Function\n";
	}
};

int main() {
	//Constructor will be invoked automatically 
	//during object creation.
	Car obj;

	//Functin can be called using class object, not automatic 
	obj.CarAvailable();

	return 0;
}

*/