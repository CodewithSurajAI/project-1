#include <iostream>
#include <vector>
#include <utility>
using namespace std;

pair<int, int> partition(vector<long long> &v, int l, int r)
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
void QuickSort(vector<long long> &v, int l, int r)
{
    if (l >= r)
        return;
    pair<int, int> m = partition(v, l, r);
    QuickSort(v, l, m.first - 1);
    QuickSort(v, m.second + 1, r);
}
long long Majority_Element(vector<long long> &v)
{
    long long maxCount = 0;
    long long Count = 1;
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] != v[i - 1])
        {
            maxCount = max(maxCount, Count);
            Count = 0;
        }
        Count++;
    }
    maxCount = max(maxCount, Count);
    //cout<<maxCount<<endl;
    return maxCount > v.size() / 2;
}
int main()
{
    long long size;
    cin >> size;
    vector<long long> v(size);
    for (long long &x : v)
        cin >> x;
    QuickSort(v, 0, size - 1);
    cout << Majority_Element(v);

    return 0;
}