#include <bits/stdc++.h>
#define fast_io                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

using namespace std;

// �ѹ��P������m�d�򧡬�0 �� 20�C�п�X��Ӿ�ơA���O�N��̦h��Y�쪺�����ƥةM�̫�@�ӦY���������U����m�C
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