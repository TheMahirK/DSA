#include <iostream>
#include <vector>
using namespace std;
class Solution
{
    vector<int> v;

public:
    int removeElement(int val)
    {
        int start = 0;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] != val)
            {
                v[start] = v[i];
                start++;
            }
        }
        return start;
    }
    void display()
    {
        for (auto &num : v)
        {
            cout << num << ' ';
        }
    }

    void setData()
    {
        for(int i=1; i<=10; i++)
        {
            if(i%2 == 0)
            {
                v.push_back(2);
            }
            else{
                v.push_back(i);
            }
        }
    }
};


int main()
{
    Solution obj1;
    obj1.setData();
    obj1.display();
    obj1.removeElement(2);
    cout << endl << endl;
    obj1.display();
    return 0;
}