#include <iostream>
#include <vector>
#include <utility>
using namespace std;

pair<int, int> partition3(vector<long long> &v, int l, int r)
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
void sortMedian(vector<long long> &v, int l, int r)
{
    int middle = l + (r - l) / 2;
    long long Max_Element = max(v[l], max(v[middle], v[r]));
    long long Min_Element = min(v[l], min(v[middle], v[r]));
    long long middle_Element = v[l] + v[r] + v[middle] - Max_Element - Min_Element;
    v[l] = middle_Element;
    v[middle] = Min_Element;
    v[r] = Max_Element;
}
void QuickSort(vector<long long> &v, int l, int r)
{
    if (l >= r)
        return;
    sortMedian(v,l,r);
    pair<int, int> m = partition3(v, l, r);
    QuickSort(v, l, m.first - 1);
    QuickSort(v, m.second + 1, r);
}

int main()
{
    long long size;
    cin >> size;
    vector<long long> v(size);
    for (long long &x : v)
        cin >> x;
    QuickSort(v, 0, size - 1);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i];
        if(i!=v.size()-1)
            cout<<" ";
    }
    return 0;
}