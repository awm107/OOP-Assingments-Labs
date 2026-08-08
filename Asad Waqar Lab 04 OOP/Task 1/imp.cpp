#include"Employee.h"
#include<iostream>
Employee::Employee()
{
	ID = 0;
	for (int i = 0; i < size1; i++)
	{
		*(Name+i) = '\0';
	}
	for (int i = 0; i < size2; i++)
	{
		*(DeptName+i) = '\0';
	}
}
Employee::Employee(int empID, char *empName, char *depName)
{
	ID = empID;
	for (int i = 0; i < size1; i++)
	{
		*(Name+i) = *(empName+i);
	}
	for (int i = 0; i < size2; i++)
	{
		*(DeptName+i) = *(depName+i);
	}
}
Employee::Employee(int empID, char *empName)
{
	ID = empID;
	for (int i = 0; i < size1; i++)
	{
		*(Name + i) = *(empName + i);
	}
	for (int i = 0; i < size2; i++)
	{
		*(DeptName + i) = '\0';
	}
}

void Employee::setID(int empID)
{
	/*cout << "Please enter the ID of the employee: ";
	cin >> empID;*/
	ID = empID;
}

int Employee::getID()
{
	return ID;
}

void Employee::setName(char *EmpName)
{
	//cout << "Please enter the name of the employee: ";
	//cin.getline(empName, size1);
	int count = 0;
	while (*(EmpName+count)!='\0')
	{
		*(Name + count) = *(EmpName + count);
		count++;
	}
}

char *Employee::getName()
{
	return Name;
}

void Employee::setDeptName(char *depName)
{
	int count = 0;
	while (*(depName + count) != '\0')
	{
		*(DeptName + count) = *(depName + count);
		count++;
	}
}

char *Employee::getDeptName()
{
	return DeptName;
}

void Employee::displayData()
{
	cout << "Employee's ID: ";
	cout<<getID();
	cout << endl;
	char* p1=new char[size1];
	char* p2=new char[size2];
	cout << "Employee's name: ";
	p1=getName();
	int count = 0;
	while (*(p1+count)!='\0')
	{
		cout << p1[count];
		count++;
	}
	count = 0;

	cout << endl;
	cout << "Department name: ";
	p2=getDeptName();
	while (*(p2 + count) != '\0')
	{
		cout << *(p2 + count);
		count++;
	}
	cout << endl;
}

Employee::~Employee()
{
	delete[]Name;
	delete[]DeptName;
}
