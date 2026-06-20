#include<iostream>
using namespace std;

/*
Program Name : Next Permutation
Program Description : Find the next Lexicographical permutation
*/

/*
1. Algorithm Used : Brute Force
   Time Complexity : O(N! * N)
   Auxiliary Space Requirement : O(N! * N)
   Intuition : Generate All permutations , sort them, linear search, return the next permutation
*/

void permutations(vector<int> &arr, vector <int> &subArr,
vector<vector<int>> &result, int freq[])
{
    if(subArr.size()==arr.size())
    {
        result.push_back(subArr);
        return;
    }
    for(int i=0; i<arr.size(); i++)
    {
        if(freq[i] == 0)
        {
            subArr.push_back(arr[i]);
            freq[i] = 1;
            permutations(arr,subArr,result,freq);
            freq[i] = 0;
            subArr.pop_back();
        }
    }
}

vector<vector<int>> findPermutations(vector<int> &arr)
{
    vector<vector<int>> result;
    vector<int> subArr;
    int freq[arr.size()];
    for(int i=0; i<arr.size(); i++) freq[i] = 0;
    permutations(arr,subArr,result,freq);
    return result;

}

void display(vector<vector<int>> &arr)
{
    for(auto row : arr)
    {
        for(auto x : row)
        {
            cout << x << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

void display(vector<int> &arr)
{
    for(auto x : arr)
    {
        cout << x << ' ';
    }
    cout << endl;
}

vector<int> nextPermutation1(vector<int> &arr)
{
    vector<vector<int>> permutations = findPermutations(arr);
    sort(permutations.begin(), permutations.end());
    int n = permutations.size();
    for(int i=0; i<n; i++)
    {
        if(permutations[i] == arr && i != n-1)
        {
            while(permutations[i] == permutations[i+1] && i < n)
            {
                i++;
            }
            if(i == n-1)  return permutations[0];
            return permutations[i+1];
        }
    }
    return permutations[0];

}

// 2 0 1 5 0
// 2 0 5 1 0
// 2 0 5 0 1


/*
2. Algorithm Used : Optimal
   Time Complexity : O(3N)
   Auxiliary Space Requirement : O(1)
   Intuition : Find the longest prefix match, find break point , swap elements to get next permutation
*/


void nextPermutation2(vector<int> &arr)
{
    int n = arr.size();
    int ind = -1;
    for(int i=n-2; i>=0; i--)
    {
        if(arr[i] < arr[i+1])
        {
            ind = i;
            break;
        }
    }
    if(ind == -1)
    {
        reverse(arr.begin(), arr.end());
        return;
    }
    for(int i=n-1; i>ind; i--)
    {
        if(arr[i] > arr[ind])
        {
            swap(arr[ind], arr[i]);
            break;
        }
    }
    reverse(arr.begin()+ind+1, arr.end());
}

int main()
{

    vector<int> arr = {2,0,1,5,0};
    vector<vector<int>> permutations = findPermutations(arr);
    sort(permutations.begin(), permutations.end());
    display(permutations);

    // vector<int> result = nextPermutation2(arr);
    nextPermutation2(arr);
    display(arr);





    return 0;
}