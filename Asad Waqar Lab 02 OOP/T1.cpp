#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int ArraySize = 5;
	int* ptr = new int[ArraySize];;
	int* newPtr;
	bool proceed = true;
	int previousArrSize = 0;
	int ArrayfillCounter = 0;
	int rogueValue = -1;
	int i = 0;

	for (i = 0; (i <= ArraySize); i++)
	{
		if (i < ArraySize)
		{
			cout << "Please enter Array " << i << " :";
			cin >> *(ptr + i);
			if (*(ptr + i) == -1)
			{
				break;
			}
		}
		else 
	{

		while (proceed == true)
		{
			ArrayfillCounter += 1;
			previousArrSize = ArraySize;
			int* tempPtr = new int[previousArrSize];
			if (ArrayfillCounter == 1)
			{
				for (int j = 0; j < previousArrSize; j++)
				{
					*(tempPtr + j) = *(ptr + j);
				}
				delete[]ptr;
			}
			else
			{
				ArraySize = 5 * (pow(2, (ArraySize / 5)));
				newPtr = new int[ArraySize];
				for (int k = 0; k < ArraySize; k++)
				{
					if (k < previousArrSize)
					{
						*(newPtr + k) = *(tempPtr + k);
					}
					else
					{
						if (k == previousArrSize)
						{
							delete[]tempPtr;
						}
						cout << "Please enter Array " << i << " :";
						cin >> *(newPtr + k);
						i = k + 1;
						if (*(newPtr + k) == -1)
						{
							proceed = false;
							break;
						}

					}
				}
				continue;
			}
		}
	}
	}

	cout << i << endl;

	system("pause");
	return 0;
}
