#include<iostream>
using namespace std;
void SortArray(int* aPtr, int size)
{
	int temp = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size-1; j++)
		{
			if (*(aPtr + j)> *(aPtr + j+1))
			{
				temp = *(aPtr + j);
				*(aPtr + j) = *(aPtr + j + 1);
				*(aPtr + j + 1) = temp;
			}
		}
	}
}
int main()
{
	int arrSize = 10;
	int* arrPtr = new int[arrSize];
	cout << "Please enter array elements: " << endl;
	for (int i = 0; i < arrSize; i++)
	{
		cin >> *(arrPtr + i);
	}
	SortArray(arrPtr, arrSize);
	for (int i = 0; i < arrSize; i++)
	{
		cout << *(arrPtr + i) << endl;
	}
	delete[]arrPtr;

	system("pause");
	return 0;
}