#pragma once
class Student
{
private:
	char* StudentName;
	long long CNIC;
	char* Degree;
	int RollNumber;
	char* Address;
public:
	Student();
	Student(char* , long long, char*, int, char*);
	void setName(char*);
	void setCNIC(long long);
	void setDegree(char*);
	void setRollnum(int);
	void setAddress(char*);
	char* getName();
	long long getCNIC();
	char* getDegree();
	int getRollNum();
	char* getAddress();
	void InputData();
	void printData();
	~Student();

};