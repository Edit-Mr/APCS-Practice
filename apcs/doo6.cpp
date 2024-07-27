#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n ; i++)
    {
        cin >> a[i];
    }
    
    int P = 10009;
    int count = 0;
    for (int i = 0; i < (1 << n); i++)
    {
        int product = 1;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                product = (product * a[j]) % P;
            }
        }
        if (product == 1)
        {
            count++;
        }
    }
    
    cout << count << endl;
    system("pause");
    
    return 0;
}