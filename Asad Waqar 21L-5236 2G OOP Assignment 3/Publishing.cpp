#include"Publishing.h"
#include<iostream>
using namespace std;
Publications::Publications()
{
	for (int i = 0; i < 50; i++)
	{
		title[i] = '\0';
	}
	price = 0.0;
}

void Publications::getData(char Title, float cost, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (Title[i]=='\0')
		{
			break;
		}
		else
		{
			title[i] = Title[i];
		}

	}
	price = cost;
}

void Publications::putData()
{
	int i = 0;
	for ( i = 0; title[i]!='\0'; i++)
	{
		cout << title[i];
	}
	cout << endl;
	cout << price << endl;
}

void Book::getData(int pages)
{
	pageCount = pages;
}

void Book::putData()
{
	cout << pageCount << endl;
}

void Tapes::getData(float time)
{
	playtime = time;
}

void Tapes::putData()
{
	cout << playtime;
}
