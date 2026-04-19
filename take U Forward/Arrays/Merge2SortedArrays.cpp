/*
Program Name : Merge two sorted arrays 
Program Description : Merge two sorted arrays , such that each array is sorted and 
both arrays combined is also sorted (without using extra space)
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
   Time Complexity : O(2(m+n))
   Auxiliary Space Requirement : O(m+n)
   Intuition : Compare element by element and insert in arr3 as per condition
   use two pointers one for each array
*/

void merge2SortedArrays1(vector<int> &arr1, vector<int> &arr2)
{
    int m = arr1.size();
    int n = arr2.size();
    // int s = max(m,n);
    int i = 0, j = 0;
    vector<int> arr3;
    for (int k = 0; k < m + n; k++)
    {
        if (arr1[i] <= arr2[j] && i < m)
        {
            arr3.push_back(arr1[i]);
            i++;
        }
        else if (j < n)
        {
            arr3.push_back(arr2[j]);
            j++;
        }
    }
    while (i < m)
    {
        arr3.push_back(arr1[i]);
        i++;
    }
    while (j < n)
    {
        arr3.push_back(arr2[j]);
        j++;
    }

    for (int i = 0; i < m + n; i++)
    {
        if (i > m)
        {
            arr2[i - m] = arr3[i];
        }
        else
        {
            arr1[i] = arr3[i];
        }
    }
}

/*
2. Algorithm Used : Optimal
   Time Complexity : O((m+n)+(mlogm + nlogn))
   Auxiliary Space Requirement : O(1)
   Intuition : Compare elements of both arrays, if any element of arr2 is smaller than the
   last (or largest) element of arr1 , swap them, and continue the same process for 
   second last (or second largest) element and so on
*/


void merge2SortedArrays2(vector<int> &arr1, vector<int> &arr2)
{
    int m = arr1.size();
    int n = arr2.size();

    int left = m - 1;
    int right = 0;

    while (left >= 0 && right < n)
    {
        if (arr2[right] < arr1[left])
        {
            swap(arr1[left], arr2[right]);
            left--;
            right++;
        }
        else
        {
            break;
        }
    }

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
}

/*
3. Algorithm Used : Optimal
   Time Complexity : O((m+n)+(log(m+n)))
   Auxiliary Space Requirement : O(1)
   Intuition : Use gap method (shell sort)
*/


void swapIfGreater(vector<int> &arr1, vector<int> &arr2, int ind1, int ind2)
{
    if (arr1[ind1] > arr2[ind2])
    {
        swap(arr1[ind1], arr2[ind2]);
    }
}

void merge2SortedArrays3(vector<int> &arr1, vector<int> &arr2)
{
    int m = arr1.size();
    int n = arr2.size();
    int len = (m + n);
    int gap = (len / 2) + (len % 2);

    while (gap > 0)
    {
        int left = 0;
        int right = left+gap;

        while (right < len)
        {
            // arr1 and arr2
            if (left < m && right >= m)
            {
                swapIfGreater(arr1,arr2,left,right-m);
            }
            // arr2 and arr2

            else if (left >= m)
            {
                swapIfGreater(arr2,arr2,left-m,right-m);
            }

            // arr1 and arr1
            else
            {
                swapIfGreater(arr1,arr1,left,right);
            }
            left++;
            right++; 
        }
        if(gap == 1)    break;

        gap = (gap/2)+(gap%2); 

    }
}

int main()
{
    vector<int> arr1 = {1, 3, 7, 9};
    vector<int> arr2 = {0, 2, 4, 5, 6, 8};

    display(arr1);
    display(arr2);

    merge2SortedArrays3(arr1, arr2);

    display(arr1);
    display(arr2);

    return 0;
}