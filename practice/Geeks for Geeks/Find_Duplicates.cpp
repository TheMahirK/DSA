#include <iostream>
#include <vector>
using namespace std;

void display(vector<int> &arr)
{
    for(int i=0; i<arr.size(); i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

vector<int> findDuplicates(vector<int> &arr)
{
    vector<int> result;
    for(int i=0; i<arr.size(); i++)
    {
        int index = abs(arr[i]-1);

        if(arr[index] > 0)
        {
            arr[index] = -arr[index];
        }

        else
        {
            result.push_back(arr[i]);
           
        }
    }

    return result;
}

int main()
{
    vector<int> v = {1,2,3,1,2,3};
    cout << "Original vector : ";
    display(v);
    vector<int> duplicates;
    cout << "Duplicates      : ";
    duplicates = findDuplicates(v);
    display(duplicates);
    return 0;
}