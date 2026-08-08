#include<iostream>
using namespace std;
class DB;
class DM;

class DM
{
private:
	int m, cm;


public:
	DM()
	{
		m = 0;
		cm = 0;

	}
	DM(int m, int cm)
	{
		this->m = m;
		this->cm = cm;

	}
	friend DM add(DM d1, DB d2);
};

class DB
{
private:
	int ft, inch;


public:
	DB()
	{
		ft = 0;
		inch = 0;

	}
	DB(int m, int cm)
	{
		this->ft = m;
		this->inch = cm;

	}
	friend DM add(DM d1, DB d2);

};

DM add(DM d1, DB d2)
{
	DM result;
	int M = 0, CM = 0;
	result.cm = ((d1.m * 100 + d1.cm) + ((d2.ft * 12) + d2.inch) * 2.54) / 100;
	result.m = result.cm % 100;

	cout << result.m << endl;
	cout << result.cm << endl;
	return result;
}

int main()
{
	int centi = 0, meter = 0;
	int feet = 0, inches = 0;
	cout << "Please enter meters: ";
	cin >> meter;
	cout << "Please enter centimeters: ";
	cin >> centi;
	cout << "Please enter feet: ";
	cin >> feet;
	cout << "Please enter inches: ";
	cin >> inches;

	DM dm1(meter, centi);
	DB db2(feet, inches);

	DM res = add(dm1, db2);
	system("pause");
	return 0;
}