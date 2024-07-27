#include <iostream>
#define short short
using namespace std;
short shortest;
short N, // room size
    K; // highway
void go(short hole[][4], short already[], short blood, short last, short alreadyBlock)
{
    if (blood < 1)
        return;
    for (short i = 1; i <= K; i++)
    {
        if (already[i])
            continue;
        short newAlreadyBlock = alreadyBlock + abs(hole[i][0] - hole[last][2]) + abs(hole[i][1] - hole[last][3]);// 走走看
        short calc = newAlreadyBlock + N - hole[i][2] + N - hole[i][3];                         // 直接到終點
        if (calc < shortest)
        {
            shortest = calc;
        }
        short newAlready[K + 1];
        for (short j = 0; j <= K; j++)
            newAlready[j] = already[j];
        newAlready[i] = 1;
        go(hole, newAlready, blood - 1, i, newAlreadyBlock);
    }
}

int main()
{
    short T; // blood
    cin >> N >> K >> T;
    shortest = N * 2 - 2;
    short hole[K + 1][4] = {1};
    for (short i = 1; i <= K; i++)
        for (short j = 0; j < 4; j++)
            cin >> hole[i][j];
    short already[K + 1] = {0};
    go(hole, already, T, 0, 0);
    cout << shortest;
    return 0;
}