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

bool search(vector<int>& arr, int x)
{
    int n = arr.size();
    int low = 0, high = n-1;

    while(low <= high)
    {
        int mid = (high + (low-high)/2);
        if(arr[mid] == x)
        {
            return true;
        }

        if(arr[low] == arr[mid] && arr[mid] == arr[high])
        {
            low++;
            high--;
            continue;
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
    return false;
}

int main()
{
    vector<int> arr = {4,5,6,6,7,0,1,2,4,4};
    display(arr);

    for(int i=0; i<arr.size(); i++)
    {

        
        int x = arr[i];
        bool result = search(arr, x);

        if(result)
        {
            cout << x << " is present in the array" << endl;
        }

        else
        {
            cout << x << " is NOT present in the array" << endl;
        }
    }
    return 0;
}