#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    int count[2] = {0};
    int position = 0;
    while (n > 0) {
        int digit = n % 10;
        count[position % 2] += digit;
        n /= 10;
        position++;
    }
    cout << abs(count[0] - count[1]);
    return 0;
}
