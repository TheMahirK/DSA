#include <iostream>
#include <vector>
using namespace std;


void findCombination(int i, vector<int> &arr, vector<int> &subArr,
vector<vector<int>> &result, int target)
{
    if(i == arr.size())
    {
        if(target == 0)
        {
            result.push_back(subArr);
        }
        return;
    }


    // pick the element
    if(arr[i] <= target)
    {
        subArr.push_back(arr[i]);
        findCombination(i,arr,subArr,result,target-arr[i]);
        // remove the picked element
        subArr.pop_back();
    }

    // not pick the element
    findCombination(i+1,arr,subArr,result,target);

}

vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        
        vector<vector<int>> result;
        vector<int> subArr;
        findCombination(0,arr,subArr,result,target);
        return result;
        
    }

int main()
{
    vector<int> arr = {2,1,3,7};
    int target = 7;
    vector<vector<int>> res;
    res = combinationSum(arr,target);

    for(int i=0; i<res.size(); i++)
    {
        for(int j=0; j<res[i].size(); j++)
        {
            cout << res[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
