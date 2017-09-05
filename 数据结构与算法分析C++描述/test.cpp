#include <iostream>

using namespace std;

class IntCell
{
public:
    explicit IntCell(int initialValue = 0): storedValue(initialValue)
    {
        cout << "Constructor called!" << endl;
    }
    int read() const
    {
        return storedValue;
    }
    void write(int x)
    {
        storedValue = x;
    }
private:
    int storedValue;
};

int main()
{
    IntCell a;
    cout << a.read() << endl;
    return 0;
}