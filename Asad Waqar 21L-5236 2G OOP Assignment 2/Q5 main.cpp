#include<iostream>
#include"NLP.h"
using namespace std;
int main()
{
	NLP n1;
	char* inputString1;
	int Size = 1000;
	inputString1 = new char[Size];
	cout << "Please enter some sentences: " << endl;
	cin.getline(inputString1, Size);
	n1.setPtr(Size, inputString1);
	cout << n1.strLength() << endl;
	int wordNum = n1.wordCount();
	cout << wordNum << endl;

	int UniqueWord = 0;
	UniqueWord = n1.unique(wordNum);
	cout << "Total unique words are: " << UniqueWord << endl;

	/*n1.unigram();*/
	delete[]inputString1;
	system("pause");
	return 0;
}