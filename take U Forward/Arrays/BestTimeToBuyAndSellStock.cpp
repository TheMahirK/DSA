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
1. Algorithm Used : Optimal
   Time Complexity : O(N)
   Auxiliary Space Requirement : O(1)
   Intuition : Start from left and keep updating minimum and profit
*/

int maxProfit(vector<int> &arr)
{
    int maxProfit = 0;
    int n = arr.size();
    int mini = arr[0];
    for(int i=1; i<n; i++)
    {
        int currProfit = arr[i] - mini;
        maxProfit = max(maxProfit, currProfit);
        mini = min(mini, arr[i]);
    }
    return maxProfit;
}

int main()
{
    vector<int> arr = {7,6,4,3,1};
    display(arr);

    cout << maxProfit(arr);
    return 0;
}