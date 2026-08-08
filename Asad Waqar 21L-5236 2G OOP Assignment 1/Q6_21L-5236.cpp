#include<iostream>
using namespace std;
int* growArray(int* aPtr, int& size)
{
	cout << "Please enter array elements: " << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> *(aPtr + i);
	}
	int growSize = 0;
	cout << "Enter the size that you want to increase: ";
	cin >> growSize;
	int prevSize = size;
	size = size + growSize;
	int* newAPtr = new int[size];
	for (int i = 0; i < size; i++)
	{
		if (i<prevSize)
		{
			*(newAPtr + i) = *(aPtr + i);
		}
		else
		{
			cout << "Enter a new value in array " << i << " : ";
			cin >> *(newAPtr + i);
		}
	}
	return newAPtr;
}
int main()
{
	int ArrSize = 10;
	int* arrPtr = new int[ArrSize];
	int* newArrPtr = growArray(arrPtr, ArrSize);
	for (int i = 0; i < ArrSize; i++)
	{
		cout << *(newArrPtr + i) << endl;;
	}
	delete[]arrPtr;
	system("pause");
	return 0;
}