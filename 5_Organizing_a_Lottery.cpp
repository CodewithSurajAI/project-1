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
using namespace std;
bool operator==(pair<long, long> &p1, pair<long, long> &p2)
{
    return p1.first < p2.first;
}
pair<int, int> partition3(vector<pair<long long, long long>> &v, int l, int r)
{
    int j = l;
    for (int i = l + 1; i <= r; i++)
    {
        if (v[i] <= v[l])
        {
            j++;
            swap(v[i], v[j]);
        }
    }
    int m2 = j;
    j = l;
    for (int i = l + 1; i <= m2; i++)
    {
        if (v[i] < v[l])
        {
            j++;
            swap(v[i], v[j]);
        }
    }
    swap(v[j], v[l]);
    return make_pair(j, m2);
}

void QuickSort(vector<pair<long long, long long>> &v, int l, int r)
{
    if (l >= r)
        return;
    pair<int, int> m = partition3(v, l, r);
    QuickSort(v, l, m.first - 1);
    QuickSort(v, m.second + 1, r);
}
int main()
{
    int s, p;
    long long x, y;
    cin >> s >> p;
    long long Min = 2147483647, Max = -2147483647 - 1;
    vector<pair<long long, long long>> limits(s);
    for (int i = 0; i < s; i++)
    {
        cin >> x >> y;
        limits[i] = make_pair(x, y);
        Min = min(Min, x);
        Max = max(Max, y);
    }
    QuickSort(limits, 0, limits.size() - 1);
    for(int i=0;i<p;i++)
    {
        cin>>x;
        int j=0,count=0;
        while(x>=limits[j].first&&j<limits.size())
            if (x <= limits[j++].second)
                count++;
        cout<<count;
        if(i!=p-1)
            cout<<" ";
    }
    return 0;
}
