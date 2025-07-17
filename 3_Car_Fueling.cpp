#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <utility>
#include <iomanip>
using std::cin;
using std::cout;
using std::endl;
using std::min;
using std::pair;
using std::string;
int car_Fueling(int d, int m, int n)
{
    int *stops = new int[n+2];
    stops[0] = 0;
    stops[n+1] = d;
    for (int i = 1; i <= n; i++)
        cin >> stops[i];
    int NumRefills = 0,currentRefill = 0;
    while(currentRefill <= n)
    {
        int lastRefill = currentRefill;
        while(currentRefill<=n && stops[currentRefill+1]- stops[lastRefill]<=m)
            currentRefill++;
        if (currentRefill == lastRefill)
            return -1;
        if (currentRefill <= n)
            NumRefills++;
    }
    return NumRefills;
}
int main()
{
    int d, m, n;
    cin >> d >> m >> n;
    cout << car_Fueling(d, m, n);
    return 0;
}