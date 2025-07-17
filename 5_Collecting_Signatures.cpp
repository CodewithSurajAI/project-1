#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <utility>
using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::min;
using std::pair;
using std::string;

bool sortToSec(pair<long long, long long> &p1, pair<long long, long long> &p2)
{
    return p1.second < p2.second;
}
void Collecting_Signatures(int n)
{

    pair<long long, long long> *arrPiars = new pair<long long, long long>[n];
    for (int i = 0; i < n; i++)
        cin >> arrPiars[i].first >> arrPiars[i].second;
    std::sort(arrPiars, arrPiars + n, sortToSec);
    int i = 0;
    int count = 0;
    std::vector<long long> endPoints;
    while (i < n)
    {
        count++;
        long long endPoint = arrPiars[i].second;
        endPoints.push_back(endPoint);
        i++;
        while (i < n)
        {
            if (arrPiars[i].first <= endPoint && endPoint <= arrPiars[i].second)
                i++;
            else 
                break;
        }
    }
    cout << count << endl;
    for (int i = 0; i < endPoints.size(); i++)
    {
        cout << endPoints[i];
        if (i != n - 1)
            cout << " ";
    }
}
int main()
{
    int n;
    cin >> n;
    Collecting_Signatures(n);
    return 0;
}