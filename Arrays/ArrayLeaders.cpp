#include <iostream>
using namespace std;

/*
Program Name : Array Leaders
Program Description : Find all the leaders in an array
Leader : An element of array is said to be a leader when all elements to its right are smaller than itself
Note : The last element of array is always a leader
*/

void display(vector<int> &arr)
{
    for(auto x : arr)
    {
        cout << x << ' ';
    }
    cout << endl;
}


/*
1. Algorithm Used : Brute Force
   Time Complexity : O(N^2)
   Auxiliary Space Requirement : O(1)
   Intuition : Check every element ahead of current element
*/
vector<int> arrayLeaders1(vector<int> &arr)
{
    vector<int> result;
    int n = arr.size();
    for(int i=0; i<n; i++)
    {
        bool flag = false;
        for(int j=i+1; j<n; j++)
        {
            if(arr[j] >= arr[i])
            {
                flag = true;
                break;
            }
        }
        if(flag == false)
        {
            result.push_back(arr[i]);
        }
    }
    return result;
}

/*
2. Algorithm Used : Optimal
   Time Complexity : O(2N)
   Auxiliary Space Requirement : O(1)
   Intuition : Start from right , find max element , every max element is a leader
*/
vector<int> arrayLeaders2(vector<int> &arr)
{
    int n = arr.size();
    vector<int> result;
    int MAX = INT_MIN;
    for(int i=n-1; i>=0; i--)
    {
        if(arr[i] > MAX)
        {
            MAX = max(arr[i], MAX);
            result.push_back(MAX);
        }
    }
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    vector<int> arr = {10,22,12,3,0,6};
    display(arr);

    vector<int> leaders = arrayLeaders2(arr);
    display(leaders);

    return 0;
}