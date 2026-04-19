#include <iostream>
using namespace std;

void display(vector<int> &v)
{
    for(auto x : v)
    {
        cout << x << ' ';
    }
    cout << endl;
}

void moveZeroesToEnd1(vector<int> &arr)
{
    vector<int> temp;
    for(int i=0; i<arr.size(); i++)
    {
        if(arr[i] != 0)
        {
            temp.push_back(arr[i]);
        }
    }

    for(int i=0; i<temp.size(); i++)
    {
        arr[i] = temp[i];
    }
    for(int i=temp.size(); i<arr.size(); i++)
    {
        arr[i] = 0;
    }
}

void moveZeroesToEnd2(vector<int> &arr)
{
    int j=-1;
    for(int i=0; i<arr.size(); i++)
    {
        if(arr[i] == 0)
        {
            j = i;
            break;
        }
    }

    for(int i=j+1; i<arr.size(); i++)
    {
        if(arr[i] != 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}


int main()
{
    vector<int> arr = {1,2,0,0,2,0,3};
    display(arr);

    moveZeroesToEnd2(arr);
    display(arr);
}