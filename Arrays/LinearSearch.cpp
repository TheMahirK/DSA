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

int linearSearch(vector<int> &arr, int x)
{
    for(int i=0; i<arr.size(); i++)
    {
        if(arr[i] == x)
        {
            return i;
        }
    }

    return -1;
}

int main()
{

    vector<int> arr = {1,4,2,3,4,5};
    display(arr);
    int x = 6;
    if(linearSearch(arr, x) >= 0)
    {
        cout << "First occurence of " << x << " is at Index " << linearSearch(arr, x) << endl;
    }
    else
    {
        cout << "Element " << x << " not found in the array" << endl;
    }

    return 0;
}
