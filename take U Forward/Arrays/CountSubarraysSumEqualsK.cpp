/*
Program Name : Count Subarray with sum K
Program Description : Find the count of all possible subarrays with sum equal to K
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
   Time Complexity : ~ O(N^3)
   Auxiliary Space Requirement : O(1)
   Intuition : Generate all subarrays and find the sum of each subarray
*/
int countSubarraySumK1(vector<int> &arr, int k)
{
    int n = arr.size();
    int count = 0;
    for(int i=0; i<n; i++)
    {
        
        for(int j=i; j<n; j++)
        {
            // vector<int> subArr;
            int sum = 0;
            for(int x=i; k<=j; x++)
            {
                sum += arr[x];
                // subArr.push_back(arr[x]);
            }
            if(sum == k)
            {
                // display(subArr);
                count++;
            }
        }
    }
    return count;
}

/*

2. Algorithm Used : Better
   Time Complexity : O(N^2)
   Auxiliary Space Requirement : O(1)
   Intuition : Keep adding every element of subarray to sum and checking if its equal to target
*/

int countSubarraySumK2(vector<int> &arr, int k)
{
    int n = arr.size();
    int count = 0;
    for(int i=0; i<n; i++)
    {
        int sum = 0;
        // vector<int> subArr;
        for(int j=i; j<n; j++)
        {
            
            sum += arr[j];
            // subArr.push_back(arr[j]);
            if(sum == k)
            {
                // display(subArr);
                count++;
            }
        }
    }
    return count;
}

/*
3. Algorithm Used : Optimal - Use of Prefix Sum
   Time Complexity : O(N)
   Auxiliary Space Requirement : O(N)
   Intuition : Keep adding every prefix sum and the frequency of it, if there exists 
   other = prefixSum - k in map , increase count by the frequency of other
*/

int countSubarraySumK3(vector<int> &arr, int k)
{
    int n = arr.size();
    unordered_map<int,int> m;
    m[0] = 1;
    int count = 0, prefixSum = 0;

    for(int i=0; i<n; i++)
    {
        prefixSum += arr[i];
        int other = prefixSum - k;
        count += m[other];
        m[prefixSum] += 1;
    }

    return count;
}

int main()
{
    vector<int> arr = {1,2,3,-3,1,1,1,4,2,-3};
    int k = 3;

    cout << countSubarraySumK3(arr, k);
    cout << endl << endl;


    return 0;
}