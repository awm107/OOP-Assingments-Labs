using namespace std;
#include <iostream>

//Sample class to demonstrate operator overloading
class Sample
{
	//private data members
private:
	int value;

public:
	//default constructor
	Sample()
	{
		value = 0;
	}

	//Parameterized constructor
	Sample(int c)
	{
		value = c;
	}

	//making operator overloading declaration as 
	//friend function
	friend Sample operator+(Sample obj, Sample obj2);

	//printing value
	void printValue()
	{
		cout << "Value is : " << value << endl;
	}
};

//overator overloading function definition
Sample operator+(Sample obj, Sample obj1)
{
	Sample S;
	S = obj.value + obj1.value;
	return S;
}

//main program
int main()
{
	int i = 0;
	//object declaration by calling parameterized constructor
	Sample S1(100);
	Sample S6(500);
	Sample S2(200);
	
	Sample S3;

	//adding objects (Binary + operator overloading)
	S3 = S1 + S2;

	cout << "S1 :" << endl;
	S1.printValue();

	cout << "S2 :" << endl;
	S2.printValue();

	cout << "S3 :" << endl;
	S3.printValue();

	return 0;
}