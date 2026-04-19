/*

Program Name : 4Sum
Program Description : Find all the unique quadruplets with sum equals target

*/

#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

void display(vector<int> &arr)
{
    for(auto x : arr)
    {
        cout << x << ' ';
    }
    cout << endl;
}

void display(vector<vector<int>> &arr)
{
    for(auto row : arr)
    {
        for(auto x : row)
        {
            cout << x << ' ';
        }
        cout << endl;
    }
    cout << endl;
}
/*
1. Algorithm Used : Brute Force
   Time Complexity : O(N^4)
   Auxiliary Space Requirement : O(2 * no. of unique quadruplets)
   Intuition : Use nested loops to find all the quads , sort them and store in a set for unique only
*/

vector<vector<int>> fourSum1(vector<int> &arr, int target)
{
    set<vector<int>> s;
    int n = arr.size();

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            for(int k=j+1; k<n; k++)
            {
                for(int l=k+1; l<n; l++)
                {
                    long long sum = arr[i];
                    sum += arr[j];
                    sum += arr[k];
                    sum += arr[l];

                    if(sum == target)
                    {
                        vector<int> temp = {arr[i],arr[j],arr[k],arr[l]};
                        sort(temp.begin(), temp.end());
                        s.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> result(s.begin(), s.end());
    return result;
}

/*
2. Algorithm Used : Better
   Time Complexity : O(N^3)
   Auxiliary Space Requirement : O(2 * no. of unique quadruplets) + O(N)
   Intuition : Use unordered set to find the fourth element
*/

vector<vector<int>> fourSum2(vector<int> &arr, int target)
{
    int n = arr.size();
    set<vector<int>> s;

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            unordered_set<long long> st;
            for(int k=j+1; k<n; k++)
            {
                long long sum = arr[i];
                sum += arr[j];
                sum += arr[k];
                long long fourth = target - sum;
                if(st.find(fourth) != st.end())
                {
                    vector<int> temp = {arr[i],arr[j],arr[k],(int)fourth};
                    sort(temp.begin(), temp.end());
                    s.insert(temp);
                }
                st.insert(arr[k]);
            }
        }
    }

    vector<vector<int>> result(s.begin(), s.end());
    return result;
}

/*
3. Algorithm Used : Optimal
   Time Complexity : O(N^3)
   Auxiliary Space Requirement : O(2 * no. of unique quadruplets)
   Intuition : Sort the array and then use two pointer approach on the sorted array
*/


vector<vector<int>> fourSum3(vector<int> &arr, int target)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> result;
    for(int i=0; i<n; i++)
    {
        if(i > 0 && arr[i] == arr[i-1]) continue;

        for(int j=i+1; j<n; j++)
        {
            if(j != i+1 && arr[j] == arr[j-1])  continue;
            int k = j+1;
            int l = n-1;

            while(k < l)
            {
                long long sum = arr[i];
                sum += arr[j];
                sum += arr[k];
                sum += arr[l];
                if(sum == target)
                {
                    vector<int> temp = {arr[i],arr[j],arr[k],arr[l]};
                    result.push_back(temp);
                    k++;
                    l--;
                    while(k < l && arr[k] == arr[k-1])  k++;
                    while(k < l && arr[l] == arr[l+1])  l--;
                }
                else if(sum < target)
                {
                    k++;
                }
                else
                {
                    l--;
                }
            }

        }
    }
    return result;
}

int main()
{

    vector<int> arr = {10,2,3,4,5,7,8};
    display(arr);
    cout << "\n" << arr.size();
    cout << endl;
    
    int target = 23;

    vector<vector<int>> quads = fourSum3(arr, target);
    display(quads);

    return 0;
}