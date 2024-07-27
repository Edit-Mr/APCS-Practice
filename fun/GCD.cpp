#include <iostream>
using namespace std;

// �p���ƪ��̤j���]��
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// �p��}�C���Ҧ��ƪ��̤j���]��
int findGCD(int arr[], int n) {
    int result = arr[0];
    for (int i = 1; i < n; i++) {
        result = gcd(result, arr[i]);
        if (result == 1) {
            return 1; // 1 �O�̤p�����]��
        }
    }
    return result;
}

int main() {
    int arr[] = {24, 36, 48, 60}; // ���ռƲ�
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = findGCD(arr, n);
    cout << "�}�C���Ʀr���̤j���]�ƬO: " << result << endl;

    return 0;
}