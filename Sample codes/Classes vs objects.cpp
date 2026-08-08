#include <iostream>
#include <cstring>
using namespace std;

//class Phone {};   //This is how you initialize class add semicolon in end and first letter of class name shouold be capital

class Phone { 
private:     // In private access specifier The data cannot be accessed from outside like main

	string p_name;
	string p_model;
public:       // In public access specifier The data cann be accessed from outside like main

	Phone(string name, string model)   // This is constructor and it gives value from main into the variables initialized in private  
	{
		p_name = name;
		p_model = model;
	}

	void makecall()   //These are member functions and called by objects created in main
	{
		cout << "You are making call from " << p_name<<endl;

	}
	void receivecall() 
	{
		cout << "You are receiving call from model number " << p_model;
	}


};

int main()
{
	Phone iphone("Iphone", "X");     // Phone here is class name and iphone is object created. From this class make object iphone and this code will make the constructor run
	iphone.makecall();               // The objects is used to call member functions
	iphone.receivecall();

	//We can create multiple objects of one class
	cout << endl;
	cout << endl;
	Phone samsung("samsung", "S22 Ultra");
	samsung.makecall();
	samsung.receivecall();
	cout << endl;

	return 0;

}

// In conclusion you can create many objects from one class. The main use of objects is to call member functions. 