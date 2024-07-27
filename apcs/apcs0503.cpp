#include <bits/stdc++.h>
#define fast_io                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

using namespace std;

int main()
{
    int N, // count
        K, // renove
        T; // end
    cin >> N >> K;
    int a[N + 2];
    cin >> a[N + 1];
    a[0] = 0;
    for (int i = 1; i <= N; i++)
        cin >> a[i];
    for (int i = 0; i < N + 1; i++)
    {
        a[i] = a[i + 1] - a[i];
        cout << a[i] << " ";
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
    int min = 0;
    for (int i = 0; i <= K; i++)
        min += a[i];
    cout << min << endl;
    return 0;
}