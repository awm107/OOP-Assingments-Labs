#include<iostream>
using namespace std;
void minRow_wise(int** Arr, int* smallestAPtr, int row, int col)
{
	int rowSmallest = 0;
	int j = 0, k = 0;

		for (j = 0; j < row; j++)
		{
			for (k = 0; k < col; k++)
			{
				if (k==0)
				{
					rowSmallest = Arr[j][k];
				}
				else if (rowSmallest>Arr[j][k])
				{
					rowSmallest = Arr[j][k];
				}
			}
			*(smallestAPtr + j) = rowSmallest;
			
		}
}
int main()
{
	int row = 5, col = 5;
	int** arr;
	arr = new int* [row];				//1D Array of Pointers//
	for (int i = 0; i < row; i++)
	{
		arr[i] = new int[col];
	}
	cout << "Please enter array elements: " << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> arr[i][j];
		}
	}

	int* smallestArrayPtr = new int[row];
	minRow_wise(arr, smallestArrayPtr, row, col);
	cout << "Smallest array row wize are: " << endl;
	for (int i = 0; i < row; i++)
	{
		cout << *(smallestArrayPtr + i) << endl;
	}
	delete[]smallestArrayPtr;

	for (int i = 0; i < row; i++)
	{
		delete[]arr[i];
	}

	system("pause");
	return 0;

}