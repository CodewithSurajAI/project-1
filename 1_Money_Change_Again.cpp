#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <utility>
#include <iomanip>
#include <map>
#include <limits>
#include <sstream>
#include <limits.h>
#include <float.h>
using namespace std;
long long MinChange(int money, vector<int> &coins)
{
    vector<int> minNumCoins(money + 1);
    minNumCoins[0] = 0;
    for (int m = 1; m <= money; m++)
    {
        int numCoins = 0;
        minNumCoins[m] = INT_MAX;
        for (int coin : coins)
        {
            if (coin <= m)
                numCoins = minNumCoins[m - coin] + 1;
            if (numCoins < minNumCoins[m])
                minNumCoins[m] = numCoins;
        }
    }
    return minNumCoins[money];
}
int main()
{
    int money;
    vector<int> coins = {1, 3, 4};
    cin >> money;
    cout << MinChange(money, coins);
    return 0;
}