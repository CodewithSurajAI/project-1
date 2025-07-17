//2 Maximum Value of the Loot
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <utility>
#include<iomanip>
using std::cin;
using std::cout;
using std::endl;
using std::min;
using std::pair;
using std::string;

bool sortByfirst(const pair<double, double> &p1, const pair<double, double> &p2)
{
    return p1.first > p2.first;
}
double Maximum_Value_of_the_Loot(int n, int W)
{
    double result = 0;
    pair<double, double> *arrPairs = new pair<double, double>[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arrPairs[i].first >> arrPairs[i].second;
        arrPairs[i].first /= arrPairs[i].second;
    }
    sort(arrPairs, arrPairs + n, sortByfirst);
    int i=0;
    while(W>0 && i<n)
    {
        double minW = min(arrPairs[i].second,(double)W);
        result+=minW*arrPairs[i].first;
        W-=minW;
        i++;
    }
    return result;
}
int main()
{
    int n, W;
    cin >> n >> W;
    cout << std::fixed << std::setprecision(5) << Maximum_Value_of_the_Loot(n, W);
    return 0;
}