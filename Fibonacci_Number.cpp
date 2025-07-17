#include<iostream>
#include<assert.h>
using namespace std;
// fast iterative solution
long long Fibonacci_Number(int n)
{
    if(n<=1) return n;
    long long *fibArr = new long long[n+1];
    fibArr[0] = 0;
    fibArr[1] = 1;
    for(int i=2;i<=n;i++)
    {
        fibArr[i] = fibArr[i - 1] + fibArr[i - 2];
    }
    return fibArr[n];
}
// slow recursive solution
long long Fibonacci_Number_Rec(int n)
{
    if (n <= 1)
        return n;
    return Fibonacci_Number_Rec(n - 1) + Fibonacci_Number_Rec(n-2);
}
// testing 
void test_Fib()
{
    for(int i=0;i<20;i++)
        assert(Fibonacci_Number(i)==Fibonacci_Number_Rec(i));
}
int main()
{
    int num;
    cin>>num;
    cout<<Fibonacci_Number(num);
    //test_Fib();
    return 0;
}