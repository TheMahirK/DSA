/*
Problem Name : Strong Number
Problem Description : Given a positive integer number, check whether the number is a strong number
or not

Definition : A number can be said as a strong number if the sum of factorials of its digits equals the
number itself

for ex.: 145 is a strong number
its digits are 1, 4 and 5
their factorials are 1 , 24 and 120 respectively
the sum of the factorials = 1 + 24 + 120 = 145
*/

#include <iostream>
using namespace std;

/*
Intuition : Find the digits by continuously taking modulus with 10 and dividing by 10 after taking
modulus, find the factorials of the digits and add them into a sum variable
If sum == original number , return true, otherwise return false

Time Complexity : O(Log_10(N))
Aux. Space Req. : O(1)
*/
bool isStrongNumber(int n)
{
    if (n == 0)
    {
        return false;
    }

    // Store the factorials from 0 to 9 , instead of calculating every time
    vector<int> facotrial = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

    int copy = n;
    int sum = 0;

    while (n != 0)
    {
        int digit = n % 10;
        sum += facotrial[digit];
        n = n / 10;
    }
    return (sum == copy);
}

int main()
{
    int n = 1;

    if (isStrongNumber(n))
    {
        cout << n << " is a Strong Number";
    }
    else
    {
        cout << n << " is NOT a Strong Number";
    }

    return 0;
}
