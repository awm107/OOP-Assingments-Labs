#include <iostream>
using namespace std;

class Point {
private:
	int x;
	int y;
public:
	Point()
	{
		x = y = 0;
	}
	Point(int x, int y) 
	{
	this->x = x;
	this->y = y;

	}
	void print() 
	{
		cout << "x: " << x << endl;
		cout << "y: " << y << endl;
	}
	void operator++()    // for ++obj
	{
		x++;
		y++;
	}
	void operator++(int)   //for obj++
	{
		x++;
		y++;
	}
	void operator--()    // for --obj
	{
		x--;
		y--;
	}
	void operator--(int)   //for obj++
	{
		x--;
		y--;
	}
	void operator-()   //for -
	{
		x=-x;
		y=-y;
	}
	
};

int main()
{
	Point obj(5, 6);
	obj.print();
	obj++;
	obj.print();
	Point obj2(5, 6);
	obj2.print();
	obj2--;
	obj2.print();
	Point obj3(5, 6);
	obj3.print();
	-obj3;
	obj3.print();
	return 0;
}