#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;
using std::min;
using std::string;

int main()
{
    int n;
    cin>>n;
    cout << (n/10) +(n%10)/5+((n%10)%5);
    return 0;
}