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

vector<int> intersectionOfTwoSortedArrays1(vector<int> &arr1, vector<int> &arr2)
{
    vector<int> result;
    int n1 = arr1.size();
    int n2 = arr2.size();
    vector<int> visited(min(n1,n2), 0);
    for(int i=0; i<max(n1,n2); i++)
    {
        for(int j=0; j<min(n1,n2); j++)
        {
            if(arr1[i] == arr2[j] && visited[j] == 0)
            {
                result.push_back(arr1[i]);
                visited[j]=1;
                break;
            }
            if(arr2[j] > arr1[i])
            {
                break;
            } 
        }
    }

    return result;
}

vector<int> intersectionOfTwoSortedArrays2(vector<int> &arr1, vector<int> &arr2)
{
    vector<int> result;
    int n1 = arr1.size();
    int n2 = arr2.size();

    int i = 0, j = 0;
    while(i < n1 && j < n2)
    {
        if(arr1[i] == arr2[j])
        {   
            result.push_back(arr1[i]);   
            i++;
            j++;
        }
        else if(arr1[i] < arr2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    return result;
}

int main()
{
    vector<int> arr1 = {1,2,2,3,4,4,5,6,7};
    vector<int> arr2 = {0,2,2,4,4,6,6};
    display(arr1);
    display(arr2);

    vector<int> intersection = intersectionOfTwoSortedArrays1(arr1, arr2);
    display(intersection);


    return 0;
}