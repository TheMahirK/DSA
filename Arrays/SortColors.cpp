/*
Program Name : Sort Colors
Program Description : Sort array containing 0s, 1s and 2s
*/

#include<iostream>
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
1. Algorithm Used : Brute Force
   Time Complexity : O(N log N)
   Auxiliary Space Requirement : O(N)
*/

void sortColors1(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
}


/*
2. Algorithm Used : Better
   Time Complexity : O(2N)
   Auxiliary Space Requirement : O(1)
*/
void sortColors2(vector<int> &arr)
{
    int count0 = 0, count1 = 0, count2 = 0;
    for(int i=0; i<arr.size(); i++)
    {
        if(arr[i] == 0)
        {
            count0++;
            continue;
        }
        else if(arr[i] == 1)
        {
            count1++;
            continue;
        }
        else
        {
            count2++;
        }
    }
    for(int i=0; i<count0; i++)
    {
        arr[i] = 0;
    }
    for(int i=count0; i<count0+count1; i++)
    {
        arr[i] = 1;
    }
    for(int i=count0+count1; i<count0+count1+count2; i++)
    {
        arr[i] = 2;
    }
}

/*
3. Algorithm Used : Optimal - Dutch National Flag Algorithm
   Time Complexity : O(N)
   Auxiliary Space Requirement : O(1)
*/
void sortColors3(vector<int> &arr)
{
    int low = 0, mid = 0, high = arr.size()-1;
    while(mid <= high)
    {
        if(arr[mid] == 0)
        {
            swap(arr[mid], arr[low]);
            mid++;
            low++;
        }
        
        else if(arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }

    }
}


int main()
{

    vector<int> arr = {1,2,1,0,2,0,1};
    display(arr);
    
    sortColors3(arr);
    display(arr);

    return 0;
}