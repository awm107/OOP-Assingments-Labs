#include<iostream>
using namespace std;
int* InputArray(int &size)
{
	cout << "Please enter array size: ";
	cin >> size;
	int* ptrArr = new int[size];
	for (int i = 0; i < size; i++)
	{
		cout << "please fill array in " << i << " : ";
		cin >> *(ptrArr + i);
	}
	/*delete[]ptrArr;*/
	return ptrArr;
}
void OutputArray(int* myArray, const int& size)
{
	for (int i = 0; i < size; i++)
	{
		cout << *(myArray + i)<<" ";
	}
	/*delete[]myArray;*/
}
int* CompressArray(int* originalArr, int& size)
{
	int temp = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size-1; j++)
		{
			if ((* (originalArr + j))> *(originalArr + (j+1)))
			{
				temp = (*(originalArr + j));
				(*(originalArr + j)) = *(originalArr + (j + 1));
				*(originalArr + (j + 1)) = temp;
			}
		}
	}
	OutputArray(originalArr, size);
	int repetition = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; (j < size); j++)
		{
			if (*(originalArr+i)== *(originalArr + j) && (i != j))
			{
				repetition +=1;
			}

		}
		if (repetition>0)
		{
			for (int k = i + repetition; k < size; ++k)
			{
				*(originalArr + (k - repetition)) = *(originalArr + k);
			}
			size = size - repetition;
			repetition = 0;
		}
		
	}
	
	int* newArrPtr = new int[size];
	for (int i = 0; i < size; i++)
	{
		*(newArrPtr + i) = *(originalArr + i);
	}
	delete[]originalArr;
	/*delete[]newArrPtr;*/
	return newArrPtr;
}
int* Intersection(int* setA, int& size1, int* setB, int& size2, int& size3)
{
	bool isCommon = false;
	int arrSize = 0;
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			if (*(setA+i)==*(setB+j))
			{
				arrSize += 1;
			}
		}
	}

	size3 = arrSize;
	int* setC = new int[size3];
	int k = 0, temp = 0;
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			if (*(setA + i) == *(setB + j))
			{
				isCommon = true;
			}
		}
		if (isCommon==true)
		{
			*(setC + k) = *(setA + i);
			k++;
		}
		isCommon = false;
	}
	/*delete[]setC;*/
	return setC;
}
int main()
{
	int Size1 = 100;
	int* p1;
	p1=InputArray(Size1);
	cout << p1 << endl;
	OutputArray(p1, Size1);
	cout << endl;
	p1=CompressArray(p1, Size1);
	cout << endl;
	cout << "Array after compression: ";
	OutputArray(p1, Size1);

	cout << endl;
	int Size2 = 100;
	int* p2;
	p2 = InputArray(Size2);
	cout << p2 << endl;
	OutputArray(p2, Size2);
	cout << endl;
	p2 = CompressArray(p2, Size2);
	cout << endl;
	cout << "Array after compression: ";
	OutputArray(p2, Size2);

	
	int Size3 = 0;
	Size3 = Size1 + Size2;
	int* p3;
	p3=Intersection(p1, Size1, p2, Size2, Size3);
	cout << endl;
	cout << "A Instersect B= ";
	OutputArray(p3, Size3);

	system("pause");
	return 0;
}