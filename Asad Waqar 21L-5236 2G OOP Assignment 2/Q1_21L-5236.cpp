#include<iostream>
using namespace std;
void RemoveRepitition(char* a, int& size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if ((*(a + i) == *(a + j)) && (i != j))
			{
				for (int count = j; count < size-1; count++)
				{
					*(a + count) = *(a + (count + 1));
				}
				size = size - 1;
			}
		}
	}
}
char *Intersection(char* a, char* b, int sizeA, int sizeB, char *aNb,int &sizeaNb)
{
	int Size = 0;
	for (int i = 0; i < sizeA; i++)
	{
		for (int j = 0; j < sizeB; j++)
		{
			if (*(a + i) == *(b + j))
			{
				Size += 1;
			}
		}
	}
	sizeaNb = Size;
	aNb = new char[sizeaNb];
	int count = 0;
	bool isEqual = false;
	for (int i = 0; i < sizeA; i++)
	{
		for (int j = 0; j < sizeB; j++)
		{
			if (*(a + i) == *(b + j))
			{
				isEqual = true;
				break;
			}
		}
		if (isEqual==true)
		{
			*(aNb + count) = *(a + i);
			count += 1;
			isEqual = false;
		}
	}
	return aNb;
}
char* Union(char* a, char* b, int sizeA, int sizeB, char* aUb, int& sizeaUb)
{
	int Size = 0;
	Size = sizeA;
	int extra = 0;
	bool flag = true;
	for (int i = 0; i < sizeB; i++)
	{
		for (int j = 0; j < sizeA; j++)
		{
			if (*(b+i)==*(a+j))
			{
				flag = false;
				break;
			}
		}
		if (flag == true)
		{
			extra += 1;
		}
		flag = true;
	}
	Size = Size + extra;
	sizeaUb = Size;
	aUb = new char[sizeaUb];
	for (int i = 0; i < sizeA; i++)
	{
		*(aUb + i) = *(a + i);
	}
	int count = 0;
	for (int i = 0; i < sizeB; i++)
	{
		for (int j = 0; j < sizeA; j++)
		{
			if (*(b + i) == *(a + j))
			{
				flag = false;
				break;
			}
		}
		if (flag == true)
		{
			*(aUb + sizeA + count) = *(b + i);
			count++;
		}
		flag = true;
	}
	return aUb;
}
int main()
{
	int uCaseCount = 65, lCaseCount = 97, noOfLetters=26;
	char* U = NULL;
	U = new char[noOfLetters];
	for (int i = 0; i < noOfLetters; i++)
	{														//Filling U Array with all alphabets
		*(U + i) = char(lCaseCount + i);
	}
	cout << endl;
	/*for (int i = 0; i < noOfLetters; i++)
	{
		cout << *(U + i);
	}*/
	int sizeA = 0, sizeB = 0;
	cout << "Please enter number for size for Array A: ";
	cin >> sizeA;
	char* A = new char[sizeA];
	for (int i = 0; i < sizeA; i++)
	{
		cout << "Please enter an alphabet in A[ " << i << " ]: ";
		cin >> *(A + i);
	}
	RemoveRepitition(A, sizeA);
	/*for (int i = 0; i < sizeA; i++)
	{
		cout << *(A + i);
	}*/

	cout << "Please enter number for size for Array B: ";
	cin >> sizeB;
	char* B = new char[sizeB];
	for (int i = 0; i < sizeB; i++)
	{
		cout << "Please enter an alphabet in B[ " << i << " ]: ";
		cin >> *(B + i);
	}
	RemoveRepitition(B, sizeB);
	/*for (int i = 0; i < sizeB; i++)
	{
		cout << *(B + i);
	}*/
	char* AnB = NULL;
	int sizeAnB = 0;
	sizeAnB = sizeA + sizeB;
	AnB=Intersection(A, B, sizeA, sizeB, AnB, sizeAnB);
	cout << endl;
	cout << "A n B is: ";
	for (int i = 0; i < sizeAnB; i++)
	{
		cout << *(AnB + i);
	}
	cout << endl;

	char* AuB = NULL;
	int sizeAuB = 0;
	sizeAuB = sizeA + sizeB;
	AuB = Union(A, B, sizeA, sizeB, AuB, sizeAuB);
	cout << endl;
	cout << "A u B is: ";
	for (int i = 0; i < sizeAuB; i++)
	{
		cout << *(AuB + i);
	}
	cout << endl;

	bool isCommon = false;
	cout << "U-(AuB): ";
	for (int i = 0; i < noOfLetters; i++)
	{
		for (int j = 0; j < sizeAuB; j++)
		{
			if (*(U + i) == *(AuB + j))
			{
				isCommon = true;
				break;
			}		
		}
		if (isCommon==false)
		{
			cout << *(U + i) << " ";
		}
		isCommon = false;
	}
	cout << endl;
	cout << "A': ";
	for (int i = 0; i < noOfLetters; i++)
	{
		for (int j = 0; j < sizeA; j++)
		{
			if (*(U + i) == *(A + j))
			{
				isCommon = true;
				break;
			}
		}
		if (isCommon == false)
		{
			cout << *(U + i) << " ";
		}
		isCommon = false;
	}
	cout << endl;
	cout << "B': ";
	for (int i = 0; i < noOfLetters; i++)
	{
		for (int j = 0; j < sizeB; j++)
		{
			if (*(U + i) == *(B + j))
			{
				isCommon = true;
				break;
			}
		}
		if (isCommon == false)
		{
			cout << *(U + i) << " ";
		}
		isCommon = false;
	}
	cout << endl;
	delete AuB;
	delete AnB;
	delete[]A;
	delete[]B;
	delete []U;
	system("pause");
	return 0;

}