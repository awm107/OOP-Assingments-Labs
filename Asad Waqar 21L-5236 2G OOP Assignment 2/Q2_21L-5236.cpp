#include<iostream>
using namespace std;
void SortVowelArray(int vowel[])
{
	int temp = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (vowel[j + 1] >= vowel[j])
			{
				temp = vowel[j + 1];
				vowel[j + 1] = vowel[j];
				vowel[j] = temp;
			}
		}
	}
}
int main()
{
	int stringSize = 201;
	char* str = new char[stringSize];
	int totalConsonants = 0;
	int totalVowels = 0;
	int Acounter = 0, Ecounter = 0, Icounter = 0, Ocounter = 0, Ucounter = 0 ;
	cout << "Enter String: ";
	cin.getline(str, stringSize);
	int count = 0;
	/*while (*(str+count)!='\0')
	{
		cout << *(str + count);
		count++;
	}*/

	while ((*(str + count) != '\0'))
	{
		if ((((*(str + count)) >= 'A') && ((*(str + count)) <= 'Z')) || (((*(str + count)) >= 'a') && ((*(str + count)) <= 'z')))
		{
			if (*(str + count) == 'a' || *(str + count) == 'A')
			{
				Acounter++;
			}
			else if (*(str + count) == 'e' || *(str + count) == 'E')
			{
				Ecounter++;
			}
			else if (*(str + count) == 'i' || *(str + count) == 'I')
			{
				Icounter++;
			}
			else if (*(str + count) == 'o' || *(str + count) == 'O')
			{
				Ocounter++;
			}
			else if (*(str + count) == 'u' || *(str + count) == 'U')
			{
				Ucounter++;
			}
			else
			{
				totalConsonants++;
			}
		}
		count++;
	}
	cout << endl;
	cout << "Total Consonats: " << totalConsonants << endl;
	totalVowels = Acounter + Ecounter + Icounter + Ocounter + Ucounter;
	cout << "Total Vowels: " << totalVowels << endl;
	int vowelCounterArray[5] = { Acounter,Ecounter,Icounter,Ocounter,Ucounter };
	SortVowelArray(vowelCounterArray);
	for (int i = 0; i < 5; i++)
	{
		if (vowelCounterArray[i]==Acounter)
		{
			cout << "Total a: " << Acounter << endl;
		}
		else if (vowelCounterArray[i] == Ecounter)
		{
			cout << "Total e: " << Ecounter << endl;
		}
		else if (vowelCounterArray[i] == Icounter)
		{
			cout << "Total i: " << Icounter << endl;
		}
		else if (vowelCounterArray[i] == Ocounter)
		{
			cout << "Total o: " << Ocounter << endl;
		}
		else if (vowelCounterArray[i] == Ucounter)
		{
			cout << "Total u: " << Ucounter << endl;
		}
	}
	
	delete[]str;
	system("pause");
	return 0;
}