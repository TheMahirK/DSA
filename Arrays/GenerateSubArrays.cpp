#include <iostream>
#include <vector>
using namespace std;

void display(vector<int> &arr)
{
    for(auto x : arr)
    {
        cout << x << ' ';
    }
    cout << endl;
}

void display(vector<vector<int>> &v)
{
    for(auto row : v)
    {
        for(auto x : row)
        {
            cout << x << ' ';
        }
        cout << endl;
    }
}

vector<vector<int>> getSubarrays(vector<int> &arr)
{
    vector<vector<int>> result;
    for(int i=0; i<arr.size(); i++)
    {
        vector<int> subArr;
        int count = 0;
        for(int j=0; j<i; j++)
        {
            subArr.push_back(arr[j]);

        }
        result.push_back(subArr);
        vector<int> subArr2;
        for(int k=i; k<arr.size(); k++)
        {
            subArr2.push_back(arr[k]);

        }
        result.push_back(subArr2);

    }


    return result;
}

int main()
{

    vector<int> arr = {1,2,3,4,5};

    display(arr);

    vector<vector<int>> result = getSubarrays(arr);
    display(result);


    return 0;
}