#include <iostream>
using namespace std;
int shortest;
short N, // room size
    K;   // highway
void go(int hole[][4], int already[], int blood, int last, int alreadyBlock)
{
    if (blood < 1)
        return;
    for (int i = 1; i <= K; i++)
    {
        if (already[i])
            continue;
        alreadyBlock += abs(hole[i][0] - hole[last][2]) + abs(hole[i][1] - hole[last][3]); // 走走看
        int calc = alreadyBlock + N - hole[i][2] + N - hole[i][3]; // 直接到終點
        if (calc < shortest)
        {
            shortest = calc;
        }
        int newAlready[K + 1];
        for (int j = 0; j <= K; j++)
            newAlready[j] = already[j];
        newAlready[i] = 1;
        go(hole, newAlready, blood - 1, i, alreadyBlock);
    }
}

int main()
{
    short T; // blood
    cin >> N >> K >> T;
    shortest = N * 2 - 2;
    int hole[K + 1][4] = {1};
    for (int i = 1; i <= K; i++)
        for (int j = 0; j < 4; j++)
            cin >> hole[i][j];
    int already[K + 1] = {0};
    go(hole, already, T, 0, 0);
    cout << shortest;
    return 0;
}