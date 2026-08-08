#include<iostream>
using namespace std;
void printHistogram(int *aPtr, int size) 
{
	char symbol = '*';
	cout << endl << endl;
	cout << "Array A" << '\t' << '\t' << "Histogram(Output)" << endl << endl;
	for (int i = 0; i < size; i++)
	{
		cout << *(aPtr + i) << '\t' << '\t';
		for (int j = 0; j < *(aPtr + i) * 2; j++)
		{
			cout << symbol;
		}
		cout << "[" << *(aPtr + i) * 2 << "]";
		cout << endl << endl;
	}


}
int main()
{
	int size = 10;
	int* A = new int[size];
	for (int i = 0; i < size; i++)
	{
		cout << "Enter array A[ " << i << " ]: ";
		cin >> *(A + i);
	}
	printHistogram(A, size);
	cout << endl;

	delete[]A;
	system("pause");
	return 0;

}