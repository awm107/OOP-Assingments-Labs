#pragma once
class Publications
{
private:
	char title[50];
	float price;
public:
	Publications();
	void getData(char, float, int);
	void putData();
};
class Book: public Publications
{
private:
	int pageCount;
public:
	void getData(int);
	void putData();
};
class Tapes : public Publications
{
private:
	float playtime;
public:
	void getData(float);
	void putData();
};