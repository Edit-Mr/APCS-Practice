#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int N;
    cin >> N;
    vector<int> sortedNumbers(N);
    for (int i = 0; i < N; i++)
        cin >> sortedNumbers[i];
    sort(sortedNumbers.begin(), sortedNumbers.end());
    sortedNumbers.erase(unique(sortedNumbers.begin(), sortedNumbers.end()), sortedNumbers.end());
    cout
        << sortedNumbers.size() << endl;
    for (int y : sortedNumbers)
        cout << y << " ";
    system("pause");
    return 0;
}