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


int maxConsecutiveOnes(vector<int> &arr)
{
    int max = 0;
    int count = 0;
    for(int i=0; i<arr.size(); i++)
    {
        if(arr[i] == 1)
        {
            count++;
        }
        else
        {
            if(count > max)
            {
                max = count;
            }
            count = 0;
        }
    }
    if(count > max)
    {
        return count;
    }
    return max;
}

int main()
{
    vector<int> arr = {1,1,1,1,1};
    display(arr);


    cout << maxConsecutiveOnes(arr) << endl;
    return 0;
}