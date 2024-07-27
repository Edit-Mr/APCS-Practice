#include <iostream>

using namespace std;

int main()
{
    int a, b, result, c = 1;
    cin >> a >> b >> result;
    if (a>0) a = 1;
    if (b>0) b = 1;
    // 檢查 AND 運算
    if ((a & b) == result)
    {
        cout << "AND" << endl;
        c = 0;
    }

    // 檢查 OR 運算
    if ((a | b) == result)
    {
        cout << "OR" << endl;
        c = 0;
    }

    // 檢查 XOR 運算
    if ((a != b) == result)
    {
        cout << "XOR" << endl;
        c = 0;
    }

    // 根據結果輸出
    if (c == 1)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}