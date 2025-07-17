#include <iostream>
#include <cmath>
using namespace std;
int periodCalculator(long long m)
{
    int periodCount = 0;

    unsigned long long first = 0;
    unsigned long long second = 1;
    while (true)
    {
        unsigned long long temp = first;
        first = second;
        second = (temp + second) % m;
        periodCount++;
        if (first == 0 && second == 1 && periodCount > 2)
            return periodCount;
    }
    return periodCount;
}
int Fibonacci_Number_Again(unsigned long long num, unsigned long long m)
{
    if (num <= 1)
        return num;
    int period = periodCalculator(m);
    unsigned long long first = 0;
    unsigned long long second = 1;
    unsigned long long iterations = (num >= m ? num % period : num);
    unsigned long long Result = 1;
    //cout<<iterations<<endl;
    if (iterations == 0)
        return 0;
    for (int i = 0; i < iterations - 1; i++)
    {
        unsigned long long temp = first;
        first = second;
        second = (temp + second) % m;
        //cout<<"Second = "<<second<<endl;
        Result+=(second%10);
        //cout<<"Result = "<<Result<<endl;
    }
    //cout << "period = " << period << endl;
    //cout<<"Second = "<<second<<endl;
    //cout << int(1 + floor(log10(m)))<<endl;
    return Result%10;
}

int main()
{
    unsigned long long num;
    cin >> num;
    cout << Fibonacci_Number_Again(num, 10);
    //cout<<"NUM = "<<num<<endl;
    return 0;
}