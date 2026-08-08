#include<iostream>;
using namespace std;
class Ship
{
private:
	char * shipName;
	int date;

public:
	Ship()
	{
		shipName = NULL;
		date = 0;
	}
	Ship(char* sName, int Date)
	{
		int count = 0;
		for (int i = 0; sName[i]!= '\0'; i++)
		{
			count++;
		}
		shipName = new char[count];
		for (int i = 0; i < count; i++)
		{
			shipName[i] = sName[i];
		}
	}
	void setShipName(char* sName)
	{
		int count = 0;
		for (int i = 0; sName[i] != '\0'; i++)
		{
			count++;
		}
		shipName = new char[count];
		for (int i = 0; i < count; i++)
		{
			shipName[i] = sName[i];
		}
	}
	void setDate(int Date)
	{
		date = Date;
	}
	char * getShipName()
	{
		return shipName;
	}
	int getDate()
	{
		return date;
	}
	virtual void print()
	{

		cout << "The ship name is: ";
		for (int i = 0; shipName[i]!='\0'; i++)
		{
			cout << shipName[i];
		}
		cout << endl;
		cout << "The date of manufacture of ship is: " << date << endl;
	}
};

class CruiseShip:public Ship
{
private:
	int passengerNo;

public:
	CruiseShip()
	{
		passengerNo = 0;
		Ship::Ship();

	}
	CruiseShip(int n)
	{
		passengerNo = n;
	}
	CruiseShip(char* name, int p)
	{
		Ship::setShipName(name);
		passengerNo = p;
	}
	char* getName()
	{
		 Ship::getShipName();
	}
	int getPassenger()
	{
		return passengerNo;
	}
	void print()
	{
		Ship::print();
		cout << endl;
		cout << "passenger number is: " << passengerNo << endl;
	}


};

class CargoShip:public Ship
{
private:
	int capacity;
public:
	CargoShip()
	{
		capacity = 0;
	}
	CargoShip(int c)
	{
		capacity = c;
	}
	CargoShip(char*name, int cap)
	{
		Ship::setShipName(name);
		capacity = cap;
	}
	char* getName()
	{
		Ship::getShipName();
	}
	int getCargoCap()
	{
		return capacity;
	}
	void print()
	{
		Ship::print();
		cout << endl;
		cout << "Capacity of cargo ship is: " << capacity << endl;
		
	}
	
};

void PrintAll(Ship* obj)
{
	obj->print();
}

int main()
{

	Ship**s = new Ship*[3];
	char*NAME = new char[100];
	cout << "please enter Ship name: " << endl;
	cin.getline(NAME, 100);

	int dt = 0, carg = 0, cPass = 0;
	cout << "please enter the date of ship made: " << endl;
	cin >> dt;
	s[0] = new Ship(NAME, dt);
	cout << "please enter the passenger number of ship made: " << endl;
	cin >> cPass;
	cout << "please enter Cruise Ship name: " << endl;
	cin.ignore;
	cin.getline(NAME, 100);
	
	s[1] = new CruiseShip(NAME, cPass);
	cout << "please enter the cargo capacity of ship made: " << endl;
	cin >> carg;
	cout << "please enter Cargo Ship name: " << endl;
	cin.ignore;
	cin.getline(NAME, 100);
	
	s[2] = new CargoShip(NAME, carg);

	for (int i = 0; i < 3; i++)
	{
		PrintAll(s[i]);
	}


	system("pause");
	return 0;

}