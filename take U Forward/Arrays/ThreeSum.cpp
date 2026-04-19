/*

Program Name : 3 Sum
Program Description : Return list of all triplets whose sum is 0

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
}

/*
1. Algorithm Used : Brute Force
   Time Complexity : O(N^3)
   Auxiliary Space Requirement : O(2 * unique triplets)
   Intuition : Find every triplet and check if the sum is 0 and use set for unique triplets
*/

vector<vector<int>> threeSum1(vector<int> &arr)
{
    set<vector<int>> s;
    int n = arr.size();
    for(int i=0; i<n; i++)
    {
        
        for(int j=i+1; j<n; j++)
        {   
            vector<int> subArr;
            for(int k=j+1; k<n; k++)
            {
                if((arr[i]+arr[j]+arr[k]) == 0)
                {
                    vector<int> temp = {arr[i],arr[j],arr[k]};
                    sort(temp.begin(), temp.end());
                    s.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> result(s.begin(), s.end());
    // display(result);
    return result;
}

/*
2. Algorithm Used : Better 
   Time Complexity : O(N^2)
   Auxiliary Space Requirement : O(N) + O(2 * unique triplets) 
   Intuition : Find all the pairs and check if the third element is present or not by using hashset

*/

vector<vector<int>> threeSum2(vector<int> &arr)
{
    set<vector<int>> s;
    int n = arr.size();
    for(int i=0; i<n; i++)
    {
        unordered_set<int> hashset;
        for(int j=i+1; j<n; j++)
        {
            int third = - (arr[i]+arr[j]);
            if(hashset.find(third) != hashset.end())
            {
                vector<int> temp = {arr[i],arr[j],third};
                sort(temp.begin(), temp.end());
                s.insert(temp);
            }
            hashset.insert(arr[j]);

        }
    }
    vector<vector<int>> result(s.begin(), s.end());
    return result;
}

/*
3. Algorithm Used : Optimal 
   Time Complexity : ~ O(NlogN) + O(N^2)
   Auxiliary Space Requirement : O(unique triplets) 
   Intuition : Use three pointer approach in sorted array

*/

vector<vector<int>> threeSum3(vector<int> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> result;
    for(int i=0; i<n; i++)
    {
        if(i > 0 && arr[i] == arr[i-1])
        {
            continue;
        }
        int j = i+1; 
        int k = n-1;
        while(j < k)
        {
            int sum = arr[i]+arr[j]+arr[k];
            if(sum < 0)
            {
                j++;
            }
            else if(sum > 0)
            {
                k--;
            }
            else
            {
                result.push_back({arr[i],arr[j],arr[k]});
                j++;
                k--;
                while(j < k && arr[j] == arr[j-1])  j++;
                while(j < k && arr[k] == arr[k+1])  k--;
            }
        }
    }
    return result;
}


int main()
{
    vector<int> arr = {-1,0,1,2,-1,-4};
    display(arr);

    cout << "\nTriplets : " << endl;
    vector<vector<int>> result = threeSum3(arr);
    display(result);

    

    return 0;
}