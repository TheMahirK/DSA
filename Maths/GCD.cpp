/*
Problem Name : Find GCD/HCF of two given numbers
Problem Description : Given two integers M and N, find the GCD (Greatest Common Divisor)/ HCF
(Highest Common Factor) of the two given integers
*/

#include <iostream>
using namespace std;

/*
Intuition : Use Euclidean algorithm to find GCD
GCD(a, b) = GCD(a-b, b) where a >= b
GCD(a, b) = GCD(a, b-a) where b >= a
until one of the numbers become zero, the other number is GCD

Time Complexity : O(log(min(m, n)))
Aux. Space Req. : O(1)
*/

int gcd(int m, int n)
{
    while (n != 0)
    {
        int r = m % n;
        m = n;
        n = r;
    }
    return m;
}

int main()
{
    int m = 6765, n = 10945;

    cout << "The GCD of " << m << " and " << n << " : " << gcd(m, n);

    return 0;
}