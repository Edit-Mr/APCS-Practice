#include <bits/stdc++.h>
#define fast_io                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

using namespace std;

int main()
{
    unsigned long long n;
    cin >> n;
    int a[10] = {6, 2, 5, 5, 4, 5, 6, 4, 7, 6};
    int sum = 0;
    if (n == 0)
        sum = 6;
    while (n >= 1)
    {
        sum += a[n % 10];
        n /= 10;
    }
    cout << sum << endl;

    return 0;
}