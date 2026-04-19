#include <iostream>
using namespace std;

int fib1(int n)
{
    if(n == 1 || n == 0) return n;
    return fib1(n-1)+fib1(n-2);
}

int main()
{
    int n = 32;
    for(int i=0; i<=n; i++)
    {
        cout << fib1(i) << ' ';
    }
    return 0;
}