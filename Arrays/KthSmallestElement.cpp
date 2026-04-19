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

int KthSmallestElement(vector<int> &arr, int k)
{
    sort(arr.begin(),arr.end());
    display(arr);
    int n = arr.size();
    cout << n << endl;
    vector<int> subArr;
    int count = 0;
    for(int i=0; i<n-1; i++)
    {
        if(arr[i] != arr[i+1])
        {
            count++;
        }
        if(count == k)
        {
            return arr[i];
        }
    }
    return arr[n-1];

}

int main()
{
    vector<int> arr = {3,2,1,4,2,4,5,6,8,7,9};
    display(arr);

    int result = KthSmallestElement(arr, 9);
    cout << result;


    return 0;
}