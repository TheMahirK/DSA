/*

Program Name : Majority Element 2
Program Description : Given array of size N, return the list of elements with frequency > N/3



2. Algorithm Used : Better
   Time Complexity : O(2N)
   Auxiliary Space Requirement : O(1)

3. Algorithm Used : Optimal - Dutch National Flag Algorithm
   Time Complexity : O(N)
   Auxiliary Space Requirement : O(1)

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
   Auxiliary Space Requirement : O(2)
   Intuition : Compare each element with all other elements to find the frequency
*/

vector<int> majorityElement2_1(vector<int> &arr)
{
    int n = arr.size();
    vector<int> result;
    for(int i=0; i<n; i++)
    {
        int ele = arr[i];
        int count = 0;
        for(int j=i; j<n; j++)
        {
            if(ele == arr[j])
            {
                count++;
            }
        }
        if(count > n/3)
        {
            result.push_back(ele);
        }
    }
    return result;
}

/*
2. Algorithm Used : Better
   Time Complexity : O(N)
   Auxiliary Space Requirement : O(N) + O(2)
   Intuition : Use unordered map to store every unique element and its frequency
*/

vector<int> majorityElement2_2(vector<int> &arr)
{
    int n = arr.size(), min = (n/3)+1;
    vector<int> result;
    unordered_map<int, int> mpp;
    for(int i=0; i<n; i++)
    {
        mpp[arr[i]]++;
        if(mpp[arr[i]] == min)
        {
            result.push_back(arr[i]);
        }

        if(result.size() == 2)
        {
            break;
        }
    }
    return result;
}

/*
2. Algorithm Used : Optimal
   Time Complexity : O(N)
   Auxiliary Space Requirement : O(1)
   Intuition : Use voting algorithm 
*/

vector<int> majorityElement2_3(vector<int> &arr)
{
    int count1 = 0, count2 = 0, ele1 = INT_MIN, ele2 = INT_MIN;
    int n = arr.size();
    
    for(int i=0; i<n; i++)
    {
        if(count1 == 0 && arr[i] != ele2)
        {
            count1 = 1;
            ele1 = arr[i];
        }
        else if(count2 == 0 && arr[i] != ele1)
        {
            count2 = 1;
            ele2 = arr[i];
        }
        else if(arr[i] == ele1)
        {
            count1++;
        }
        else if(arr[i] == ele2)
        {
            count2++;
        }
        else
        {
            count1--;
            count2--;
        }
    }
    count1 = 0, count2 = 0;
    vector<int> result;
    int mini = (n/3)+1;
    for(int i=0; i<n; i++)
    {
        if(arr[i] == ele1)
        {
            count1++;
        }
        if(arr[i] == ele2)
        {
            count2++;
        }
    }
    if(count1 >= mini)
    {
        result.push_back(ele1);
    }
    if(count2 >= mini)
    {
        result.push_back(ele2);
    }
    return result;

}

int main()
{
    vector<int> arr = {4,3,4,2,4,2,4,2,5,2};
    display(arr);

    vector<int> majorityElements = majorityElement2_3(arr);
    display(majorityElements);

    return 0;
}