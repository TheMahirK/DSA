#include <iostream>
#include <string>
using namespace std;

bool checkPalindrome(int start , string &s)
{
    if(start >= s.size()/2) return true;
    if(s[start] != s[s.size()-start-1]) return false;
    return checkPalindrome(start+1 , s);
}


int main()
{
    string s = "MADAM";
    cout << checkPalindrome(0,s);


    return 0;
}