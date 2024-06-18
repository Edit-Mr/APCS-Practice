#include 
using namespace std;

int main(){
    //加速輸入輸出程式
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a; //用字串儲存輸入的數字
    cin >> a;
    int ans = 0; //將答案初始值設為0

    for(int i = 0; a[i]; i++){
        if(i%2) ans += a[i]-'0'; //若是奇數項，加上值
        else ans-= a[i]-'0'; //若是偶數項，減掉值
    }

    ans = (ans>0)?ans:-ans; //將答案轉換為絕對值

    cout << ans;
    return 0;
}