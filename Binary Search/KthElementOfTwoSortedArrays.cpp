/*

Program Name : Kth element of sorted combination of two sorted arrays
Program Description : Given two sorted arrays arr1 and arr2 , and an integer k.
Our goal is to find the kth element in the sorted combination of arr1 and arr2

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

1. Algorithm Used : Brute
   Time Complexity : O(n+m)
   Auxiliary Space Requirement : O(1)
   Intuition : Use similar technique as merge sort to merge arrays and keep count of how many elements
   merged. When count reaches k , we find the kth element in the sortedcombination of two sorted arrays

   Note : when k == (m+n), last element of sorted combination, we return max(last ele arr1 , last ele arr2)
   When

*/

int kthElement1(vector<int> &arr1, vector<int> &arr2, int k)
{
    int n1 = arr1.size(), n2 = arr2.size();
    int n = n1 + n2;
    if (k == n)
        return (max(arr1[n1 - 1], arr2[n2 - 1]));
    int count = 0, i = 0, j = 0;

    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            count++;
            if (count == k)
            {
                return arr1[i];
            }
            i++;
        }
        else
        {
            count++;
            if (count == k)
            {
                return arr2[j];
            }
            j++;
        }
    }

    while (i < n1)
    {
        count++;
        if (count == k)
        {
            return arr1[i];
        }
        i++;
    }

    while (j < n2)
    {
        count++;
        if (count == k)
        {
            return arr2[j];
        }
        j++;
    }

    return min(arr1[n1 - 1], arr2[n2 - 1]);
}

/*

2. Algorithm Used : Optimal
   Time Complexity : O(log[min(n,m)])
   Auxiliary Space Requirement : O(1)
   Intuition : Use binary search to split both arrays so that exactly k elements lie on the left side.
   If the split is valid (l1 <= r2 and l2 <= r1), the answer is max(l1, l2).
   Otherwise, adjust the split using binary search.


*/

int kthElement2(vector<int> &arr1, vector<int> &arr2, int k)
{
    int n1 = arr1.size(), n2 = arr2.size();
    if (n1 > n2)
    {
        return kthElement2(arr2, arr1, k);
    }

    int n = n1 + n2, low = max(0, k - n2), high = min(k, n1);
    int left = k;

    while (low <= high)
    {
        int mid1 = (low + (high - low) / 2);
        int mid2 = left - mid1;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;

        if (mid1 < n1)
            r1 = arr1[mid1];
        if (mid2 < n2)
            r2 = arr2[mid2];
        if (mid1 - 1 >= 0)
            l1 = arr1[mid1 - 1];
        if (mid2 - 1 >= 0)
            l2 = arr2[mid2 - 1];

        if (l1 <= r2 && l2 <= r1)
        {

            return max(l1, l2);
        }

        else if (l1 > r2)
            high = mid1 - 1;

        else
            low = mid1 + 1;
    }

    return 0;
}

int main()
{

    vector<int> arr1 = {1, 2, 4, 8, 16, 32};
    vector<int> arr2 = {1, 3, 9, 27, 81};

    cout << "Array1 : ";
    display(arr1);
    cout << "Array2 : ";
    display(arr2);

    int k = 10;
    int kthEle = kthElement2(arr1, arr2, k);
    cout << k << "th Element after sorted combination of Arr1 and Arr2 : " << kthEle;

    return 0;
}