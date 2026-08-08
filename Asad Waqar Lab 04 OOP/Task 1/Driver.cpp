#include"Employee.h"
#include<iostream>
using namespace std;

int main()
{
	int arrSize = 0;
	cout << "Please enter the size for the array of objects: ";
	cin >> arrSize;
	Employee* ptr =new Employee[arrSize];
	int id = 0;
	char empName[size1];
	char depName[size2];

	for (int i = 0; i < arrSize; i++)
	{
		
		cout << "Please enter the ID of the employee: ";
		cin >> id;
		ptr[i].setID(id);
		cout << "Please enter the name of the employee: ";
		cin.getline(empName, size1);
		ptr[i].setName(empName);
		cout << endl << endl;
		cout << "Please enter the name of the department: ";
		cin.getline(depName, size2);
		ptr[i].setDeptName(depName);
	}
	for (int i = 0; i < arrSize; i++)
	{
		ptr[i].displayData();
		cout << endl;
	}

	delete[]ptr;

	system("pause");
	return 0;
}