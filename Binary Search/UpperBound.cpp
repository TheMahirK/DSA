/*

Program Name : Lower Bound
Program Description : Given a sorted array and a target value , find the lowest index in array
such that arr[index] > target
If no such index exists in array then return the lowest hypothetical index where the element
arr[index] > target would exist

*/

#include <iostream>
using namespace std;

void display(vector<int> &arr)
{
    for(auto x : arr)
    {
        cout << x << ' ';
    }
    cout << endl;
}

/*
1. Algorithm Used : Optimal
   Time Complexity : O(log N)
   Auxiliary Space Requirement : O(1)
   Intuition : Since the array is sorted , we can use binary search and update the answer accordingly
*/

int upperBound(vector<int> &arr, int target)
{
    // this is the short code with same implementation, just using built in functions
    // return upper_bound(arr.begin(), arr.end(),target)-arr.begin();

    int n = arr.size();
    int low = 0, high = n-1;
    int ans = n;

    while(low <= high)
    {
        int mid = (high+(low-high)/2);
        
        if(arr[mid] > target)
        {
            ans = mid;
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }

    }

    return ans;
}

int main()
{
    vector<int> arr = {1,2,3,6,7,8,16,17,18,36,37,38};
    display(arr);

    int x = 8;

    cout << arr[upperBound(arr, x)] << endl;


    return 0;
}