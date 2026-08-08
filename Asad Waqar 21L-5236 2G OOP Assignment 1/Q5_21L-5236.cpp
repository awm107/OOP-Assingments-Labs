#include<iostream>
using namespace std;
int* shrinkArray(int* aPtr, int& size)
{
	cout << "Please enter array elements: " << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> *(aPtr + i);
	}
	int shrinkSize = 0;
	cout << "Enter the size that you want to decrease that should not be more than " << size << " : ";
	cin >> shrinkSize;
	size = size - shrinkSize;
	int* newAPtr = new int[size];
	for (int i = 0; i < size; i++)
	{
		*(newAPtr + i) = *(aPtr + i);
	}
	return newAPtr;
}
int main()
{
	int ArrSize = 10;
	int* arrPtr = new int[ArrSize];
	int* newArrPtr = shrinkArray(arrPtr, ArrSize);
	for (int i = 0; i < ArrSize; i++)
	{
		cout << *(newArrPtr + i) << endl;;
	}
	delete[]arrPtr;
	system("pause");
	return 0;
}