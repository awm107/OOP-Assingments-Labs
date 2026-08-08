#include <iostream>
using namespace std;

struct ComplexNum
{
	int real;
	int img;
};

class Calculator //Abstract classes
{
public:
	virtual void add() = 0;
	virtual void multiply() = 0;
	virtual void subtract() = 0;
	virtual void divide() = 0;
};

class SimpleNum : public Calculator
{
private:
	int a, b ;
public:
	SimpleNum()
	{
		a = 0;
		b = 0;
	}

	SimpleNum(int n1, int n2)
	{
		a = n1;
		b = n2;
	}

	void add()
	{
		cout << "Addition : " << a + b << endl;
	}
	void subtract()
	{
		cout << "Subtraction : " << a - b << endl;
	}
	void multiply()
	{
		cout << "Multiplication : " << a * b << endl;
	}
	void divide()
	{
		cout << "Division : " << a / b << endl;
	}
};

class ComplexNumber : public Calculator
{
private:
	ComplexNum a;
	ComplexNum b;

public:
	ComplexNumber(int n1, int n2, int n3, int n4)
	{
		a.real = n1;
		a.img = n2;
		b.real = n3;
		b.img = n4;
	}

	void add()
	{
		int x = 0, y = 0;
		x = a.real + b.real;
		y = a.img + b.img;
		cout << "Addition : " << x << " + " << y << "i " << endl;
	}

	void subtract()
	{
		int x = 0, y = 0;
		x = a.real - b.real;
		y = a.img - b.img;
		cout << "Subtraction : " << x << " + " << y << "i " << endl;
	}

	void multiply()
	{
		int x = 0, y = 0;
		x = (a.real * b.real) - (a.img * b.img);
		y = (a.img * b.real) - (a.real * b.img);
		cout << "Multiplication : " << x << " + " << y << "i " << endl;
	}

	void divide()
	{
		float x = 0, y = 0;
		x = ((a.real * b.real) + (a.img * b.img)) / ((b.real * b.real) + (b.img * b.img));
		y = ((a.img * b.real) - (a.real * b.img)) / ((b.real * b.real) + (b.img * b.img));
		cout << "Division : " << x << " + " << y << "i " << endl;
	}
};



int main()
{
	SimpleNum s1(6, 2);
	ComplexNumber c1(6, 5, 3, 2);
	Calculator* cal[2];
	cal[0] = &s1;
	cal[1] = &c1;
	cal[0]->add();
	cal[0]->subtract();
	cal[0]->multiply();
	cal[0]->divide();
	cal[1]->add();
	cal[1]->subtract();
	cal[1]->multiply();
	cal[1]->divide();

	system("pause");
	return 0;
}
