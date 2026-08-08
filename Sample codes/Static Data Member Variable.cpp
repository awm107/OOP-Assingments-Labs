#include <iostream>
using namespace std;

class Base
{
    
public:
    int x;
    static int y;  // definition
};

int Base::y=40;  //providing static variable memory and value using scope resolution operator


int main()
{
    Base obj;
    obj.x = 10;
    obj.y = 20;

    Base obj2;
    obj2.x = 30;
    obj2.y = 50;

    cout << obj.y << endl;
    cout << obj.x << endl;
    cout << obj2.y << endl;
    cout << obj2.x;
    return 0;
}