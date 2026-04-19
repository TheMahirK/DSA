/*

Program Name : Count Inversions
Program Description : Find count of all inversions in a given array

An inversion is a pair (a[i],a[j]) where i < j and a[i] > a[j]

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
   Time Complexity : O(N^2)
   Auxiliary Space Requirement : O(1)
   Intuition : Use nested loops to find all the reverse pairs , increase count as per condition
*/

int countInversions1(vector<int> &arr)
{
    int count = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                count++;
            }
        }
    }

    return count;
}


/*
2. Algorithm Used : Optimal
   Time Complexity : O(N log N)
   Auxiliary Space Requirement : O(N) (if we dont want to alter original array then O(2N))
   Intuition : Use merge sort concept , apply 2 pointer approach while merging
   to get this optimal solution, we need sorted arrays , we can integrate this concept in merge sort
*/

int merge(vector<int> &arr, int low, int mid, int high);
int mS(vector<int> &arr, int low, int high);
int mergeSort(vector<int> &arr);

int countInversions2(vector<int> &arr)
{
    vector<int> copyArr(arr.begin(), arr.end());
    return mergeSort(copyArr);
}

int merge(vector<int> &arr, int low, int mid, int high)
{
    int count = 0;
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            count += (mid-left+1);
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
    return count;
}

int mS(vector<int> &arr, int low, int high)
{
    int count = 0;
    if (low >= high)
    {
        return count;
    }
    int mid = (low + high) / 2;
    count += mS(arr, low, mid);
    count += mS(arr, mid + 1, high);
    count += merge(arr, low, mid, high);
    return count;
}

int mergeSort(vector<int> &arr)
{
    int n = arr.size();
    return mS(arr, 0, n - 1);
}



int main()
{
    vector<int> arr = {5, 3, 2, 4, 1};
    display(arr);


    cout << "No. of Inversions : " <<countInversions2(arr) << endl;

    display(arr);

    return 0;
}