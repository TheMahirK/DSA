/*
Problem Name : One Subsequence with sum K
Problem Description : Given an array of +ve integers and an integer k, one the subsequence
whose sum is equal to k
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
Intuition : Use the concept of 1. pick (add element to sum and subseq.) ,
 2. Not pick (pick, add, remove, subtract) to find the all the subsequences with sum == k

 use bool return type , whenever we find the first subseq with sum == k, we return true

 and whenever we get true during recursion, we break the recursion by returning true

Time Complexity : O(2^N) in worst case
as we may have to generate all subsequences 
Aux. Space Req. : O(2^N)
*/

bool f(int index, vector<int> &arr, int sum, int k, vector<int> &subseq)
{
    if(index >= arr.size())
    {
        // Condition satisfied
        if(sum == k)
        {
            return true;
        }
        // Condition not satisfied
        return false;
    }

    sum += arr[index];
    subseq.push_back(arr[index]);

    if(f(index+1, arr, sum, k, subseq) == true)
    {
        // Found answer (stored in subseq)
        return true;
    }

    subseq.pop_back();
    sum -= arr[index];

    if(f(index+1, arr, sum, k, subseq) == true)
    {
        // Found answer (stored in subseq)
        return true;
    }
    return false;
}

vector<int> subsequenceWithSumK(vector<int> &arr, int k)
{
    int sum = 0;
    vector<int> subseq;

    f(0, arr, sum, k, subseq);

    return subseq;
}

int main()
{

    vector<int> arr = {1,2,3,4,5,6,7};
    int k = 29;

    vector<int> subseq = subsequenceWithSumK(arr, k);

    display(subseq);

    return 0;
}