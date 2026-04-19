/*

Program Name : Find Minimum no. of days required to make M bouquets from K adjacent
bloomed flowers
Program Description : Given array bloomDay which contain the bloom day of ith flower
and M = no. of bouqets required
K = no. of adjacent bloomed flowers required per bouquet

Find the minimum no. of days required to make M bouquets with K adjacent bloomed flowers

*/

#include <iostream>
using namespace std;

void display(vector<int> &arr)
{
    for (auto x : arr)
    {
        cout << x << ' ';
    }
    cout << endl;
}

bool possibleDay(vector<int> &arr, int day, int flowers, int bouquets)
{
    int n = arr.size();
    int count = 0, bouquetCount = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= day)
        {
            count++;
        }
        else
        {
            bouquetCount += (count / flowers);
            count = 0;
        }
    }
    bouquetCount += (count / flowers);

    if (bouquetCount >= bouquets)
    {
        return true;
    }
    return false;
}

/*

1. Algorithm Used : Brute force
   Time Complexity : O([arr(max) - arr(min) * N], N = arr.size()
   Auxiliary Space Requirement : O(1)
   Intuition : The range is from arr(min) to arr(max),
   check for every ith day in range if its possible to make bouquets or not
   the first answer found is the minimum no. of days

   Note : if there are less flowers than total flowers required
    (arr.size() < flowers*bouquets) its not possible to make bouquets
*/

int minDays1(vector<int> &arr, int flowers, int bouquets)
{
    int n = arr.size();

    if (n < flowers * bouquets)
    {
        return -1;
    }

    int max = arr[0], min = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }

        if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    for (int i = min; i <= max; i++)
    {
        if (possibleDay(arr, i, flowers, bouquets))
        {
            return i;
        }
    }
    return -1;
}

/*

2. Algorithm Used : Optimal
   Time Complexity : O(log (max - min) * N), N = arr.size()
   Auxiliary Space Requirement : O(1)
   Intuition : The range is from arr(min) to arr(max),
   use binary search to narrow down the range
   Note : if there are less flowers than total flowers required
    (arr.size() < flowers*bouquets) its not possible to make bouquets
*/

int minDays2(vector<int> &arr, int flowers, int bouquets)
{
    int n = arr.size();

    if (n < flowers * bouquets)
    {
        return -1;
    }

    int max = arr[0], min = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }

        if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    int low = min, high = max;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        bool possibility = possibleDay(arr, mid, flowers, bouquets);

        if (possibility)
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
    vector<int> arr = {1, 2, 3, 12, 13, 2, 3, 4, 14, 15};
    display(arr);

    int flowers = 3;
    int bouquets = 2;

    int ans = minDays2(arr, flowers, bouquets);

    if (ans != -1)
    {
        cout << "Minimum days required to make " << bouquets << " bouquets with " << flowers
             << " consecutive bloomed flowers : " << ans;
    }

    else
    {
        cout << "It is not possible to make " << bouquets << " bouquets with " << flowers
             << " consecutive bloomed flowers";
    }

    return 0;
}