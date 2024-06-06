#include <bits/stdc++.h>
#define fast_io                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

using namespace std;

// ρ公籔竚絛瞅А0  20叫块ㄢ俱计だ程计ヘ㎝程氨竚
//https://zerojudge.tw/ShowProblem?problemid=m370
int main()
{
    int n, x;
    cin >> n >> x;
    int leftS = 200, rightS = -200, leftL = 0, rightL = 0;
    for (int i = 0; i < x; i++)
    {
        int temp;
        cin >> temp;
        if (temp < n)
        {
            leftL++;
            if (temp < leftS)
                leftS = temp;
        }
        else
        {
            rightL++;
            if (temp > rightS)
                rightS = temp;
        }
    }
    if (rightL > leftL)
        cout << rightL << " " << rightS << endl;
    else
        cout << leftL << " " << leftS << endl;
}