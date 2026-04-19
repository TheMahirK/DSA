#include <iostream>
#include <vector>
using namespace std;

void display(vector<int> &v)
{
    for(auto x : v)
    {
        cout << x << ' ';
    }
    cout << endl;
}

vector<int> deleteAlternate(vector<int> &v)
{
    int count = 0;
    int n = v.size();
    for(int i=0; i<n; i++)
    {
        if(i%2 != 0)
        {
            v.erase(v.begin()+i-count);
            count++;
        }
    }
    return v;
}

int main()
{
    vector<int> v = {1,2,3,4,5};
    display(v);
    v = deleteAlternate(v);
    display(v);

    return 0;
}