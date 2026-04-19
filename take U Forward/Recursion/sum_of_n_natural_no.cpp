#include <iostream>
using namespace std;


// Parametrised way

int sum1(int n , int s)
{
    if(n < 1)
    {
        cout << s << endl;
        return 0;
    }
    return sum1(n-1,s+n);
}

// Functional way

int sum2(int n)
{
    if(n == 1) return 1;
    return n+sum2(n-1);
}

int main()
{
    int n = 5;
    sum1(n,0);

    cout << sum2(n) << endl;


    return 0;
}