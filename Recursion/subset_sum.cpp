#include <iostream>
#include <vector>
using namespace std;

void findSum(int ind, int sum, vector<int> &arr,
vector<int> &subset)
{
    if(ind == arr.size())
    {
        subset.push_back(sum);
        return;
    }

    // to pick the element
    findSum(ind+1,sum+arr[ind],arr,subset);

    // to not pick the element
    findSum(ind+1,sum,arr,subset);
}

vector<int> subsetSum(vector<int> &arr)
{
    vector<int> subset;
    sort(arr.begin(),arr.end());
    int sum = 0;

    findSum(0,sum,arr,subset);
    // sort(subset.begin(),subset.end());
    return  subset;
}

int main()
{
    vector<int> arr = {3,1,2};
    vector<int> result;
    result = subsetSum(arr);

    for(int num : result)
    {
        cout << num << ' ';
    }

    return 0;
}