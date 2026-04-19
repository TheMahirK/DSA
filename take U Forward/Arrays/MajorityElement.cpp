/*
Program Name : Majority Element
Program Description : There exist an element which occurs more than N/2 times , return that element
*/


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


/*
1. Algorithm Used : Brute Force
   Time Complexity : O(N^2)
   Auxiliary Space Requirement : O(1)
   Intuition : Check how many times a single element is repeated
*/

int majorityElement1(vector<int> &arr)
{
    int n = arr.size();
    for(int i=0; i<n; i++)
    {
        int count = 1;
        for(int j=i+1; j<n; j++)
        {
            if(arr[i] == arr[j])
            {
                count++;
            }
        }
        if(count > n/2)
        {
            return arr[i];
        }
    }
    return -1;
}


/*
2. Algorithm Used : Better - Using Unordered Map
   Time Complexity : O(N) 
   Auxiliary Space Requirement : O(N)
   Intuition : Store Element and its frequency in a map
*/

int majorityElement2(vector<int> &arr)
{
    int n = arr.size();
    unordered_map<int, int> mpp;
    for(int i=0; i<n; i++)
    {
        if(mpp.find(arr[i]) != mpp.end())
        {
            mpp[arr[i]]++;
            if(mpp[arr[i]] > n/2)
            {
                return arr[i];
            }
        }
        else
        {
            mpp.insert({arr[i],1});
        }
    }
    return -1;
}


/*
3. Algorithm Used : Optimal - Moore's Voting Algorithm
   Time Complexity : O(N) 
   Auxiliary Space Requirement : O(1)
   Intuition : Any Vote not in our favour is Vote against us
*/

int majorityElement3(vector<int> &arr)
{
    int n = arr.size();
    int ele;
    int count = 0;
    for(int i=0; i<n; i++)
    {
        if(count == 0)
        {
            ele = arr[i];
            // cout << ele << endl;
            count++;
        }
        else if(arr[i] == ele)
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    return ele;
}

int main()
{
    vector<int> arr = {4,2,4,3,4,5,4};
    display(arr);

    cout << majorityElement3(arr) << endl;

    return 0;
}