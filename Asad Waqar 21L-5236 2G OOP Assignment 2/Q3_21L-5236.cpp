#include<iostream>
using namespace std;
void RightCircularlyShift(int* const x, int* const y, int* const z)
{
	int temp = 0;
	temp = *x;
	*x = *z;
	*z = *y;
	*y = temp;
}
int main()
{
	int x = 0, y = 0, z = 0;
	cout << "Enter a value for x: ";
	cin >> x;
	cout << "Enter a value for y: ";
	cin >> y;
	cout << "Enter a value for z: ";
	cin >> z;

	int* xPtr, * yPtr, * zPtr;
	xPtr = &x;
	yPtr = &y;
	zPtr = &z;

	RightCircularlyShift(xPtr, yPtr, zPtr);
	cout << "x= " << *xPtr << endl;
	cout << "y= " << *yPtr << endl;
	cout << "z= " << *zPtr << endl;
	system("pause");
	return 0;
}