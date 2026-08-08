#include <iostream>
using namespace std;
class Square
{
public:
    int side;

    //functions
    Square area()
    {
        cout << "Area of the square is :" << side * side << endl;
        return *this;
    }
    Square perimeter()
    {
        cout << "Perimeter of the square is :" << 4 * side << endl;
        return *this;
    }
};
int main()
{
    Square sq;

    sq.side = 3;

    //cascading function calls
    sq.area().perimeter();

    return 0;
}