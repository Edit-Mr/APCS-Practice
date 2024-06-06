#include <bits/stdc++.h>
#define fast_io                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> points(n);

    for (int i = 0; i < n; ++i)
        cin >> points[i].first >> points[i].second;

    map<pair<char, char>, int> turns{
        {{'E', 'N'}, 0}, {{'N', 'W'}, 0}, {{'W', 'S'}, 0}, {{'S', 'E'}, 0}, {{'E', 'S'}, 1}, {{'S', 'W'}, 1}, {{'W', 'N'}, 1}, {{'N', 'E'}, 1}, {{'E', 'W'}, 2}, {{'W', 'E'}, 2}, {{'N', 'S'}, 2}, {{'S', 'N'}, 2}, {{'N', 'N'}, 3}, {{'S', 'S'}, 3}, {{'W', 'W'}, 3}, {{'E', 'E'}, 3}};

    int turn[4] = {0};
    char currentDirection = 'E';

    for (int i = 1; i < n; ++i)
    {
        char newDirection;
        if (points[i].first > points[i - 1].first)
        {
            newDirection = 'E'; // 東
        }
        else if (points[i].first < points[i - 1].first)
        {
            newDirection = 'W'; // 西
        }
        else if (points[i].second > points[i - 1].second)
        {
            newDirection = 'N'; // 北
        }
        else if (points[i].second < points[i - 1].second)
        {
            newDirection = 'S'; // 南
        }
        int turnType = turns[{currentDirection, newDirection}];
        turn[turnType]++;
        currentDirection = newDirection;
    }
        cout << turn[0] << ' '<< turn[1] << ' '<< turn[2];
    return 0;
}
