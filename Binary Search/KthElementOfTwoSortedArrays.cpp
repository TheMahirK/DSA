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

int main()
{

    vector<int> arr1 = {1, 2, 4, 8, 16, 32};
    vector<int> arr2 = {1, 3, 9, 27, 81};

    cout << "Array1 : ";
    display(arr1);
    cout << "Array2 : ";
    display(arr2);

    int k = 10;
    int kthEle = kthElement1(arr1, arr2, k);
    cout << k << "th Element after sorted combination of Arr1 and Arr2 : " << kthEle;

    return 0;
}