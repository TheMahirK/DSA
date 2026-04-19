/*

Program Name : Search in sorted and rotated array
Program Description : Given a sorted and rotated array and an element x, find the
index of x in array , if not found , return -1

*/
#include <iostream>
using namespace std;

void display(vector<int>& arr)
{
    for(auto x : arr)
    {
        cout << x << ' ';
    }
    cout << endl;
}

/*

1. Algorithm Used : Modified Binary Search
   Time Complexity : O(log(N))
   Auxiliary Space Requirement : O(1) 
   Intuition : Check if left half is sorted and element is present in left half or right half
   Else right half is sorted , check element is present in left half or right half

*/

int search(vector<int>& arr, int x)
{
    int n = arr.size();
    int low = 0, high = n-1;

    while(low <= high)
    {
        int mid = (high + (low-high)/2);
        if(arr[mid] == x)
        {
            return mid;
        }

        // Left half is sorted

        if(arr[low] <= arr[mid])
        {
            // element is present in left half
            if(arr[low] <= x && x <= arr[mid])
            {
                high = mid-1;
            }

            // element is not present in left half
            else
            {
                low = mid+1;
            }
        }

        // right half is sorted
        else
        {
            // element is present in right half
            if(arr[mid] <= x && x <= arr[high])
            {
                low = mid+1;
            }

            // element is not present in right half
            else
            {
                high = mid-1;
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {6,7,8,9,0,1,2,3,4,5};
    display(arr);

    int x = 6;
    int index = search(arr, x);

    if(index >= 0)
    {
        cout << x << " is present at index " << index << endl;
    }

    else
    {
        cout << x << " is not present in array" << endl;
    }

    return 0;
}