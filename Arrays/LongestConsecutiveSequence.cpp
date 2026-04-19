#include <iostream>
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

bool linearSearch(int n, vector<int> &arr)
{
    for(int i=0; i<arr.size(); i++)
    {
        if(arr[i] == n)
        {
            return true;
        }
    }
    return false;
}

int longestConsecutiveSequence1(vector<int> &arr)
{
    int longestLen = 1;
    int n = arr.size();

    for(int i=0; i<n; i++)
    {
        vector<int> sequence;
        int a = arr[i];
        int currLen = 1;
        while(linearSearch(a+1, arr) == true)
        {
            currLen++;
            a++;
            
        }
        if(currLen > longestLen)
        {
            longestLen = currLen;
            
        }
    }
    return longestLen;
}

int longestConsecutiveSequence2(vector<int> &arr)
{
    int n = arr.size();
    int maxLen = 1;
    int currLen = 0, lastEle = INT_MIN;
    sort(arr.begin(),arr.end());
    for(int i=0; i<n; i++)
    {
        if(lastEle == arr[i]-1)
        {
            currLen++;
            lastEle = arr[i];
        }
        else if(arr[i] != lastEle)
        {
            currLen = 1;
            lastEle = arr[i];
        }
        maxLen = max(maxLen, currLen);
    }
    return maxLen;
}


int longestConsecutiveSequence3(vector<int> &arr)
{
    int n = arr.size();
    int maxLen = 1;
    int currLen = 0;
    unordered_set<int> s;
    for(int i=0; i<n; i++)
    {
        s.insert(arr[i]);
    }
    for(auto a : s)
    {
        if(s.find(a-1) == s.end())
        {
            currLen = 1;
            int x = a;
            while(s.find(x+1) != s.end())
            {
                x++;
                currLen++;
            }
        }
        maxLen = max(currLen, maxLen);
    }
    return maxLen;
}

int main()
{
    vector<int> arr = {102,4,100,1,101,3,2,1,1};
    display(arr);

    cout << longestConsecutiveSequence3(arr);

    return 0;
}