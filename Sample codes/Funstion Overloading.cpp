#include <iostream>
using namespace std;

void print(int i, int k) {
	cout << " Here is int " << i <<  " " << k << endl;
}
void print(double  f) {
	cout << " Here is float " << f << endl;
}
void print(char const* c) {
	cout << " Here is char* " << c << endl;
}

int main() {
	print(10, 20);
	print(10.10);
	print("ten");  //C++ (const char [4])"ten"  // To pass const array we need const pointer as seen above
	return 0;
}