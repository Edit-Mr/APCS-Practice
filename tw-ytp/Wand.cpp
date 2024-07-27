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

    // �ƧǼƦr�C��
    sort(numbers.begin(), numbers.end());

    // ��l�Ƴ̤p�t�Z
    long long closest_diff = LLONG_MAX;
    long long closest_product = 0;

    // �ϥ������w��k�d��̱��񪺭��n
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            // �ˬd���n�O�_�|���X
            if (numbers[i] != 0 && numbers[j] > LLONG_MAX / numbers[i]) {
                continue;
            }

            long long product = numbers[i] * numbers[j];
            long long diff = abs(product - target);

            if (diff < closest_diff) {
                closest_diff = diff;
                closest_product = product;
            }

            // �u�ơG�p�G��e���n�w�g�j��ؼСA�h���򭼿n�|��j�A�L���~��
            if (product > target) {
                break;
            }
        }
    }

    // ��X���G
    cout << closest_diff << endl;

    return 0;
}
