#include <iostream>
using namespace std;

/*
void print(string name)
{

	cout << name << endl;
}
int main()
{
	for (int i = 0; i < 10000; i++)
	{
		print("arslan shahbaz");
	}


	return 0;
}
*/

//In the above example i=0 go up then come down i=1 go up then come down i=2 go up and then come down 

// Using inline function
inline void print(string name)
{

	cout << name << endl;
}
int main()
{
	for (int i = 0; i < 10000; i++)
	{
		print("arslan shahbaz");
	}


	return 0;
}

//Now the code is transferred from  function to the the main where that function is being called by the compiler so that compiler do not have to go up and down continiuosly.