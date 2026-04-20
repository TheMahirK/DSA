/*

Program Name : Median of two sorted arrays
Program Description : Given two sorted arrays of any size n and m , n,m >= 0
Goal is to find the median of combination both sorted arrays in sorted order
Median : middle value of all elements

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

1. Algorithm Used : Brute force / Obvious
   Time Complexity : O(n + m)
   Auxiliary Space Requirement : O(1)
   Intuition : Use the algorithm merge used in merge sort, and check for median condition
   If total combined elements are even , median is average of two middle values

*/

double getMedian1(vector<int> &arr1, vector<int> &arr2)
{
    int n1 = arr1.size();
    int n2 = arr2.size();
    int n = n1 + n2;
    int ind1 = (n / 2), ind2 = (n / 2) - 1;
    int ele1 = -1, ele2 = -1;

    int i = 0, j = 0, count = 0;

    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            if (count == ind1)
            {
                ele1 = arr1[i];
            }
            if (count == ind2)
            {
                ele2 = arr1[i];
            }
            count++;
            i++;
        }

        else
        {
            if (count == ind1)
            {
                ele1 = arr2[j];
            }
            if (count == ind2)
            {
                ele2 = arr2[j];
            }
            count++;
            j++;
        }
    }

    while (i < n1)
    {
        if (count == ind1)
        {
            ele1 = arr1[i];
        }
        if (count == ind2)
        {
            ele2 = arr1[i];
        }
        count++;
        i++;
    }

    while (j < n2)
    {
        if (count == ind1)
        {
            ele1 = arr2[j];
        }
        if (count == ind2)
        {
            ele2 = arr2[j];
        }
        count++;
        j++;
    }

    if (n % 2 == 1)
    {
        return ele1;
    }
    return (double)(double(ele1 + ele2) / 2.0);
}

/*

2. Algorithm Used : Optimal
   Time Complexity : O(log[min(m,n)])
   Auxiliary Space Requirement : O(1)
   Intuition : Apply binary search on smaller array to partition both arrays
   such that left half has equal elements and all left elements are <= right elements.
   If partition is valid, compute median using boundary elements.
   Otherwise adjust search space.

*/

double getMedian2(vector<int> &arr1, vector<int> &arr2)
{
    int n1 = arr1.size(), n2 = arr2.size();
    if (n1 > n2)
    {
        return getMedian2(arr2, arr1);
    }

    int n = n1 + n2, low = 0, high = n1;
    int left = (n1 + n2 + 1) / 2;

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
            if (n % 2 == 1)
            {
                return max(l1, l2);
            }
            return ((double)(max(l1, l2) + min(r1, r2)) / 2.0);
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

    double median = getMedian2(arr1, arr2);

    cout << "Median of Array1 and Array2 : " << median;

    return 0;
}