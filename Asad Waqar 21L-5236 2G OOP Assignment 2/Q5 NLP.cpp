#include<iostream>
#include"NLP.h"
using namespace std;

NLP::NLP()
{
	iString = NULL;
	arrSize = 0;
	spaceCounter = 0;
	uniArr = NULL;
	wordlengthArray= NULL;
	wordCounter = 0;
}

NLP::NLP(int size)
{
	arrSize = size;
	iString = new char[arrSize];
	spaceCounter = 0;
	uniArr = NULL;
	wordlengthArray = NULL;
	wordCounter = 0;
}

NLP::NLP(int size, char* sPtr)
{
	spaceCounter = 0;
	arrSize = size;
	iString = new char[arrSize];
	for (int i = 0; i < arrSize; i++)
	{
		*(iString + i) = *(sPtr + i);
	}
	uniArr = NULL;
	wordlengthArray = NULL;
	wordCounter = 0;
}

void NLP::setSize(int size)
{
	arrSize = size;
}

void NLP::setPtr(int size, char* sPtr)
{
	arrSize = size;
	iString = new char[arrSize];
	for (int i = 0; i < arrSize; i++)
	{
		*(iString + i) = *(sPtr + i);
	}
}

int NLP::getSize()
{
	return arrSize;
}

char* NLP::getPtr()
{
	return iString;
}

NLP::~NLP()
{
	delete[]iString;
	int wNum = 0;
	wNum = wordCount();
	for (int i = 0; i <wNum; i++)
	{
		delete[]uniArr[i];
	}
	delete uniArr;
	delete[] wordlengthArray;
}

int NLP::strLength()
{
	int count = 0;
	while (*(iString+count)!='\0')
	{
		count++;
	}
	return count;
}

int NLP::wordCount()
{
	int wCounter = 1;
	int count = 0;
	while (*(iString+count)!='\0')
	{
		if (count==0)
		{
			count++;
			continue;
		}
		else
		{
			if ((* (iString + count) >= 'A' && *(iString + count) <= 'Z')|| (*(iString + count) >= 'a' && *(iString + count) <= 'z'))
			{
				count++;
				continue;
			}
			else if (*(iString + count)=' ')
			{
				spaceCounter++;
				if ((*(iString + count-1) >= 'A' && *(iString + count - 1) <= 'Z') || (*(iString + count - 1) >= 'a' && *(iString + count - 1) <= 'z'))
				{
					if ((*(iString + count + 1) >= 'A' && *(iString + count + 1) <= 'Z') || (*(iString + count + 1) >= 'a' && *(iString + count + 1) <= 'z'))
					{
						wCounter++;
					}
				}
				count++;
				continue;
			}
			else
			{
			
			}
		}
		count++;
	}
	/*cout << spaceCounter<<endl;*/
	this->wordCounter = wordCounter;
	return wCounter;
}

int NLP::unique(int wNum)
{
	wordlengthArray = new int[wNum];
	for (int i = 0; i < wNum; i++)
	{
		*(wordlengthArray + i) = 0;			//Initialize
	}
	int i = 0;
	int uWCounter = 0;
	int firstcount = 0;
	int lastcount = 0;
	int count = 0;
	int finalcount = 0;
	while (*(iString+count)!='\0')
	{
		if (count==0)
		{
			count++;
			lastcount = count;
			continue;
		}
		else
		{
			if ((* (iString + count) >= 'A' && *(iString + count) <= 'Z')|| (*(iString + count) >= 'a' && *(iString + count) <= 'z'))
			{
				count++;
				lastcount = count;
				continue;
			}
			else if (*(iString + count)=' ')
			{
				count++;
				lastcount = count;
				finalcount = lastcount - firstcount;
				*(wordlengthArray + i) = finalcount;
				i++;
				finalcount = 0;
				firstcount = lastcount;
				continue;
			}
			else
			{
				continue;
			}
		}
	}
	
	uniArr = new char* [wNum];
	for (int j = 0; j < wNum; j++)
	{
		uniArr[j] = new char[*(wordlengthArray + j)];
	}

	count = 0;
	for (int j = 0; j < wNum; j++)
	{
		for (int k = 0; k < *(wordlengthArray + j); k++)
		{
			uniArr[j][k] = *(iString + count);
			if (uniArr[j][k]==' ')
			{
				uniArr[j][k] = '\0';
			}
			count++;
		}
	}

	bool notSame = true;
	bool isUnique = false;
	int NullCounter = 0;
	for (int j = 0; j < wNum; j++)
	{
		for (int k = j; k < wNum; k++)
		{
			if (k==j)
			{
				
			}
			else
			{
				if (*(wordlengthArray+j)!= *(wordlengthArray + k))			//Comparing length
				{
					isUnique = true;
				}
				else
				{
					for (int loop = 0; loop < *(wordlengthArray + j); loop++)
					{
						if (uniArr[j][loop]!= uniArr[k][loop])
						{
							isUnique = true;
							break;
						}

					}

					if (isUnique==false)
					{
						notSame = false;
						uniArr[j] = NULL;
						NullCounter += 1;
						break;
					}
					isUnique = false;
				}

			}
		}
		notSame = true;
		isUnique = false;
	}

	uWCounter = wNum - NullCounter;

	cout << "Unigram of string is: " << endl;
	for (int i = 0; i < wNum; i++)
	{
		for (int j = 0; j < *(wordlengthArray + i); j++)
		{
			if (uniArr[i]!=NULL)
			{
				cout << uniArr[i][j];
			}
			
		}
		cout << ' ';
	}
	cout << endl;
	return uWCounter;
}

void NLP::unigram()
{
	for (int i = 0; i < this->wordCounter; i++)
	{
		for (int j = 0; j < *(wordlengthArray+i); j++)
		{
			
			if (uniArr[i][j]=='\0')
			{
				break;
			}
			else
			{
				cout << uniArr[i][j];
			}
		}
		cout << endl;
	}
}
