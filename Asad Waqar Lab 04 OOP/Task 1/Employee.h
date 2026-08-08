#pragma once
using namespace std;
const int size1 = 31;
const int size2 = 41;
class Employee
{
private:
	int ID;
	char *Name=new char[size1];
	char *DeptName=new char[size2];

public:
	Employee();
	Employee(int empID, char *empName, char *depName);
	Employee(int empID, char *empName);
	void setID(int empID);
	int getID();
	void setName(char *empName);
	char* getName();
	void setDeptName(char *depName);
	char* getDeptName();
	void displayData();
	~Employee();

};