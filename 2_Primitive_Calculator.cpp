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

long long Primitive_Calculator(long long num, stack<long long> &path)
{
    vector<pair<long long, int>> operations(num + 1);
    operations[0].first = 0;
    operations[1].first = 0;
    for (long long n = 2; n <= num; n++)
    {
        long long n1, n2 = 2147483647, n3 = 2147483647;
        n2 = operations[n / 2].first + 1;
        n3 = operations[n / 3].first + 1;
        n1 = operations[n - 1].first + 1;
        if (n % 2 == 0 && n % 3 == 0)
            operations[n].first = min(n1, min(n2, n3));
        else if (n % 2 != 0 && n % 3 == 0)
            operations[n].first = min(n1, min(n2 + 2, n3));
        else if (n % 2 == 0 && n % 3 != 0)
            operations[n].first = min(n1, min(n2, operations[(n / 3) * 3].first + n - (n / 3) * 3));
        else
            operations[n].first = operations[n].first = min(n1, min(operations[(n / 2) * 2].first + n - (n / 2) * 2,
                                                                    operations[(n / 3) * 3].first + n - (n / 3) * 3));
        if (operations[n].first == n1)
            operations[n].second = 1;
        else if (operations[n].first == n2)
            operations[n].second = 2;
        else
            operations[n].second = 3;
    }
    long long temp = num;
    path.push(num);
    while (temp != 1)
    {
        if (operations[temp].second == 1)
            temp -= 1;
        else if (operations[temp].second == 2)
            temp /= 2;
        else
            temp /= 3;
        path.push(temp);
    }
    return operations[num].first;
}

int main()
{
    long long num, x;
    cin >> num;
    stack<long long> path;
    cout << Primitive_Calculator(num, path) << endl;
    while (!path.empty())
    {
        x = path.top();
        cout << x;
        path.pop();
        if (!path.empty())
            cout << " ";
    }
    return 0;
}