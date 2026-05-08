/*

Problem Name : GCD of two numbers
Problem Description : Given two positive numbers M and N. Calculate the GCD of M and N

GCD : Greatest Common Divisor (also known as HCF - Highest Common Factor)
GCD of two numbers is the largest possible number which divides the both numbers perfectly

Problem Link : https://www.geeksforgeeks.org/problems/gcd-of-two-numbers3459/1

*/

#include <iostream>
using namespace std;

/*

1. Algorithm Used : Brute Force
   Time Complexity : O(min(M, N))
   Auxiliary Space Requirement : O(1)
   Intuition : The GCD lies between 1 and min(M,N), check for each value in this range in
   descending order. First value that divides both M and N is the GCD

*/
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

/*

2. Algorithm Used : Optimal
   Time Complexity : O(log[min(M, N)])
   Auxiliary Space Requirement : O(1)
   Intuition : Use Euclidean Algorithm to find the GCD

   Euclidean Algorithm says :
   Let a and b be two integers such that a≥b>0. By the Division Algorithm,
   there exist unique integers q and r satisfying
    a=bq+rwhere 0≤r<b
    Then,
    gcd(a,b)=gcd(b,r)
    This process is repeated recursively until the remainder becomes 0. If at some step,
    rn = 0
    then the GCD is the last nonzero remainder:
    gcd(a,b)=rn−1
​

*/
int gcd2(int m, int n)
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
    int m = 28;
    int n = 161;

    int gcd = gcd2(m, n);

    cout << "GCD of " << m << " and " << n << " is : " << gcd;

    return 0;
}