//[1] Create a class called time that has separate int member data for hours, minutes, and seconds.One constructor
//should initialize this data to 0, and another should initialize it to fixed values.Another member function should
//display it, in 11 :59 : 59 format.
// 
//[2] Modify the class time that you have created in Q # 1 to include overloaded increment(++) and decrement(--
//) operators that operate in both prefix and postfix notation and return values.Add statements to main() to test
//these operators.
// 
//[3] Add to the time class of Q # 1 the ability to subtract two time values using the overloaded(-) operator,and to
//multiply a time value by a number of type float, using the overloaded(*) operator.

#include"time.h"
#include<iostream>
using namespace std;

int main()
{
	Time t1;
	Time t2(5,32,52);

	t1++;
	t1.displayTime();
	system("pause");
	return 0;
}
