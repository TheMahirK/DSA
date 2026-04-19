#include <iostream>
#include <vector>
using namespace std;

void findCombination(int ind, int target, vector<int> &arr,
vector<int> &subArr, vector<vector<int>> &ans)
{
    if(target == 0)
    {
        ans.push_back(subArr);
        return;
    }

    for(int i=ind; i<arr.size(); i++)
    {
        if(i>ind && arr[i]==arr[i-1]) continue;
        if(arr[i]>target) break;
        subArr.push_back(arr[i]);
        findCombination(i+1,target-arr[i],arr,subArr,ans);
        subArr.pop_back();
    }

}

vector<vector<int>> combinationSum2(vector<int> &arr, int target)
{
    sort(arr.begin(),arr.end());
    vector<int> subArr;
    vector<vector<int>> ans;
    findCombination(0,target,arr,subArr,ans);
    return ans;
}

int main()
{
    vector <int> arr = {5,1,2,3,4,-1,6};
    int target = 5;
    vector<vector<int>> result;
    result = combinationSum2(arr,target);
    for(int i=0; i<result.size(); i++)
    {
        for(int j=0; j<result[i].size(); j++)
        {
            cout << result[i][j] << ' ';
        }
        cout << endl;
    }

}