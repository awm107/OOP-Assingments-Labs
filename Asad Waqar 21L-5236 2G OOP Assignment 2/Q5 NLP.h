#pragma once

class NLP
{
private:
	char* iString;
	int arrSize;
	int spaceCounter;
	int wordCounter;
	char** uniArr;
	int* wordlengthArray;
public:
	NLP();
	NLP(int size);
	NLP(int size, char* sPtr);
	void setSize(int size);
	void setPtr(int size, char* sPtr);
	int getSize();
	char* getPtr();
	~NLP();
	int strLength();
	int wordCount();
	int unique(int wNum);
	void unigram();
};
