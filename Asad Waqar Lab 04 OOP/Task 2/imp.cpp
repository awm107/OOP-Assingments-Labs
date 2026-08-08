#include"Student.h"
#include<iostream>
using namespace std;

Student::Student()
{
	StudentName = NULL;
	CNIC = 0;
	Degree = NULL;
	RollNumber = 0;
	Address = NULL;
}

Student::Student(char* Sname, long long cnic, char* deg, int rNum, char* address)
{
	int count = 0;
	while (*(Sname + count) != '\0')
	{
		count++;

	}
	StudentName = new char[count];
	count = 0;
	while (*(Sname + count) != '\0')
	{
		*(StudentName + count) = *(Sname + count);
		count++;
	}
	CNIC = cnic;

	count = 0;
	while (*(deg + count) != '\0')
	{
		count++;

	}
	Degree = new char[count];
	count = 0;
	while (*(deg + count) != '\0')
	{
		*(Degree + count) = *(deg + count);
		count++;
	}
	RollNumber = rNum;

	count = 0;
	while (*(address + count) != '\0')
	{
		count++;

	}
	Address = new char[count];
	count = 0;
	while (*(address + count) != '\0')
	{
		*(Address + count) = *(address + count);
		count++;
	}
}

void Student::setName(char* Sname)
{
	int count = 0;
	while (*(Sname + count) != '\0')
	{
		count++;

	}
	StudentName = new char[count];
	count = 0;
	while (*(Sname+count)!='\0')
	{
		*(StudentName + count) = *(Sname + count);
		count++;
	}
	cout << endl;
}

void Student::setCNIC(long long cnic)
{
	CNIC = cnic;
	cout << endl;
}

void Student::setDegree(char* deg)
{
	int count = 0;
	while (*(deg + count) != '\0')
	{
		count++;

	}
	Degree = new char[count];
	count = 0;
	while (*(deg + count) != '\0')
	{
		*(Degree + count) = *(deg + count);
		count++;
	}
	cout << endl;
}

void Student::setRollnum(int rNum)
{
	RollNumber = rNum;
	cout << endl;
}

void Student::setAddress(char* address)
{
	int count = 0;
	while (*(address + count) != '\0')
	{
		count++;

	}
	Address = new char[count];
	count = 0;
	while (*(address + count) != '\0')
	{
		*(Address + count) = *(address + count);
		count++;
	}
	cout << endl;
}

char* Student::getName()
{
	return StudentName;
}

long long Student::getCNIC()
{
	return CNIC;
}

char* Student::getDegree()
{
	return Degree;
}

int Student::getRollNum()
{
	return RollNumber;
}

char* Student::getAddress()
{
	return Address;
}

void Student::InputData()
{
	int size = 30, cnic = 0, rollN = 0;
	char* nameArray = new char[size];

	cout << "Please enter the following data for the student: " << endl;
	cout << "Name: ";
	cin.getline(nameArray, size);
	setName(nameArray);
	cout << endl;

	cout << "CNIC: ";
	cin >> cnic;
	setCNIC(cnic);
	cout << endl;

	char* degName = new char[size];
	cout << "Degree: ";
	cin.getline(degName, size);
	setDegree(degName);
	cout << endl;

	cout << "Roll Number: ";
	cin >> rollN;
	setRollnum(rollN);

	char* addressName = new char[size];
	cout << "Address: ";
	cin.getline(addressName, size);
	setAddress(addressName);
	cout << endl << endl;
	
}

void Student::printData()
{
	int count = 0;
	while (*(StudentName + count) != '\0')
	{
		cout << "Student name is: " << *(StudentName + count);
		count++;
	}
	cout << endl;
	cout << "Student CNIC: " << CNIC;
	
	count = 0;
	while (*(Degree + count) != '\0')
	{
		cout << "Student degree is: " << *(Degree + count);
		count++;
	}
	cout << endl;
	cout << "Student roll number is: " << RollNumber ;

	count = 0;
	while (*(Address + count) != '\0')
	{
		cout << "Student address is: " << *(Address + count);
		count++;
	}
	cout << endl << endl;
}

Student::~Student()
{
	delete[] StudentName;
	delete[] Degree;
	delete[] Address;
}
