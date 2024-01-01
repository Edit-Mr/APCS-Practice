#include <iostream>
#include <cmath>

using namespace std;

long long cut(int start, int end, int a[])
{
    if (end - start  < 2)
        return 0;
    double mid = (a[start] + a[end]) / 2;
    double  diff = a[end] - a[start];
    int  closestPosition = start;
    for (int i = start + 1; i <= end; i++)
    {
        int currentDiff = abs(a[i] - mid);
        if (currentDiff < diff)
        {
            diff = currentDiff;
            closestPosition = i;
        }
    }
    return (a[end] - a[start]) + cut(start, closestPosition, a) + cut(closestPosition, end, a);
}

int main()
{
    int L, N;
    cin >> N >> L;
    int a[N+2];
    for (int i = 1; i <= N; i++)
    {
        cin >> a[i];
    }
    a[0] = 0;
    a[N+1] = L;
    cout << cut(0, N+1, a);

    system("pause");
    return 0;
}