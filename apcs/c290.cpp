#include 
using namespace std;

int main(){
    //�[�t��J��X�{��
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a; //�Φr���x�s��J���Ʀr
    cin >> a;
    int ans = 0; //�N���ת�l�ȳ]��0

    for(int i = 0; a[i]; i++){
        if(i%2) ans += a[i]-'0'; //�Y�O�_�ƶ��A�[�W��
        else ans-= a[i]-'0'; //�Y�O���ƶ��A���
    }

    ans = (ans>0)?ans:-ans; //�N�����ഫ�������

    cout << ans;
    return 0;
}