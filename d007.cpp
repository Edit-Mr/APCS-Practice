#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, P;
    cin >> n >> P;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    vector<long long> dp(P + 1, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = P; j >= numbers[i]; --j) {
            dp[j] = max(dp[j], dp[j - numbers[i]] + numbers[i]);
        }
    }

    cout << dp[P] << endl;
  system("pause");
    return 0;
}
