/*
Problem Name : Subsets 2
Problem Description : Given an array of integers (may contain duplicates). Find all the unique
subsets/subsequences which can be made by using the elements of array
*/
#include <iostream>
using namespace std;

void display(vector<int> &arr)
{
    if (arr.empty())
    {
        cout << "{}" << endl;
        return;
    }
    for (auto x : arr)
    {
        cout << x << ' ';
    }
    cout << endl;
}

void display(vector<vector<int>> &subsequences)
{
    int count = 1;
    for (auto subsequence : subsequences)
    {
        cout << count++ << " : ";
        display(subsequence);
    }
}

/*
Intuition : Start from subsequence of size = 0 , empty subsequence, for every recursive call,
push the subseq of size+1 in the ans
For every index i , use the concept of pick and not pick to generate subsequence
do this for all elements from index till last index

Sort the array , and use the duplicate checking condition to avoid duplicates
*/

void f(int index, vector<int> &arr, vector<int> &currSubseq, vector<vector<int>> &ans)
{
    // step 1: Push the subseq of size = index in the ans
    ans.push_back(currSubseq);

    for (int i = index; i < arr.size(); i++)
    {
        if (i > index && arr[i] == arr[i - 1])
            continue; // avoid duplicates condition

        // step 2:  Pick up the curr index element (make subsequence of size index+1)
        currSubseq.push_back(arr[i]);

        // step 3: Move ahead to find other unique subsequences
        f(i + 1, arr, currSubseq, ans);

        // step 4: While backtracking , remove the picked up element in step 2 to generate other
        // subsequences
        currSubseq.pop_back();
    }
}

vector<vector<int>> getUniqueSubsets(vector<int> &arr)
{
    vector<vector<int>> ans;
    vector<int> currSubseq;

    // Sort the array for optimal algorithm to work , to avoid duplicates
    sort(arr.begin(), arr.end());

    // Call the function

    f(0, arr, currSubseq, ans);

    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3, 2, 3, 2};

    cout << "Array : ";
    display(arr);

    vector<vector<int>> subsequences = getUniqueSubsets(arr);

    cout << "Subsequences : " << endl;
    display(subsequences);

    return 0;
}
