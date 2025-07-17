#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::min;
using std::sort;
using std::string;

unsigned long long Maximum_Advertisement_Revenue(int n)
{
    long long *a = new long long[n];
    long long *b = new long long[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    std::sort(a,a+n);
    std::sort(b,b+n);
    unsigned long long sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i] * b[i];
    return sum;
}
int main()
{
    int n;
    cin >> n;
    cout << Maximum_Advertisement_Revenue(n);
    return 0;
}