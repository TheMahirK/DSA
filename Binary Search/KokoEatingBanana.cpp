/*

Program Name : Koko Eating Bananas
Program Description : Given array Piles and hours, every element of Piles is a Pile
calculate the minimum eating speed that all bananas can be eaten in 
less or equal hours

Note : Koko can eat bananas in fixed time intervals and fixed piles only
and cannot jump to next pile until the interval is over

*/


#include <iostream>
#include <cmath>
using namespace std;

void display(vector<int> &arr)
{
    for (auto x : arr)
    {
        cout << x << ' ';
    }
    cout << endl;
}



int totalHours(vector<int> &piles, int hourly)
{
    int total = 0;

    for (int i = 0; i < piles.size(); i++)
    {
        total += ceil((double)piles[i] / hourly);
    }
    return total;
}

/*

1. Algorithm Used : Brute Force
   Time Complexity : O(N * max(piles)), N = piles.size()
   Auxiliary Space Requirement : O(1)
   Intuition : The maximum bananas can be eaten is max of piles, and minimum banana can be eaten
   is 1. Start from 1 to max(piles) and calculate required hours for each, if at any point
   the required time is less than or equal to given hours , we find the minimum eating speed

*/

int minEatingSpeed(vector<int> &piles, int hours)
{
    int maxEle = piles[0];
    int n = piles.size();

    for (int i = 1; i < n; i++)
    {
        if (piles[i] > maxEle)
        {
            maxEle = piles[i];
        }
    }

    for (int i = 1; i <= maxEle; i++)
    {
        int reqHours = totalHours(piles, i);
        if (reqHours <= hours)
        {
            return i;
        }
    }
    return -1;
}


/*

1. Algorithm Used : Optimal, Binary Search
   Time Complexity : O(N * log(max)), N = piles.size(), max = max(piles);
   Auxiliary Space Requirement : O(1)
   Intuition : Use binary search to narrow down the eating speed

*/

int minEatingSpeed2(vector<int> &piles, int hours)
{
    int n = piles.size();
    int max = piles[0];

    for (int i = 1; i < n; i++)
    {
        if (piles[i] > max)
        {
            max = piles[i];
        }
    }

    int low = 1, high = max;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        int reqTime = totalHours(piles, mid);

        if (reqTime == hours)
        {
            return mid;
        }

        else if (reqTime < hours)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

int main()
{
    vector<int> pilesOfBananas = {3, 6, 7, 11};
    display(pilesOfBananas);

    int hours = 8;

    int minSpeed = minEatingSpeed2(pilesOfBananas, hours);
    cout << minSpeed << endl;

    return 0;
}