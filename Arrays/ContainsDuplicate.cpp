#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

void display(vector<int> &arr)
{
    for(auto x : arr)
    {
        cout << x << ' ';
    }
    cout << endl;
}

// bool containsDuplicate(vector<int> &arr)
// {
//     unordered_map<int,int> m;
//     for(int i=0; i<arr.size(); i++)
//     {
//         if(m.find(arr[i]) != m.end())
//         {
//             return true;
//         }
//         m.insert({arr[i],1});
//     }
//     return false;
// }

bool containsDuplicate(vector<int> &arr)
{
    unordered_set<int> s;
    for(int i=0; i<arr.size(); i++)
    {
        if(s.find(arr[i]) != s.end())
        {
            return true;
        }
        s.insert(arr[i]);
    }
    return false;
}

int main()
{
    vector<int> arr = {1,2,3,4,5};
    display(arr);

    cout << containsDuplicate(arr);


    return 0;
}