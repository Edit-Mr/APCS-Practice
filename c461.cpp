#include <iostream>

using namespace std;

int main()
{
    int a, b, result, c = 1;
    cin >> a >> b >> result;
    if (a>0) a = 1;
    if (b>0) b = 1;
    // �ˬd AND �B��
    if ((a & b) == result)
    {
        cout << "AND" << endl;
        c = 0;
    }

    // �ˬd OR �B��
    if ((a | b) == result)
    {
        cout << "OR" << endl;
        c = 0;
    }

    // �ˬd XOR �B��
    if ((a != b) == result)
    {
        cout << "XOR" << endl;
        c = 0;
    }

    // �ھڵ��G��X
    if (c == 1)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}