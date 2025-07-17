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

long long binary_search(std::vector<long long>& v, long long first, long long last, long long key)
{
    while(first<=last)
    {
        long long middle = first+(last-first)/2;
        if(v[middle]==key)
            return middle;
        else if(v[middle]>key)
            last = middle-1;
        else
            first = middle+1;
    }
    return -1;
}

int main()
{
    long long n,k;
    cin>>n;
    vector<long long> v(n);
    for(long long &x:v)cin>>x;
    cin>>k;
    for(long long i=0;i<k;i++)
    {
        long long temp;
        cin>>temp;
        cout<<binary_search(v,0,n-1,temp);
        if(i!=k-1)
            cout<<" ";
    }
    return 0;
}
