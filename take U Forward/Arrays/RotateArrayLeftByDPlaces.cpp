#include<iostream>
using namespace std;

void display(vector<int> &v)
{
    for(auto x : v)
    {
        cout << x << ' ';
    }
    cout << endl;
}


void leftRotateByDPlaces1(vector<int> &arr, int d)
{
    int n = arr.size();
    d = d%n;
    if(d == 0)
    {
        return;
    }
    vector<int> temp;
    for(int i=0; i<d; i++)
    {
        temp.push_back(arr[i]);
    }
    for(int i=0; i<n; i++)
    {
        arr[i] = arr[d+i];
    }
  
    for(int i=n-d; i<n; i++)
    {
        arr[i] = temp[i-(n-d)];
        
    }
}

void leftRotateByDPlaces2(vector<int> &arr, int d)
{
    int n = arr.size();
    d = d%n;
    if(d == 0)
    {
        return;
    }
    reverse(arr.begin(), arr.begin()+d);
    reverse(arr.begin()+d, arr.end());
    reverse(arr.begin(), arr.end());
}


int main()
{
    vector<int> arr = {1,2,3,4,5};
    display(arr);

    leftRotateByDPlaces2(arr,2);
    display(arr);


    return 0;
}