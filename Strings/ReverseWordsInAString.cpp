#include <iostream>
using namespace std;

string reverseWords(string s)
{
    int n = s.size();

    int i = 0, j = 0;

    while (j < n)
    {
        while (j < n && s[j] == ' ')
        {
            j++;
        }

        while (j < n && s[j] != ' ')
        {
            s[i] = s[j];
            i++, j++;
        }
        while (j < n && s[j] == ' ')
        {
            j++;
        }

        // Add one space after word
        if (j < n)
        {
            s[i] = ' ';
            i++;
        }
    }

    s.resize(i);
    reverse(s.begin(), s.end());

    int start = 0;

    for (int end = 0; end <= s.size(); end++)
    {
        if (end == s.size() || s[end] == ' ')
        {
            reverse(s.begin() + start, s.begin() + end);
            start = end + 1;
        }
    }
    return s;
}

int main()
{
    string s = "    the     sky   is blue     ";

    cout << s << endl;

    s = reverseWords(s);

    cout << s << endl;
}