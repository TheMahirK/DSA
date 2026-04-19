#include <iostream>
#include <vector>
using namespace std;

void display(vector<int> &arr)
{
    for (auto x : arr)
    {
        cout << x << ' ';
    }
    cout << endl;
}

vector<int> decimalToBinary(int n)
{
    vector<int> result;

    while (n != 1)
    {
        if (n % 2 == 1)
        {
            result.push_back(1);
        }
        else
        {
            result.push_back(0);
        }

        n = n / 2;
    }
    result.push_back(1);
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    int n = 31;

    vector<int> result = decimalToBinary(n);
    display(result);

    return 0;
}