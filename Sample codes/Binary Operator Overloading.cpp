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
	Point operator+(const Point& rhs)     // for addition
	{
		Point lhs;
		lhs.x = x + rhs.x;
		lhs.y = y + rhs.y;
		return lhs;
	}
	
	Point operator-(const Point& rhs)    //for subtraction
	{
		Point lhs;
		lhs.x = x - rhs.x;
		lhs.y = y - rhs.y;
	    return lhs;
	}
	Point operator*(const Point& rhs)   //for multiplication
	{
		Point lhs;
		lhs.x = x * rhs.x;
		lhs.y = y * rhs.y;
		return lhs;
	}
	Point operator/(const Point& rhs)  //for division
	{
		Point lhs;
		lhs.x = x / rhs.x;
		lhs.y = y / rhs.y;
		return lhs;
	}

};

int main()
{
	Point obj(1, 1), obj2(2,3);
	Point obj3 = obj + obj2;
	obj3.print();
	obj3 = obj - obj2;
	obj3.print();
	obj3 = obj * obj2;
	obj3.print();
	obj3 = obj / obj2;
	obj3.print();
	
	
	return 0;
}