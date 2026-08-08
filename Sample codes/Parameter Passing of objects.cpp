
/*In C++ we can pass class’s objects as argumentsand also return them from a function the same way we pass and return other variables.No special keyword or header file is required to do so.
To pass an object as an argument we write the object name as the argument while calling the function the same way we do it for other variables.
In this Example there is a class which has an integer variable ‘a’and a function ‘add’ which takes an object as argument.The function is called by one objectand takes another as an argument.
Inside the function, the integer value of the argument object is added to that on which the ‘add’ function is called.
In this method, we can pass objects as an argumentand alter them*/

// C++ program to show passing
// of objects to a function

#include <iostream>
using namespace std;

class Example {
public:
    int a;

    // This function will take
    // an object as an argument
    void add(Example E)
    {
        a = a + E.a;
    }
};

// Driver Code
int main()
{

    // Create objects
    Example E1, E2;

    // Values are initialized for both objects
    E1.a = 50;
    E2.a = 100;

    cout << "Initial Values \n";
    cout << "Value of object 1: " << E1.a
        << "\n& object 2: " << E2.a
        << "\n\n";

    // Passing object as an argument
    // to function add()
    E2.add(E1);

    // Changed values after passing
    // object as argument
    cout << "New values \n";
    cout << "Value of object 1: " << E1.a
        << "\n& object 2: " << E2.a
        << "\n\n";

    return 0;
}