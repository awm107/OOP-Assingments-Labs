#pragma once
class Time
{
	friend Time operator-(Time&, Time&);
private:
	int hours, minutes, seconds;
public:
	Time();									//Q1
	Time(int hrs, int mins, int secs);
	void displayTime();
	void operator++();
	void operator++(int);
	void operator--();
	void operator--(int);
};