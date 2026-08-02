/*
Problem Name : Combination Sum
Problem Description : Given an array and an integer target, find all the possible combinations possible
in the array whose sum == target
Note : A single array element can be used multiple times
e.g. arr = [1,2,3], target = 8
valid combinations are [1,1,1,1,1,1,1,1],[2,2,2,2],[2,3,3]......
*/
#include <iostream>
using namespace std;

/*
Intuition : Use pick and not pick concept to find all the possible subsequences

1. If element <= target , we pick it and reduce target for next recursive call, and do not go ahead , as we can use same element
multiple times
2. When coming back from recurive call of pick conditon , we remove the picked element for next combination
3. Otherwise we do not pick element, move to next index , and do not reduce target
4. When we picked
*/

void display(vector<int> &arr)
{
    for (auto x : arr)
    {
        cout << x << ' ';
    }
    cout << endl;
}

void f(int index, vector<int> &arr, int target, vector<int> &currSubseq, vector<vector<int>> &ans)
{
    // Base case
    if (index >= arr.size())
    {
        // Condition satisfied
        if (target == 0)
        {
            ans.push_back(currSubseq);
        }
        return;
    }

    // Pick conditon
    if (arr[index] <= target)
    {
        currSubseq.push_back(arr[index]);
        f(index + 1, arr, target - arr[index], currSubseq, ans);

        // Remove the picked element for next subseq
        currSubseq.pop_back();
    }

    // Do not pick and move ahead
    f(index + 1, arr, target, currSubseq, ans);
}

vector<vector<int>> combinationSum(vector<int> &arr, int target)
{
    vector<vector<int>> ans;
    vector<int> currSubseq;

    f(0, arr, target, currSubseq, ans);

    return ans;
}

void display(vector<vector<int>> &subsequences)
{
    for (auto subsequence : subsequences)
    {
        display(subsequence);
    }
}

int main()
{
    vector<int> arr = {2, 3, 4, 5, 6};

    cout << "Array : ";
    display(arr);

    int target = 8;
    cout << "Target : " << target << endl;

    cout << "Combinations : " << endl;
    vector<vector<int>> ans = combinationSum(arr, target);

    display(ans);

    return 0;
}