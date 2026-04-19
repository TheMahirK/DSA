
/*

Program Name : Find the Smallest Divisor Given a Threshold
Program Description : Given an array and a threshold , find the smallest divisor
such that the sum of all ceil divisons of divisor with array elements is
less than or equal to the threshold

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

/*

1. Algorithm Used : Brute Force
   Time Complexity : O(N * max(arr)) , N = arr.size()
   Auxiliary Space Requirement : O(1)
   Intuition : The range for solution is 1 to max(arr), get threshold for all values in
   the range and check the condition

*/

int getThreshold(vector<int> &arr, int divisor)
{
    int totalThreshold = 0;

    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        totalThreshold += ceil((float)arr[i] / divisor);
    }

    return totalThreshold;
}

int smallestDivisor1(vector<int> &arr, int threshold)
{
    int n = arr.size();
    int min = arr[0], max = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    for (int i = 1; i <= max; i++)
    {
        int currThreshold = getThreshold(arr, i);

        if (currThreshold <= threshold)
        {
            return i;
        }
    }

    return -1;
}

/*

2. Algorithm Used : Optimal
   Time Complexity : O(N * log[max(arr)]) , N = arr.size()
   Auxiliary Space Requirement : O(1)
   Intuition : The range for solution is 1 to max(arr),
   use binary search get threshold and narrow down the range

*/

int smallestDivisor2(vector<int> &arr, int threshold)
{
    int n = arr.size();
    int min = arr[0], max = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    int low = 1, high = max;

    while (low <= high)
    {
        int mid = (low + (high - low) / 2);

        int currThreshold = getThreshold(arr, mid);

        // Decrease divisor to increase threshold
        if (currThreshold <= threshold)
        {
            high = mid - 1;
        }

        // Increase divisor to decrease threshold
        else
        {
            low = mid + 1;
        }
    }

    return low;
}

int main()
{
    vector<int> arr = {1, 2, 3, 14, 5, 16, 7, 18, 9};
    display(arr);

    int threshold = 18;

    int smallestDiv = smallestDivisor2(arr, threshold);

    cout << smallestDiv;

    return 0;
}