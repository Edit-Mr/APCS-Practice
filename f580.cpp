#include <iostream>
#define fast_io                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

using namespace std;

// 接下來有 n次修改操作，每個操作包含兩個整數 a, b
// 若 a, b都是正整數，交換編號 a與編號b 的骰子的位置。
// 若 b 為 -1，將編號 a 的骰子向前旋轉。
// 若b 為 -1，將編號 a 的骰子向右旋轉。
// 在 n次操作結束之後，依序輸出編號 1到編號n 的骰子朝上的點數。

int main()
{
    int n, m;
    cin >> n >> m;
    int diceX[n][4];
    int diceY[n][4];

    for (int i = 0; i < n; ++i)
    {
        diceX[i][0] = 4;
        diceX[i][1] = 2;
        diceX[i][2] = 3;
        diceX[i][3] = 1;
        diceY[i][0] = 5;
        diceY[i][1] = 6;
    }

    int dice[n];
    for (int i = 0; i < n; i++)
        dice[i] = i + 1;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        if (b == -1)
        {
            a = dice[a];
            int temp = diceY[a][0];
            diceY[a][0] = diceX[a][0];
            diceX[a][0] = diceY[a][1];
            diceY[a][1] = diceX[a][2];
            diceX[a][2] = temp;
        }
        else if (b == -2)
        {
            a = dice[a];
            int temp = diceX[a][0];
            diceX[a][0] = diceX[a][3];
            diceX[a][3] = diceX[a][2];
            diceX[a][2] = diceX[a][1];
            diceX[a][1] = temp;
        }
        else
        {
            int temp = dice[a]; // 注意索引從0開始，但骰子編號從1開始
            dice[a] = dice[b - 1];
            dice[b - 1] = temp;
        }
    }
    // 輸出
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; ++j)
            if (dice[j] == i)
                cout << diceY[j][0] << (i != n - 1) ? " " : "\n";
    return 0;
}