#include <bits/stdc++.h>
#define fast_io                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

using namespace std;

int main() {
    fast_io;

    int n;
    long long target;
    cin >> n >> target;

    vector<long long> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    // 排序數字列表
    sort(numbers.begin(), numbers.end());

    // 初始化最小差距
    long long closest_diff = LLONG_MAX;
    long long closest_product = 0;

    // 使用雙指針方法查找最接近的乘積
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            // 檢查乘積是否會溢出
            if (numbers[i] != 0 && numbers[j] > LLONG_MAX / numbers[i]) {
                continue;
            }

            long long product = numbers[i] * numbers[j];
            long long diff = abs(product - target);

            if (diff < closest_diff) {
                closest_diff = diff;
                closest_product = product;
            }

            // 優化：如果當前乘積已經大於目標，則後續乘積會更大，無需繼續
            if (product > target) {
                break;
            }
        }
    }

    // 輸出結果
    cout << closest_diff << endl;

    return 0;
}
