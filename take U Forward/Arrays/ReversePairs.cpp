/*

Program Name : Reverse Pairs
Program Description : Find count of all reverse pairs in a given array

A reverse pair is a pair (a[i],a[j]) where i < j and a[i] > 2*a[j]

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

int reversePairs1(vector<int> &arr)
{
    int count = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        long long ele1 = arr[i];

        for (int j = i + 1; j < n; j++)
        {
            long long ele2 = arr[j];
            ele2 = 2 * ele2;

            if (ele1 > ele2)
            {
                count++;
            }
        }
    }

    return count;
}

int countPairs(vector<int> &arr, int low, int mid, int high);
void merge(vector<int> &arr, int low, int mid, int high);
int mS(vector<int> &arr, int low, int high);
int mergeSort(vector<int> &arr);



/*
2. Algorithm Used : Optimal
   Time Complexity : O(N log N)
   Auxiliary Space Requirement : O(N), if we dont want to alter the original array then O(2N) 
   Note : the Extra O(N) in above is for copy array in case we dont want to alter original array
   Intuition : Use merge sort concept , count all the reverse pairs in divided array using two
   pointer approach
*/

int reversePairs2(vector<int> &arr)
{
    vector<int> copyArr(arr.begin(), arr.end());
    int n = arr.size();
    return mergeSort(copyArr);
}

void merge(vector<int> &arr, int low, int mid, int high)
{
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
}

int countPairs(vector<int> &arr, int low, int mid, int high)
{
    int count = 0;
    int right = mid + 1;

    for (int i = low; i <= mid; i++)
    {
        while (right <= high && arr[i] > 2 * arr[right])
        {
            cout << arr[i] << ',' << arr[right] << endl;
            right++;
        }
        count += (right - (mid + 1));
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
    count += countPairs(arr, low, mid, high);
    merge(arr, low, mid, high);

    return count;
}

int mergeSort(vector<int> &arr)
{
    int n = arr.size();

    return mS(arr, 0, n - 1);
}

int main()
{

    vector<int> arr = {40, 25, 19, 12, 9, 6, 2};
    display(arr);

    int reversePairs = reversePairs2(arr);

    cout << "No. of Reverse Pairs : " << reversePairs << endl;

    display(arr);

    return 0;
}