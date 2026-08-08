/*
Problem Name : Find all Permutations of a given Array/String
Problem Description : Given an array/string , generate all the possible permutations of the array/string
*/

#include <iostream>
using namespace std;

void display(vector<int> &arr)
{
    for (auto x : arr)
    {
        cout << x << ' ';
    }
    cout << endl;
}

void display(vector<vector<int>> &arr)
{
    for (auto row : arr)
    {
        display(row);
    }
}

/*
Intuition : Write Intuition here
*/

void f1(vector<int> &arr, vector<bool> &visited, vector<int> &permutation, vector<vector<int>> &ans)
{
    if (permutation.size() == arr.size())
    {
        ans.push_back(permutation);
        return;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (!visited[i])
        {
            permutation.push_back(arr[i]);
            visited[i] = true;

            f1(arr, visited, permutation, ans);

            permutation.pop_back();
            visited[i] = false;
        }
    }
}

vector<vector<int>> permutations1(vector<int> &arr)
{
    vector<vector<int>> ans;
    vector<int> permutation;
    int n = arr.size();
    vector<bool> visited(n, false);

    f1(arr, visited, permutation, ans);

    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3};

    cout << "Array : ";
    display(arr);

    vector<vector<int>> permutations = permutations1(arr);

    cout << "Permutations :" << endl;

    display(permutations);

    return 0;
}