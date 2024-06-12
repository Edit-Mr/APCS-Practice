#include <iostream>
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

using namespace std;

int main()
{
    int L, N;
    cin >> L >> N;
    int arr[N + 2];
    arr[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }
    arr[N + 1] = L;
    for (int i = 1; i < N; i++)
        for (int j = 1; j < N; j++)
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }

    int add = 0;
    for (int i = 0; i <= N; i++)
    {
        int need = (arr[i + 1] - arr[i]) / 15;
        if (need > 0)
            if ((arr[i + 1] - arr[i]) % 15 == 0)
                add += need - 1;
            else
                add += need + 1;
    }
    cout << add << endl;
}