#include <iostream>
#include <bitset>
#include <unordered_map>
using namespace std;

void display(vector<int> &arr)
{
    for (auto x : arr)
    {
        cout << x << ' ';
    }
    cout << endl;
}

int subarrayXOR1(vector<int> &arr, int k)
{
    int count = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int XOR = 0;
            // vector<int> subArr;
            for (int s = i; s <= j; s++)
            {
                // subArr.push_back(arr[s]);
                XOR = XOR ^ arr[s];
            }
            if (XOR == k)
            {
                // display(subArr);
                count++;
            }
        }
    }
    return count;
}

int subarrayXOR2(vector<int> &arr, int k)
{
    int n = arr.size();
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        int XOR = 0;
        for (int j = i; j < n; j++)
        {
            XOR = XOR ^ arr[j];
            if (XOR == k)
            {
                count++;
            }
        }
    }

    return count;
}


int subarrayXOR3(vector<int> &arr, int k)
{
    int n = arr.size();
    int count = 0;

    unordered_map<int, int> mpp;
    mpp[0] = 1;
    int XOR = 0;
    for(int i=0; i<n; i++)
    {
        XOR = XOR^arr[i];
        mpp[XOR]++;

        int x = XOR^k;

        if(mpp.find(x) != mpp.end())
        {
            count += mpp[x];
        }
    }
    

    return count;
}

int main()
{
    vector<int> arr = {4, 2, 2, 6, 4};
    display(arr);

    int k = 6;

    int count = subarrayXOR3(arr, k);
    cout << "Count : " << count;

    return 0;
}