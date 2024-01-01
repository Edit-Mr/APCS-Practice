#include <iostream>

using namespace std;

int countCombinations(int numbers[],int index, int currentProduct,int l)
{
    if (index == l)
        return (int)(currentProduct % 10009 == 1);
    return countCombinations(numbers,index + 1, (currentProduct * numbers[index]) % 10009,l) + countCombinations(numbers,index + 1, currentProduct,l);
}

int main()
{
    int n;
    cin >> n;
    int numbers[n];
    for (int i = 0; i < n; ++i)
        cin >> numbers[i];
    int result = countCombinations(numbers,0, 1,n);
    cout << result - 1 << endl;
    return 0;
}
