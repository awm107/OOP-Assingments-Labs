#include <iostream>
using namespace std;

class Base
{

public:
    int x;
    static int y;  // definition
    void printx()
    {
    
        cout << x << " " << endl;  // can use static variables in normal functions
        cout << y << " " << endl;
    }

    static void printy()
    {
    
       // cout << x << " " << endl;  // Cannot use normal data variables in static functions
        cout << y << " " << endl;
    
    }


};

int Base::y = 40;  //providing static variable memory and value using scope resolution operator


int main()
{
    Base obj;
    obj.x = 10;
    obj.y = 20;
    obj.printx();
    Base obj2;
    obj2.x = 30;
    obj2.y = 50;
   Base::printy();   // The biggest advantage of static member functions is that it can be called without objects using this syntax.
    
    return 0;
}