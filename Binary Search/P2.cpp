#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int binaryToDecimal(string s)
{
    int ans = 0;
    int count = 1;

    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == '1')
        {
            ans += count;
        }
        count *= 2;
    }
    return ans;
}

string decimalToBinary(long long n, int k)
{
    string s;

    if (n == 0)
        return string(k, '0');

    while (n > 0)
    {
        s.push_back((n % 2) + '0');
        n /= 2;
    }

    reverse(s.begin(), s.end());

    if (s.size() < k)
    {
        s.insert(s.begin(), k - s.size(), '0');
    }

    return s;
}

int countSetBits(string s)
{
    int count = 0;

    for (char c : s)
    {
        if (c == '1')
            count++;
    }
    return count;
}

string fun(string x, int bits, int maxSet)
{
    int bestXor = -1;
    string ans;

    // Create max number (all 1s)
    string s(bits, '1');
    int n = binaryToDecimal(s);
    int xn = binaryToDecimal(x);

    while (n >= 1)
    {
        int n2 = xn ^ n;

        string strN = decimalToBinary(n, bits);

        if (countSetBits(strN) <= maxSet)
        {
            if (n2 > bestXor)
            {
                bestXor = n2;
                ans = strN;
            }
        }
        n--;
    }

    return ans;
}

string fun2(string x, int bits, int maxSet)
{
    int n = bits;
    string ans(n, '0');

    // Step 1: Put 1 where x has 0 (maximize XOR)
    for (int i = 0; i < n && maxSet > 0; i++)
    {
        if (x[i] == '0')
        {
            ans[i] = '1';
            maxSet--;
        }
    }

    // Step 2: If still remaining, fill from right (least harmful)
    for (int i = n - 1; i >= 0 && maxSet > 0; i--)
    {
        if (ans[i] == '0')
        {
            ans[i] = '1';
            maxSet--;
        }
    }

    return ans;
}

int main()
{
    string s1 = "11100";
    int bits = s1.size();
    int maxSet = 1;

    int num = binaryToDecimal(s1);
    cout << num << " : " << s1 << endl;

    string s2 = decimalToBinary(num, bits);
    cout << s2 << " : " << num << endl;

    string ans = fun2(s1, bits, maxSet);

    cout << "Answer: " << ans << endl;

    return 0;
}