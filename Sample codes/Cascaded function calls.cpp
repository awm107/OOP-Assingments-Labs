#include<iostream>
using namespace std;

class Demo
{
	public:
		Demo FUN1()
		{
			cout <<"\nFUN1 CALLED"<<endl;

			return *this;
		}

		Demo FUN2()
		{
			cout <<"\nFUN2 CALLED"<<endl;

			return *this;
		}
		
		Demo FUN3()
		{
			cout <<"\nFUN3 CALLED"<<endl;

			return *this;
		}

};

int main()
{
	Demo ob;

	ob.FUN1().FUN2().FUN3();

	return 0;
}



















