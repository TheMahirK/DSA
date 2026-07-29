#include <iostream>
using namespace std;

bool check(int index, string &s)
{
    if (index >= s.size() / 2)
    {
        return true;
    }

    if (s[index] != s[s.size() - index - 1])
    {
        return false;
    }
    return check(index + 1, s);
}

bool checkPalindrome(string &s)
{
    return check(0, s);
}

int main()
{
    string s = "RACECAR";

    bool isPalindrome = checkPalindrome(s);

    cout << isPalindrome;

    return 0;
}