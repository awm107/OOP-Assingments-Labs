#include"time.h"
#include<iostream>
using namespace std;

Time::Time()
{
	hours = minutes = seconds = 0;

}

Time::Time(int hrs, int mins, int secs)
{
	if (0 <= hrs && hrs < 24)
		hours = hrs;
	else
		hours = 0;
	if (0 <= mins && mins < 60)
		minutes = mins;
	else
		minutes = 0;
	if (0 <= secs && secs < 60)
		seconds = secs;
	else
		seconds = 0;
}

void Time::displayTime()
{
	if (hours < 10)
	{
		cout << "0";
	}
	cout << hours << ":";
	if (minutes < 10)
	{
		cout << "0";
	}
	cout << minutes << ":";
	if (seconds < 10)
		cout << "0";
	cout << seconds;
	cout << endl;
}

void Time::operator++()
{
	seconds++; 
	if (seconds > 59)
	{
		seconds = 0; 
		minutes++; 
		if (minutes > 59) 
		{
			minutes = 0;
			hours++; 
			if (hours > 23)
			{
				hours = 0; 
			}
		}
	}
}

void Time::operator++(int)
{
	seconds++;
	if (seconds > 59)
	{
		seconds = 0;
		minutes++;
		if (minutes > 59)
		{
			minutes = 0;
			hours++;
			if (hours > 23)
			{
				hours = 0;
			}
		}
	}
}

void Time::operator--()
{
	seconds--;
	if (seconds < 0)
	{
		seconds = 59;
		minutes--;
		if (minutes < 0)
		{
			minutes = 59;
			hours--;
			if (hours < 0)
			{
				hours = 23;
			}
		}
	}
}

void Time::operator--(int)
{
	seconds--;
	if (seconds < 0)
	{
		seconds = 59;
		minutes--;
		if (minutes < 0)
		{
			minutes = 59;
			hours--;
			if (hours < 0)
			{
				hours = 23;
			}
		}
	}
}

Time operator-(Time& obj1, Time& obj2)
{
	Time temp;
	if (obj1.hours<obj2.hours)
	{
		cout << "Cannot subtract these times since time can never be in minus.";
		exit(0);
	}
	else
	{
		if (obj1.seconds >= obj2.seconds)
		{
			temp.seconds = obj1.seconds - obj2.seconds;
		}
		else
		{
			obj1.minutes--;
			obj1.seconds += 60;
			temp.seconds = obj1.seconds - obj2.seconds;
		}
		if (obj1.minutes >= obj2.minutes)
		{
			temp.minutes = obj1.minutes - obj2.minutes;
		}
		else
		{
			obj1.hours--;
			obj1.minutes += 60;
			temp.minutes = obj1.minutes - obj2.minutes;
		}
		if (obj1.hours<obj2.hours)
		{
			cout << "Sorry, time is getting in negative.";
			exit(0);
		}
		else
		{
			temp.hours= obj1.hours - obj2.hours;
		}
	}
	return temp;
}
