////Task 1
//Overload the pre - increment operator ++ to convert the MyString to uppercase i.e.all
//lowercase letters in the given MyString will be converted into uppercase.


//Task 2
//Overload the stream insertion operator << to display a MyString on screen.

//Task 3
//Overload the stream extraction operator &gt; &gt; to take input of a MyString from the user.

//Task 4
//Overload the assignment operator( = ) to copy the values of a MyString object to
//another existing MyString object.

//Task 1.6
//Overload the operator == that returns true if the two MyString objects are equal else return
//false.
#include<iostream>
using namespace std;
class MyString
{
private:
	char* str; // Pointer to the char array that holds the string
	int length; // Variable to store the length of the string (excluding NULL)
public:
	// Default constructor to initialize the string to empty string
	MyString()
	{
		str = NULL;
		length = 0;
	}
	// Overloaded constructor
	MyString(const char* sPtr)
	{
		int count = 0;
		while ((*(sPtr + count) != '\0'))
		{
			count++;
		}
		length = count + 1;//so that null char is also included
		str = new char[length];
		for (int i = 0; i < length; i++)
		{
			*(str + i) = *(sPtr + i);
		}
	}

	// Copy constructor
	MyString(const MyString& obj1) //Passed an object by ref and const so that it value is not change
	{
		length = obj1.length;
		str = new char[length];
		for (int i = 0; i < length; i++)
		{
			*(str + i) = *(obj1.str + i);
		}
	}
	// Returns the length (# of characters excluding the null terminator) of the string
	int getLength() 
	{
		return (length-2);
	}
	void operator++()
	{
		char temp=' ';
		for (int i = 0; i < length; i++)
		{
			if (*(str + i) >= 'a' && *(str + i) <= 'z')
			{
				temp = *(str + i);
				temp = int(temp) - 32;
				*(str + i) = temp;
			}
		}
	}

	friend ostream& operator<<(ostream& out, const MyString& obj1)
	{
		out << "OUTPUT: ";
		for (int i = 0; i < obj1.length-1; i++)
		{
			out << obj1.str[i];
		}
		return out;
	}

	friend istream& operator>>(istream& in, MyString& obj1)
	{
		cout << "Enter length of string: ";
		in >> obj1.length;
		obj1.str = new char[obj1.length];
		cout << "Enter string: ";
		in.getline(obj1.str, obj1.length-1);
		return in;
	}

	const MyString& operator=(const MyString& obj1)
	{
		if (this != &obj1) //avoid self-assignment
		{
			delete[] str; 
			length = obj1.length;
			str = new char[length]; 
			for (int i = 0; i < length; i++)
				str[i] = obj1.str[i];
		}
		return *this;
	}
	bool operator==(const MyString& obj1)
	{
		if (length==obj1.length)
		{
			for (int i = 0; i < length; i++)
			{
				if (str[i]!=obj1.str[i])
				{
					return false;
				}
			}
			return true;
		}
		else
		{
			return false;
		}
	}
	~MyString() // Destructor
	{
		delete[]str;
	}
};
int main()
{
	MyString newString("Hello I am Asad \0");
	++newString;
	cout << newString << endl;
	cout << newString.getLength() << endl;

	MyString newString2;
	cin >> newString2;
	cout << newString2 << endl;
	system("pause");
	return 0;
}