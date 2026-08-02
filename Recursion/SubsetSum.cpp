/*
Problem Name : Subset Sum
Problem Description : Given an array of integers, find the sum of each possible subset from elements of
array, return all the subset sums in increasing order
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
Intuition : Use pick and not pick approach to visit all the subsequences, keep a sum variable to store
the subset sum. When picking up an element, add it to sum and move ahead for next indexes.
When not picking the element, do not add it to sum and move ahead for next indexes

Time Complexity : O(N * 2^N)
Aux. Space Req. : O(N) for subsequences
2^N for returning output
*/

void f(int index, vector<int> &arr, int currSum, vector<int> &ans)
{
    // Base case
    if (index == arr.size())
    {
        ans.push_back(currSum);
        return;
    }

    // Pick the current index element and move ahead
    f(index + 1, arr, currSum + arr[index], ans);

    // Do not pick the current index element and move ahead
    f(index + 1, arr, currSum, ans);
}

vector<int> subsetSum(vector<int> &arr)
{
    vector<int> ans;
    int currSum = 0;

    f(0, arr, currSum, ans);

    sort(ans.begin(), ans.end());

    return ans;
}

int main()
{
    vector<int> arr = {1, 3, 2};

    cout << "Array : ";
    display(arr);

    vector<int> subsetSums = subsetSum(arr);
    cout << "Subset sums : ";
    display(subsetSums);

    return 0;
}