#include <iostream>
using namespace std;

void display(vector<vector<int>> &subsequences)
{
    int count = 1;
    for(auto subsequence : subsequences)
    {
        cout << count++ << " : ";
        if(subsequence.empty())
        {
            cout << "{}" << endl;
            break;
        }
        for(auto x : subsequence)
        {
            cout << x << ' ';
        }   
        cout << endl;
    }
}

void subsequence(int index, vector<int> &arr, vector<int> &currSubsequence,vector<vector<int>> &ans)
{
    if(index >= arr.size())
    {
        ans.push_back(currSubsequence);
        return;
    }

    //1. Pick the current index element
    currSubsequence.push_back(arr[index]);

    //2. Go to next index and repeat from step 1
    subsequence(index+1, arr, currSubsequence, ans);

    //3. Remove current index element
    currSubsequence.pop_back();

    //4. Go to next index and repeat from step 1
    subsequence(index+1, arr,currSubsequence, ans);
}

vector<vector<int>> getSubsequences(vector<int> &arr)
{
    vector<vector<int>> ans;
    vector<int> currSubsequence;
    subsequence(0, arr, currSubsequence, ans);
    return ans;
}

int main()
{
    vector<int> arr = {1,2,3};

    vector<vector<int>> ans = getSubsequences(arr);

    display(ans);
    
    return 0;
}