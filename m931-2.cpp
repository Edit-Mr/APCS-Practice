#include <bits/stdc++.h>
#define fast_io                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

using namespace std;

// ��n�Ө���A�C�Ө��⦳�����O�M���m�O�C
// ���⪺��O�ȬO�����O�M���m�O������M�A��X��O�ȲĤG�j�������O�M���m�O�ƭȡC
// �O�ҨC�Ө��⪺��O�Ȭ۲��C

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