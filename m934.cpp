#include <iostream>
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

using namespace std;
int cost = 0x7f7f7f;
void combine(int list[], int n, int cost = 0)
{
    if (n == 2)
    {
        cost += abs(list[0] - list[1]);
        if (cost < ::cost)
            ::cost = cost;
        cout << cost << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            cost += abs(list[i] - list[j]);
            int new_list[n - 2];
            int skip = 0;
            for (int k = 0; k < n; k++)
            {
                if (k == i || k == j)
                {
                    new_list[k] = list[i] + list[j];
                    skip = 1;
                    k++;
                }
                else
                    new_list[k - skip] = list[k];
            }
            combine(new_list, n - 2, cost);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int list[n];
    for (int i = 0; i < n; i++)
        cin >> list[i];
    combine(list, n, 0);
    cout << cost;
}