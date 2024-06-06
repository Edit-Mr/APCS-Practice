#include <iostream>
#define int long long
using namespace std;
const int maxn = 2e5 + 5;
signed main()
{
  int n, k, count = 0, got = 0, i = 0;
  cin >> n >> k;
  while (got < k)
  {
    char letter;
    int number;
    cin >> letter >> number;
    if (number <= 12 || number >= 65 || (letter == 'F' && number >= 35 && number <= 45))
    {
      count += i - got;
      got++;
    }
    i++;
  }
  cout << count << endl;
}