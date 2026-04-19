

#include <iostream>
#include <unordered_map>
using namespace std;

void display(vector<int> &arr)
{
    for(auto x : arr)
    {
        cout << x << ' ';
    }
    cout << endl;
}


vector<int> twoSum1(vector<int> &arr, int k)
{
    for(int i=0; i<arr.size(); i++)
    {
        for(int j=i+1; j<arr.size(); j++)
        {
            if(arr[i] + arr[j] == k)
            {
                return {i,j};
            }
        }
    }
    return {-1,-1};
}

vector<int> twoSum2(vector<int> &arr, int k)
{
    unordered_map<int, int> found;
    for(int i=0; i<arr.size(); i++)
    {
        int rem = k - arr[i];
        if(found.find(rem) != found.end())
        {
            return {found[rem],i};
        }
        else
        {
            found.insert({arr[i], i});
        }
    }
    return {-1, -1};
}
int main()
{

    vector<int> arr = {2,6,5,8,11,12};
    int k = 14;
    display(arr);

    vector<int> result = twoSum2(arr, k);
    display(result);

    return 0;
}