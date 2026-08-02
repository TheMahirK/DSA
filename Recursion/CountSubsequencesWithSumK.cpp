/*
Problem Name : Count subsequences with sum K
Problem Description : Given an array and an integer K, find the total number of subsequences whose
sum == k
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
Intuition : Use 1. pick (add sum)
2. not pick (subtract from sum)
To find all the subsequences 
In base case return 1 if condition is satisfied, return 0 if not
do this recursively for all the subsequences, return total in end

Time Complexity : O(2^N)
Aux. Space Req. : O(2^N)
*/

int f(int index, vector<int> &arr, int sum, int k)
{
    // Base case

    if(index >= arr.size())
    {
        // condition satisfied
        if(sum == k)
        {
            return 1;
        }

        // condition not satisfied
        return 0;
    }

    // Pick condition
    sum += arr[index];

    // Pick and move ahead
    int left = f(index+1, arr, sum, k);

    // Not pick condition
    sum -= arr[index];

    // Do not pick and move ahead
    int right = f(index+1, arr, sum, k);

    return left + right;
}

int countSubsequences(vector<int> &arr, int k)
{
    int sum = 0;
    return f(0, arr, sum, k);
}

int main()
{
    vector<int> arr = {1,2,3,4,5,6,7};
    int k = 7;

    int count = countSubsequences(arr, k);

    cout << count;

    return 0;
}