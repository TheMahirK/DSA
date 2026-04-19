#include <iostream>
#include <vector>
using namespace std;

void display(vector<int> &v)
{
    for(auto num : v)
    {
        cout << num << ' ';
    }
    cout << endl;
}
int minProduct(vector<int> &arr, int k)
{
    // Complete the function
    sort(arr.begin(), arr.end());
    display(arr);
    int product = 1;
    for (int i = 0; i < k; i++)
    {
        product = product * arr[i];
    }
    return product;
}

int main()
{

    vector<int> v = {17,20,13,15,12,20,19,20,13,20,11,11,16,18,15,15,12,14};
    display(v);
    // sort(v.begin(),v.end());
    // display(v);
    int k = 10;
    cout << minProduct(v,k);
    return 0;
}