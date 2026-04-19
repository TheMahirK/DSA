#include <iostream>
#include <string>
using namespace std;

void display(string &s)
{
    for (auto x : s)
    {
        cout << x << ' ';
    }
    cout << endl;
}

int binaryToDecimal(string &s)
{
    int result = 0;
    int n = s.size();

    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '1')
        {
            int x = pow(2, n - i - 1);
            result += x;
        }
    }

    return result;
}

string decimalToBinary(int n)
{
    if(n == 0)  return "0";
    string result;

    while (n != 1)
    {
        if (n % 2 == 1)
        {
            result.push_back('1');
        }
        else
        {
            result.push_back('0');
        }

        n = n / 2;
    }
    result.push_back('1');
    reverse(result.begin(), result.end());
    return result;
}

int main()
{

    int x = INT_MIN;

    x = ~x;

    cout << x;

    return 0;
}