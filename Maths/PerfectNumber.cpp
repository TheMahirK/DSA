/*
Problem Name : Perfect Number
Problem Description : Given a positive integer number, check whether the number is a perfect number
or not

Definition : A number can be said a perfect number if sum of all of its positive divisors, excluding the
number itself is equal to the number itself

for ex. 6 is a perfect number
divisors of 6 are 1, 2, 3
1 + 2 + 3 = 6
*/
#include <iostream>
using namespace std;

/*
Intuition : Check for divisors from 1 to sqrt(n) and add divisors to sum, then check for perfect number
condition
Here we start from 2 because we already know 1 divides every number, and this way we dont include the
number itself also in the sum

Time Complexity : O(sqrt(N))
Aux. Space Req. : O(1)
*/
bool isPerfectNumber(int n)
{
    if (n == 1)
        return false;
    int sum = 1;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            sum += i;
            if (n / i != i)
            {
                sum += n / i;
            }
        }
    }
    return (sum == n);
}

int main()
{
    int n = 6;

    bool isPerfect = isPerfectNumber(n);

    if (isPerfect)
    {
        cout << n << " is a Perfect Number";
    }
    else
    {
        cout << n << " is NOT a Perfect Number";
    }

    return 0;
}