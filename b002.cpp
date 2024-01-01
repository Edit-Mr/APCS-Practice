#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    if (a.length() > b.length())
        cout << "chuang" << endl;
    else
        cout << "diang" << endl;
    return 0;
}