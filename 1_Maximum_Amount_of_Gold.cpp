#include <iostream>
#include <vector>
#include <utility>
using namespace std;

long long knapsack(vector<int> weights_values, int W)
{
    vector<vector<long long>> values(W + 1, vector<long long>(weights_values.size()));

    for (int i = 1; i < weights_values.size(); i++)
    {
        for (int w = 1; w <= W; w++)
        {
            values[w][i] = values[w][i - 1];
            int wi = weights_values[i];
            if (wi <= w)
            {
                long long val = values[w - wi][i - 1] + wi;
                values[w][i] = max(values[w][i], val);
            }
        }
    }
    return values[W][weights_values.size() - 1];
}
int main()
{
    int W, n;
    cin >> W >> n;
    vector<int> weights_values(n + 1);

    for (int i = 1; i <= n; i++)
    {
        int w;
        cin >> w;
        weights_values[i] = w;
    }
    cout << knapsack(weights_values, W);
    return 0;
}