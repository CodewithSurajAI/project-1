#include <iostream>
using namespace std;
int GCD(int a, int b)
{
    if (b == 0)
        return a;
    return GCD(b, a % b);
}
long long LCM(int a ,int b)
{
    return (static_cast<long long>(a)*b)/GCD(a,b);
}
int main()
{
    int a, b;
    cin >> a >> b;
    cout << LCM(a, b);
    return 0;
}