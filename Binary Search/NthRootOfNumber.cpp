/*

Program Name : Return nth root of m
Program Description : Given integers n and m , return nth root of m
if  the nth root of m is not an integer return -1;

*/

#include <iostream>
using namespace std;

long long power(int x, int exp)
{
    if (exp == 0)
        return 1;

    long long A = power(x, exp / 2);

    if (exp % 2 != 0)
    {
        return x * A * A;
    }

    else
    {
        return A * A;
    }
}

/*

1. Algorithm Used : Binary Search
   Time Complexity : O(log n . log m) = O(log[n+m])
   Auxiliary Space Requirement : O(1)
   Intuition : Use power function to find the exponentiation, check if its equal to m
   use binary search technique to eliminate lower or higher parts

*/

long long nthRoot(int n, int m)
{
    if (n == 1)
        return m;

    else if (m == 1)
        return m;
    int low = 0, high = m / 2;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        int value = power(mid, n);

        if (value == m)
        {
            return mid;
        }

        else if (value < m)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int n = 5;
    int m = 32;

    cout << nthRoot(n, m) << endl;

    cout << power(10,20) << endl;

    return 0;
}