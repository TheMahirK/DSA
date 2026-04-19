/*

Program Name : Find Kth Missing Positive Integer
Program Description : Given a sorted array, but some numbers are missing (numbers are not
continuous). Given a number K , find the Kth missing number in array.

Note : The missing number can be outside of array too (left of 0th index and right of (n-1)th index


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

1. Algorithm Used : Better/Brute Force
   Time Complexity : O(N)
   Auxiliary Space Requirement : O(1)
   Intuition : We assume the answer is k at first. (When array is empty Kth missing number is K)
   Then for every number in the array that is ≤ k, we move k forward by 1 because
   that number is not missing.

*/

int findKthMissingNumber1(vector<int> &arr, int k)
{
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= k)
        {
            k++;
        }
        else
        {
            break;
        }
    }
    return k;
}

/*

2. Algorithm Used : Optimal
   Time Complexity : O(log N)
   Auxiliary Space Requirement : O(1)
   Intuition : We use binary search to find the point where k missing numbers are reached,
   by counting missing numbers at each position.
   Missing Number is arr[high] + more
   more = k - missing = k - (arr[mid] - mid - 1) = k-arr[mid]+mid+1

   at end , mid = high

   missing number = arr[high] + k - arr[high] + high + 1 = high+1+k

*/

int findKthMissingNumber2(vector<int> &arr, int k)
{
    int n = arr.size();
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + (high - low) / 2);
        int missing = arr[mid] - (mid + 1);

        // Missing number is in right side
        if (missing < k)
        {
            low = mid + 1;
        }

        // Missing number is in left side
        else
        {
            high = mid - 1;
        }
    }
    // Missing number is (K+1) numbers ahead than high

    return (high + 1 + k);
}

int main()
{
    vector<int> arr = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    display(arr);

    int k = 10;

    int kthMissingNumber = findKthMissingNumber2(arr, k);

    cout << k << "th missing number is : " << kthMissingNumber;

    return 0;
}