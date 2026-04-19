#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &arr, int k)
{
    int left = 0;
    int right = arr.size()-1;
    int ans = -1;
    while(left <= right)
    {
        int mid = left + ((right-left)/2);

        if(arr[mid] == k)
        {
            ans = mid;
            right = mid-1;
        }

        if(k < arr[mid])
        {
            right = mid-1;
        }

        else if(k > arr[mid])
        {
            left = mid+1;
        }

    }

    return ans;
}

int main()
{
    vector<int> v = {1,2,3,4,5,5};
    int k = 5;
    int index = binarySearch(v, k);
    if(index >= 0)
    {
        cout << k << " found at index : " << index;
    }
    else
    {
        cout << k << " not found";
    }


    return 0;
}