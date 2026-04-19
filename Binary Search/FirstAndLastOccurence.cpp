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

vector<int> searchRange1(vector<int>& arr, int target)
{
    vector<int> result = {-1,-1};
    int n = arr.size();

    for(int i=0; i<n; i++)
    {
        if(arr[i] == target)
        {
            if(result[0] == -1)
            {
                result[0] = i;
            }

            result[1] = i;
        }
    }

    return result;
}

vector<int> searchRange2(vector<int>& arr, int target)
{
    int n = arr.size();
    int lb = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
    int ub = upper_bound(arr.begin(), arr.end(), target) - arr.begin();

    if(lb == n || arr[lb] != target)
    {
        return {-1, -1};
    }
    return {lb, ub-1};

}

vector<int> searchRange3(vector<int>& arr, int target)
{
    int n = arr.size();
    int low = 0, high = n-1;
    int first = -1, last = -1;

    while(low <= high)
    {
        int mid = (high + (low-high)/2);
        if(arr[mid] == target)
        {
            first = mid;
            high = mid-1;
        }

        else if(target < arr[mid])
        {
            high = mid-1;
        }

        else
        {
            low = mid+1;
        }

    }

    if(first == -1)
    {
        return {-1,-1};
    }

    low = 0, high = n-1;

    while(low <= high)
    {
        int mid = (high + (low-high)/2);
        if(arr[mid] == target)
        {
            last = mid;
            low = mid+1;
        }

        else if(target < arr[mid])
        {
            high = mid-1;
        }

        else
        {
            low = mid+1;
        }
    }
    return {first, last};
}



int main()
{

    vector<int> arr = {0,1,2,3,4,5,5,5,5,5,10};
    display(arr);

    int target = 5;
    vector<int> result = searchRange3(arr, target);
    display(result);

    return 0;
}