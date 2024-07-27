#include <iostream>

using namespace std;

int main()
{
    // 讀取數字個數和目標數字
    int n;
    long long target;
    cin >> n >> target;
    long long numbers[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> numbers[i];
    }

    // 初始化最小差距
    long long closest_diff = 1e18;

    // 使用雙指針方法
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            long long product = numbers[i] * numbers[j];
            long long diff = abs(product - target);
            if (diff < closest_diff)
                closest_diff = diff;
        }
    }

    // 輸出結果
    cout << closest_diff << endl;

    return 0;
}
