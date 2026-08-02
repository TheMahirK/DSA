/*
Problem Name : Subsequences with sum K
Problem Description : Given an array of +ve integers and an integer k, find all the subsequences
whose sum is equal to k
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
Intuition : Use the concept of 1. pick and 2. not pick (pick and then remove) to generate all subsequences
keep a sum variable to store sum, if at any point sum equals k, we push that subsequence in our answer
when doing step 2. not pick, we subtract the element from sum so that way we dont pick in subseq. and
sum also

Do this recursively to get all possible subsequences and all valid subsequences that satisfy condition 
of sum == k

Time Complexity : O(2^N) 
The total number of ordered subsequences possible for array of size N = 2^N

Aux. Space Req. : O(2^N)

*/
int steps = 0;
void f(int index, vector<int> &arr, vector<int> &subseq, int k, int sum, vector<vector<int>> &ans)
{
    steps++;
    if(index >= arr.size())
    {
        if(sum == k)
        {
            ans.push_back(subseq);
        }
        return;
    }

    subseq.push_back(arr[index]);
    sum += arr[index];

    f(index+1, arr, subseq, k, sum, ans);

    subseq.pop_back();
    sum -= arr[index];
    
    f(index+1, arr, subseq, k, sum, ans);
}

vector<vector<int>> subsequencesWithSumK(vector<int> &arr, int k)
{
    int sum = 0;
    vector<int> subseq;
    vector<vector<int>> ans;
    f(0, arr, subseq, k, sum, ans);

    return ans;
}

int main()
{
    vector<int> arr = {1,2,3,4,5,6,7};

    int k = 7;

    vector<vector<int>> ans = subsequencesWithSumK(arr, k);

    cout << "steps : " << steps << endl;
    for(auto subseq : ans)
    {
        display(subseq);
    }

    return 0;
}