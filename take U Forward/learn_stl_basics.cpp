#include <vector>
#include <iostream>
using namespace std;

int main()
{
    vector<int> v1;
    for(int i = 1; i <= 10; i++)
    {
        v1.push_back(2*i);
    }

    for(auto num : v1)
    {
        cout << num << ' ';
    }
    cout << endl;

    int start = *v1.begin();
    {
        cout << start;
    }



    return 0;
}