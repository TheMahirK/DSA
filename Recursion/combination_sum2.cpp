#include <iostream>
#include <vector>
using namespace std;

void findCombination(int ind, vector<int> &arr, int target, vector<int> &subArr,
vector<vector<int>> &ans)
{

    if(target == 0)
    {
        ans.push_back(subArr);
        return;
    }

    for(int i=ind; i<arr.size(); i++)
    {
        if(i>ind && arr[i] == arr[i-1])     continue;
        if(arr[i] > target)         break;

        subArr.push_back(arr[i]);
        findCombination(i+1,arr,target-arr[i],subArr,ans);
        subArr.pop_back();
    }


}

vector<vector<int>> combinationSum2(int ind, vector<int> &arr,int target)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    vector<int> subArr;

    
    findCombination(0,arr,target,subArr,ans);
    return ans;
}

int main()
{
    vector <int> arr = {5,1,2,3,4};
    int target = 5;
    vector<int> subArr;

    vector<vector<int>> result = combinationSum2(0,arr,target);
    for(int i=0; i<result.size(); i++)
    {
        for(int j=0; j<result[i].size(); j++)
        {
            cout << result[i][j] << ' ';
        }
        cout << endl;
    }


    return 0;
}