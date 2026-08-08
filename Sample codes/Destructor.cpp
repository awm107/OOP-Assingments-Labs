#include <iostream>
using namespace std;
class String {
private:
    char* s;
    int size;

public:
    String(char* c)
    {
        size = strlen(c);
        cout << size << endl;
        s = new char[size + 1];
        strcpy_s;
    }
    ~String()
    {
        delete[] s;
    }
};

int main()
{
    char arr[10] = { 'm','y','n','a' };
    String obj1(arr);

    

    return 0;
}