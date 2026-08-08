#include<iostream>
using namespace std;
int main()
{
	long value1 = 200000;
	long value2 = 0;
	long* longPtr;
	longPtr = &value1;
	cout << *longPtr << endl;
	value2 = *longPtr;
	cout << value2<<endl;
	cout << &value1<<endl;
	cout << longPtr << endl;

	system("pause");
	return 0;
}