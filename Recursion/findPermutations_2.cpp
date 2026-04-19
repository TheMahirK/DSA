#include <iostream>
#include <vector>
using namespace std;

// to find all permutations of an array/vector
//  this method utilizes swapping the elements and then adding to answer rather than 
//  another data structure to store elements then copying

// time complexity O(n!) * O(n);
// aux space req. O(n!) for answer + O(n) for recursion

void permutation(int ind, vector<int> &arr, vector<vector<int>> &result)
{
    if(ind == arr.size())
    {
        result.push_back(arr);
        return;
    }

    for(int i=ind; i<arr.size(); i++)
    {
        swap(arr[ind],arr[i]);
        permutation(ind+1, arr, result);
        swap(arr[i],arr[ind]);
    }

}

vector<vector<int>> findPermutation(vector<int>&arr)
{
    vector<vector<int>> result;
   
    permutation(0,arr,result);
    return result;


}

int main()
{
    vector <int> arr = {1,2,3};
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