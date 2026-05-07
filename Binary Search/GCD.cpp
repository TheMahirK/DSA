#include <iostream>
using namespace std;

int gcd1(int m, int n)
{
    for (int i = min(m, n); i >= 1; i--)
    {
        if (m % i == 0 && n % i == 0)
        {
            return i;
        }
    }
    return 1;
}

// will practice , understand and write euclidean algorithm tomorrow morning

int main()
{
    int m = 12;
    int n = 9;

    int gcd = gcd1(m, n);

    cout << "GCD of " << m << " and " << n << " is : " << gcd;

    return 0;
}