#include <iostream>
using namespace std;

void print(int n)
{
    if(n < 1) return

    print(-(0-n));
    cout << n << endl;
    
}

int main()
{
    print(10);
    return 0;
}