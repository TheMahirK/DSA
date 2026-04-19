/*

Program Name : Find the minimum capacity to ship packages within D days
Program Description : Given a ship, no. of D days and weights of the different
packages, find the minimum capacity of the ship as to deliver all the packages within
D days.

Note : The packages must be shipped in order and as a complete package (cannot be splitted)

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

int requiredDays(vector<int> &arr, int capacity, int days)
{
    int total = 0, currDays = 1;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {

        if (currDays > days)
        {
            break;
        }

        if (total + arr[i] <= capacity)
        {
            total += arr[i];
        }

        else
        {
            currDays++;
            total = arr[i];
        }
    }

    return currDays;
}

/*

1. Algorithm Used : Brute Force
   Time Complexity : O((sum-max) * N), sum = sum(arr), max = max(arr), N = arr.size()
   Auxiliary Space Requirement : O(1)
   Intuition : The capacity range is between max(arr) and sum(arr),
   Find the required days for each capacity and check for condition
   The first capacity with time less or equal to days is the minimum capacity
*/

int getWeightCapacity1(vector<int> &arr, int days)
{
    int max = arr[0];
    int sum = arr[0];
    int n = arr.size();

    for (int i = 1; i < n; i++)
    {
        sum += arr[i];
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    for (int i = max; i <= sum; i++)
    {
        int total = requiredDays(arr, i, days);

        if (total <= days)
        {
            return i;
        }
    }

    return -1;
}

/*

1. Algorithm Used : Optimal
   Time Complexity : O(log(sum-max) * N), sum = sum(arr), max = max(arr), N = arr.size()
   Auxiliary Space Requirement : O(1)
   Intuition : The capacity range is between max(arr) and sum(arr),
   use the binary search algo to narrow down the range
*/

int getWeightCapacity2(vector<int> &arr, int days)
{
    int max = arr[0];
    int sum = arr[0];
    int n = arr.size();

    for (int i = 1; i < n; i++)
    {
        sum += arr[i];
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    int low = max, high = sum;

    while (low <= high)
    {
        int mid = (low + (high - low) / 2);

        int reqDays = requiredDays(arr, mid, days);

        //  Decrease the range to find the minimum
        if (reqDays <= days)
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
    vector<int> arr = {1, 3, 7, 9, 11, 13, 15, 17, 19};
    display(arr);

    int days = 5;

    cout << getWeightCapacity1(arr, days);

    return 0;
}