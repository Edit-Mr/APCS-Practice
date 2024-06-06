#include <bits/stdc++.h>
#define fast_io                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

using namespace std;

// 有n個角色，每個角色有攻擊力和防禦力。
// 角色的能力值是攻擊力和防禦力的平方和，輸出能力值第二大的攻擊力和防禦力數值。
// 保證每個角色的能力值相異。

int main()
{
    int n;
    cin >> n;
    int attack[n];
    int defense[n];
    int power[n];
    int biggest = 0; 
    for (int i = 0; i < n; ++i)
    {
        cin >> attack[i] >> defense[i];
        power[i] = attack[i] * attack[i] + defense[i] * defense[i];
        if (power[i] > power[biggest])
            biggest = i;
    }
    int second = 0;
    for (int i = 0; i < n; ++i)
        if (power[i] > power[second] && i != biggest)
            second = i;
    cout << attack[second] << " " << defense[second];
    return 0;
}