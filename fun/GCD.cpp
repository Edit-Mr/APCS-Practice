#include <iostream>
using namespace std;

// 璸衡ㄢ计程そ计
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// 璸衡皚い┮Τ计程そ计
int findGCD(int arr[], int n) {
    int result = arr[0];
    for (int i = 1; i < n; i++) {
        result = gcd(result, arr[i]);
        if (result == 1) {
            return 1; // 1 琌程そ计
        }
    }
    return result;
}

int main() {
    int arr[] = {24, 36, 48, 60}; // 代刚计舱
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = findGCD(arr, n);
    cout << "皚い计程そ计琌: " << result << endl;

    return 0;
}