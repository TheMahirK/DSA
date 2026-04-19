#include <iostream>
using namespace std;

void swapArray1(int arr[], int size, int l , int r)
{
    if(l >= r) return;

    swap(arr[l],arr[r]);
    swapArray1(arr, size, l+1 , r-1);
}

void swapArray2(int arr[], int size , int i)
{
    if(i == size/2) return;
    swap(arr[i], arr[size-i-1]);

    swapArray2(arr,size,i+1);
}


int main()
{
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    int left = 0;
    int right = size-1;

    swapArray1(arr,size,left,right);

    for(int i=0; i<size; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;

    swapArray2(arr,size,left);

    for(int i=0; i<size; i++)
    {
        cout << arr[i] << ' ';
    }    
    cout << endl;

}