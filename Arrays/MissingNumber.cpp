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

int missingNumber1(vector<int> &arr, int n)
{
    for(int i=1; i<=n; i++)
    {
        int j;
        for(j=0; j<arr.size(); j++)
        {
            if(arr[j] == i)
            {
                break;
            }
        }
        if(j == arr.size())
        {
            return i;
        }
    }
    return -1;
}

int missingNumber2(vector<int> &arr, int n)
{
    vector<int> found(n, 0);
    for(int i=0; i<arr.size(); i++)
    {
        found[arr[i]] = 1;
    }
    for(int i=0; i<found.size(); i++)
    {
        if(found[i+1] == 0)
        {
            return i+1;
        }
    }
    return -1;
}

int missingNumber3(vector<int> &arr, int n)
{
    int sum = n*(n+1)/2;
    for(int i=0; i<arr.size(); i++)
    {
        sum -= arr[i];
    }
    return sum;
}

int missingNumber4(vector<int> &arr, int n)
{
    int xor1 = 0, xor2 = 0;
    for(int i=0; i<n-1; i++)
    {
       xor1 = xor1^arr[i];
       xor2 = xor2^(i+1);
    }
    xor2 = xor2^n;

    return xor2^xor1;
    
}

int main()
{
    
    vector<int> arr = {5,2,3,1,6,7};

    int n = 7;

    display(arr);

    
    cout << missingNumber4(arr, n) << endl;


    return 0;
}