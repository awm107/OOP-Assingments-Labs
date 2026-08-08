#include <iostream>
using namespace std;

class Point {
private:
	int x;
public:
	Point()
	{
		x = 0;
	}
	void setX(int a)
	{
		x = a;
	}
	friend istream& operator >>(istream& input, Point& obj);
	friend ostream& operator <<(ostream& output, Point& obj);
};
istream& operator>> (istream& input, Point& obj)
{
	input >> obj.x;
	return input;
}
ostream& operator<< (ostream& output, Point& obj)
{
	output << obj.x << endl;
	return output;
}

int main()
{
	Point p;
	cin >> p;
	cout << p;


	return 0;
}