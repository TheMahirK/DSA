#include <iostream>
#include <vector>
#include <string>
using namespace std;

char firstRep(string &s)
{
    int n = s.size();
    int max = n+1;
    char result = '#';
    vector<int>freq(26,n+2);
    for(int i=0; i<n; i++)
    {
        if(freq[s[i]-'a'] < max)
        {
            max = freq[s[i]-'a'];
            result = s[i];
        }
        else
        {
            freq[s[i]-'a'] = i;
        }
    }
    return result;
}

int main()
{
    string s = "mynameismahir";

    char result = firstRep(s);
    cout << result;


    return 0;
}