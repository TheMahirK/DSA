#include <iostream>
using namespace std;

bool isArmstrongNumber(int n)
{
    int copy = n;
    int sum = 0;
    while (n != 0)
    {
        int digit = n % 10;
        sum += (digit * digit * digit);
        n = n / 10;
    }
    return (sum == copy);
}

int main()
{
    int n = 153;

    if (isArmstrongNumber(n))
    {
        cout << n << " is an Armstrong Number";
    }
    else
    {
        cout << n << " is NOT an Armstrong Number";
    }

    return 0;
}