#include <iostream>
using namespace std;

// Parametrised way

int fact1(int n, int p)
{
    if(n == 1 || n == 0) 
    {
        cout << p << endl;
        return p;
    }
    
    return fact1((n-1) , (p*n));
}

// Functional way

int fact2(int n)
{
    if(n == 1 || n == 0) return 1;
    return n*fact2(n-1);
}

int main()
{
    int n = 10;

    fact1(n,1);

    cout << fact2(n) << endl;


    return 0;
}