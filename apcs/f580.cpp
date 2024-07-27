#include <iostream>
#define fast_io                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

using namespace std;

// ���U�Ӧ� n���ק�ާ@�A�C�Ӿާ@�]�t��Ӿ�� a, b
// �Y a, b���O����ơA�洫�s�� a�P�s��b ����l����m�C
// �Y b �� -1�A�N�s�� a ����l�V�e����C
// �Yb �� -1�A�N�s�� a ����l�V�k����C
// �b n���ާ@��������A�̧ǿ�X�s�� 1��s��n ����l�¤W���I�ơC

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
            int temp = dice[a]; // �`�N���ޱq0�}�l�A����l�s���q1�}�l
            dice[a] = dice[b - 1];
            dice[b - 1] = temp;
        }
    }
    // ��X
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; ++j)
            if (dice[j] == i)
                cout << diceY[j][0] << (i != n - 1) ? " " : "\n";
    return 0;
}