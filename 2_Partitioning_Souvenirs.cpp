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
#include <stack>

using namespace std;

bool knapsack3(vector<int> souvenirs, int totalSum)
{
    if (totalSum % 3 != 0)
        return 0;
    vector<vector<vector<int>>> values(souvenirs.size(), vector<vector<int>>(totalSum / 3 + 1, vector<int>(totalSum / 3 + 1)));
    for (int i = 1; i < values.size(); i++)
    {
        for (int j = 0; j <= totalSum / 3; j++)
        {
            for (int k = 0; k <= totalSum / 3; k++)
            {
                values[i][j][k] = values[i - 1][j][k];
                if (j >= souvenirs[i])
                    values[i][j][k] = max(values[i - 1][j - souvenirs[i]][k] + souvenirs[i], values[i][j][k]);
                if (k >= souvenirs[i])
                    values[i][j][k] = max(values[i - 1][j][k - souvenirs[i]] + souvenirs[i], values[i][j][k]);
            }
        }
    }
    return values.back()[totalSum / 3][totalSum / 3] == 2 * (totalSum / 3.0);
}

int main()
{
    int n, totalSum = 0;
    cin >> n;
    vector<int> souvenirs(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> souvenirs[i];
        totalSum += souvenirs[i];
    }
    cout << knapsack3(souvenirs, totalSum);
    return 0;
}