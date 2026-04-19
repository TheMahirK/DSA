/*
Program Name : Single Number
Program Description : All numbers are present twice except one , return that number
*/

#include <iostream>
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
*/

int singleNumber1(vector<int> &arr)
{
    for(int i=0; i<arr.size(); i++)
    {
        int count = 1;
        for(int j=0; j<arr.size(); j++)
        {
            if(arr[i] == arr[j] && j != i)
            {
                count++;
                break;
            }
        }
        if(count == 1)
        {
            return arr[i];
        }
    }
    return -1;
}

/*
2. Algorithm Used : Better (Using Unordered Map)
   Time Complexity : O(N)
   Auxiliary Space Requirement : O(N)
*/

int singleNumber2(vector<int> &arr)
{
    int n = arr.size();
    unordered_map<int, int> freq;
    for(int i=0; i<n; i++)
    {
        if(freq.find(arr[i]) != freq.end())
        {
            freq[arr[i]]++;
        }
        else
        {
            freq.insert({arr[i], 1});
        }
    }

    for(auto x : freq)
    {
        if(x.second == 1)
        {
            return x.first;
        }
    }
    return -1;
}


/*
3. Algorithm Used : Optimal - Using XOR Function
   Time Complexity : O(N)
   Auxiliary Space Requirement : O(1)
*/
int singleNumber3(vector<int> &arr)
{
    int xor1 = 0;
    for(int i=0; i<arr.size(); i++)
    {
        xor1 = xor1^arr[i];
    }

    return xor1;

}

int main()
{

    vector<int> arr = {1,1,2,3,4,2,4};
    display(arr);

    cout << singleNumber3(arr) << endl;

    return 0;
}