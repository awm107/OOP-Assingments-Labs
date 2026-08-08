#include<iostream>
using namespace std;
int FindSecondLargest(int* aPtr, int size)
{
	int max = 0;
	int j = 0;
	max = *(aPtr + j);
	for ( j = 0; j < size; ++j)
	{
		if (*(aPtr+j)>max)
		{
			max = *(aPtr + j);
		}
	}
	int secondLarge = 0;
	for ( j = 0; j < size; j++)
	{
		if (*(aPtr + j)!=max)
		{
			if ((* (aPtr + j)>secondLarge)&& (*(aPtr + j) < max))
			{
				secondLarge = *(aPtr + j);
			}
		}
	}
	return secondLarge;
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
	int secondMax = 0;
	secondMax = FindSecondLargest(arrPtr, arrSize);
	cout << secondMax << endl;
	delete[]arrPtr;

	system("pause");
	return 0;
}