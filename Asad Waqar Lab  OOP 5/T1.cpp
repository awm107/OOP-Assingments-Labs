#include<iostream>
#include<fstream>
using namespace std;

class Helper
{
public:
	static int StringLength(char* str)
	{
		int len;
		for (len = 0; str[len] != '\0'; len++)
		{

		}
		return len;

	}
	static void StringCopy(char*& dest, char*& src) {
		int len = StringLength(src);
		int i = 0;
		for (i = 0; i < len; i++)
		{
			dest[i] = src[i];
		}
		dest[i] = '\0';
	}
	static char* GetStringFromBuffer(char* str)
	{
		int len = StringLength(str);
		char* temp = new char[len + 1];
		StringCopy(temp, str);
		return temp;
	}
};



class Car
{
private:
	static int totalCars;	// initialize it to zero yourself
	int model;
	char* make;
	char* name;
	char* color;
public:
	Car()
	{
		model = 0;
		color = make = name = 0;
		totalCars++;
	}
	//Write Getter of totalCars yourself


	static int GetTotalCars() 
	{
		return totalCars;
	}
	void ReadDataFromFile(ifstream& fin)
	{
		char temp[20];

		fin >> model;

		fin >> temp;								//inputting(extracting) from  cardata.txt file
		make = Helper::GetStringFromBuffer(temp);

		fin >> temp;
		name = Helper::GetStringFromBuffer(temp);

		fin >> temp;
		color = Helper::GetStringFromBuffer(temp);
	}
	void PrintListView()
	{
		cout << model << "\t " << make << "\t " << name << " \t" << color << endl;
	}
	void PrintDetailView()
	{
		cout << "model " << "\t " << model << endl;
		cout << "make " << "\t " << make << endl;
		cout << "name " << "\t " << name << endl;
		cout << "color " << "\t " << color << endl;
		//Write yourself
	}
	~Car()
	{
		cout << "Destroying ";
		PrintListView();
		totalCars--;
		delete[] make;
		delete[] name;
		delete[] color;

		//Deallocate memory yourself
	}
	void Input()
	{
		char tempArr[50];
		cout << "Enter new car info: " << endl;
		cout << "enter car model: ";
		cin >> model;
		cout << "enter make: ";
		cin >> tempArr;
		make = Helper::GetStringFromBuffer(tempArr);
		cout << "enter car name: ";
		cin >> tempArr;
		name = Helper::GetStringFromBuffer(tempArr);
		cout << "enter color of the car: ";
		cin >> tempArr;
		color = Helper::GetStringFromBuffer(tempArr);
	}

};

Car* ReadDataFromFile(char* fileName)
{
	ifstream fin(fileName);
	int totalCars = 0;
	if (fin.is_open())
	{
		fin >> totalCars;
		Car* carsList = new Car[totalCars];
		int i = 0;
		while (!fin.eof())
		{

			carsList[i].ReadDataFromFile(fin);
			i++;
		}
		return carsList;
	}
	else
	{
		return 0;
	}
}
int Car::totalCars = 0;
int main()
{
	char filename[20] = "CarsData.txt";
	char* Name = Helper::GetStringFromBuffer(filename);
	Car* carsList = ReadDataFromFile(Name);
	int count = 0;
	if (carsList != 0)
	{

		count = Car::GetTotalCars();	//Calling static function
		cout << "Total Number of Cars in System:\t" << count << endl;

		//Test one Print at a time.
		cout << "\nCars List:\n\n";
		{
			for (int i = 0; i < count; i++)
			{
				carsList[i].PrintListView();
			}
		}
		/*Comment above printing and Test Printing 2*/
		cout << "\nCars List:\n\n";
		{
			Car temp = carsList[0];
			temp.PrintListView();

			for (int i = 1; i < count; i++)
			{
				temp = carsList[i];
				temp.PrintListView();
			}
		}
		if (carsList)
			delete[] carsList;
	}


	cout << "Total Number of Cars in System:\t" << Car::GetTotalCars() << endl << endl << endl;

	Car testCar;
	testCar.Input(); // Take car data from user
	testCar.PrintDetailView();

	cout << "Total Number of Cars in System:\t" << testCar.GetTotalCars() << endl << endl << endl;
	system("pause");
	return 0;
}
