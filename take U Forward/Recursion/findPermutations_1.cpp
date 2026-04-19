#include <iostream>
#include <vector>
using namespace std;

// to find all permutations of an array/vector
// time complexity O(n!) * O(n)
// aux space req. O(n!) for answer + O(n) for recursion + O(n) for subarray



void permutation(vector<int> &arr, vector <int> &subArr,
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
            permutation(arr,subArr,result,freq);
            freq[i] = 0;
            subArr.pop_back();
        }
    }
}

vector<vector<int>> findPermutation(vector<int> &arr)
{
    vector<vector<int>> result;
    vector<int> subArr;
    int freq[arr.size()];
    for(int i=0; i<arr.size(); i++) freq[i] = 0;
    permutation(arr,subArr,result,freq);
    return result;

}

int main()
{
    vector<int> arr = {1,2,3};
    vector<vector<int>> result;

    result = findPermutation(arr);
    int count = 1;
    for(int i=0; i<result.size(); i++)
    {
        cout << count << " : ";  
        for(int j=0; j<result[i].size(); j++)
        {
             
            cout << result[i][j] << ' ';
           
        }
         count++;
        cout << endl;
    }


    return 0;
}