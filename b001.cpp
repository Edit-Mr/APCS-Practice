#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    if (a < b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    int r = a % b;
    while (r != 0)
    {
        a = b;
        b = r;
        r = a % b;
    }
    cout << b;
    return 0;
}