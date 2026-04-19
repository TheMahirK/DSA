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



int longestSubarray1(vector<int> &arr, int k)
{
    
    int max = 0;
    for(int i=0; i<arr.size(); i++)
    {
        
        int sum = 0;
        for(int j=i; j<arr.size(); j++)
        {
            sum += arr[j];
            if(sum == k && (j-i+1) > max)
            {
                max = j-i+1;
                
            }
        }
    }
    return max;
}


int longestSubarray2(vector<int> &arr, int k)
{
    unordered_map<long long , int> prefixSum;
    long long sum = 0;
    int maxLen = 0;
    for(int i=0; i<arr.size(); i++)
    {
        sum += arr[i];

        if(sum == k)
        {
            maxLen = i+1;
        }

        long long rem = sum - k;
        if(prefixSum.find(rem) != prefixSum.end())
        {
            int len = i-prefixSum[rem];
            maxLen = max(len, maxLen);
        }
        if(prefixSum.find(sum) == prefixSum.end())
        {
            prefixSum[sum] = i;
        }
    }
    return maxLen;
}


int longestSubarray3(vector<int> &arr, int k)
{
    int i = 0, j = 0, maxLen = 0;
    long long sum = arr[0];

    int n = arr.size();

    while(j < n)
    {
        while(i <= j && sum > k)
        {
            sum -= arr[i];
            i++;
        }
        if(sum == k)
        {
            maxLen = max(maxLen, j-i+1);
            
        }
        j++;
        if(j < n)
        {
            sum += arr[j];
        }
    }

    return maxLen;
}


int main()
{

    vector<int> arr = {2,3,1,1,2,3,1,2};
    int k = 4;

    display(arr);
    cout << longestSubarray2(arr, k) << endl;


    return 0;
}