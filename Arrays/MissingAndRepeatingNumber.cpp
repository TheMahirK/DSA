/*
Program Name : Find missing and repeating number
Program Description : Given an array of size N. 
The elements of array are numbers from 1 to N in any order
but one element is missing , and one number is repeating.
Find missing and repeating number
*/

#include<iostream>
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
   Intuition : Count the frequency of each number by comparing using nested for loop
*/

vector<int>findMissingAndRepeating1(vector<int> &arr)
{
    int n = arr.size();
    int missing = -1, repeating = -1;

    for(int i=1; i<=n; i++)
    {
        int count = 0;
        for(int j=0; j<n; j++)
        {
            if(arr[j] == i)
            {
                count++;
            }
            if(count == 2)
            {
                repeating = i;
                break;
            }
        }
        if(count == 0)
        {
            missing = i;
        }
        if(missing != -1 && repeating != -1)
        {
            break;
        }
    }
    return {missing,repeating};

}

/*
2. Algorithm Used : Better
   Time Complexity : O(N)
   Auxiliary Space Requirement : O(N)
   Intuition : Store the frequency of each number in another array for hashing
*/

vector<int>findMissingAndRepeating2(vector<int> &arr)
{
    int n = arr.size();
    vector<int> freq(n,0);
    int missing,repeating;
    for(int i=0; i<n; i++)
    {
        freq[arr[i]-1]++;
    }

    for(int i=0; i<n; i++)
    {
        if(freq[i] == 0)
        {
            missing = i+1;
        }
        if(freq[i] == 2)
        {
            repeating = i+1;
        }
    }
    return {missing,repeating};
}

/*
3. Algorithm Used : Optimal
   Time Complexity : O(N)
   Auxiliary Space Requirement : O(1)
   Intuition : Use two equations to find two variables
   (1)  Sum of N natural numbers Sn = N*(N+1)/2
   (2)  Sum of Squares of N natural numbers Sn2 = (N*(N+1)*(2N+1))/6
*/

vector<int>findMissingAndRepeating3(vector<int> &arr)
{
    int n = arr.size();
    int s = 0;
    int sn = n*(n+1)/2;
    int s2 = 0;
    int sn2 = (n*(n+1)*(2*n + 1))/6;
    int x;  // Repeating Number
    int y;  // Missing Number

    for(int i=0; i<n; i++)
    {
        s += arr[i];
        s2 += (arr[i]*arr[i]);
    }

    x = ((s-sn)+((s2-sn2)/(s-sn)))/2;
    y = x-s+sn;

    return {y,x};
}

int main()
{
    vector<int> arr = {1,3,5,6,8,2,4,6,9};
    display(arr);

    vector<int> missingAndRepeating = findMissingAndRepeating3(arr);
    display(missingAndRepeating);


    return 0;
}