#include <iostream>
using namespace std;

void print1(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void print2(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void print3(int n)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void print4(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

void print5(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = n; j > i; j--)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void print6(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void print7(int n)
{
    for (int i = 1; i <= n; i++)
    {
        // spaces
        for (int j = 1; j <= n - i; j++)
        {
            cout << "  ";
        }
        // stars

        for (int j = 1; j <= 2 * i - 1; j++)
        {
            cout << "* ";
        }

        // spaces
        for (int j = 1; j <= n - i; j++)
        {
            cout << "  ";
        }

        cout << endl;
    }
}

void print8(int n)
{
    for (int i = 1; i <= n; i++)
    {
        // spaces
        for (int j = 1; j <= i - 1; j++)
        {
            cout << "  ";
        }

        // stars
        for (int j = 1; j <= 2 * n - 2 * i + 1; j++)
        {
            cout << "* ";
        }
        // spaces
        for (int j = 1; j <= i - 1; j++)
        {
            cout << "  ";
        }

        cout << endl;
    }
}

void print9(int n)
{
    print7(n);
    print8(n);
}

void print10(int n)
{
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        int stars = i;
        if (i > n)
            stars = 2 * n - i;
        for (int j = 1; j <= stars; j++)
        {
            cout << "* ";
        }

        cout << endl;
    }
}

void print11(int n)
{

    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= i; j++)
        {
            if ((i + j) % 2 == 0)
            {
                cout << "1 ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

void print12(int n)
{
    for (int i = 1; i <= n; i++)
    {
        // numbers
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }

        // spaces
        for (int j = 1; j <= 2 * n - 2 * i; j++)
        {
            cout << "  ";
        }

        // numbers

        for (int j = i; j != 0; j--)
        {
            cout << j << " ";
        }

        cout << endl;
    }
}

void print13(int n)
{
    int start = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << start << " ";
            start++;
        }
        cout << endl;
    }
}

void print14(int n)
{

    for (int i = 1; i <= n; i++)
    {
        char start = 'A';
        for (int j = 1; j <= i; j++)
        {
            cout << start << ' ';
            start++;
        }
        cout << endl;
    }
}

void print15(int n)
{
    for (int i = 1; i <= n; i++)
    {
        char start = 'A';
        for (int j = n; j >= i; j--)
        {
            cout << start << ' ';
            start++;
        }
        cout << endl;
    }
}

void print16(int n)
{
    char start = 'A';
    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= i; j++)
        {
            cout << start << ' ';
        }
        start++;

        cout << endl;
    }
}

void print17(int n)
{
    for (int i = 1; i <= n; i++)
    {

        // spaces
        for (int j = n - 1; j >= i; j--)
        {
            cout << "  ";
        }

        // characters
        char start = 'A';
        for (int j = 1; j <= 2 * i - 1; j++)
        {
            if (j <= i)
            {
                cout << start << ' ';
                start++;
            }
            else
            {
                start = start - 2;
                cout << start << ' ';
                start++;
            }
        }

        // spaces
        for (int j = n - 1; j >= i; j--)
        {
            cout << "  ";
        }

        cout << endl;
    }
}

void print18(int n)
{

    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= i; j++)
        {
            char c = 'A' + n - 1 - i + j;
            cout << c << ' ';
        }

        cout << endl;
    }
}

void print19(int n)
{
    int spaces = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {

            cout << '*' << ' ';
        }

        for (int j = 1; j <= spaces; j++)
        {
            cout << "  ";
        }
        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << '*' << ' ';
        }
        spaces += 2;
        cout << endl;
    }
    spaces = 2 * n - 2;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {

            cout << '*' << ' ';
        }

        for (int j = 1; j <= spaces; j++)
        {
            cout << "  ";
        }
        for (int j = 1; j <= i; j++)
        {
            cout << '*' << ' ';
        }
        spaces -= 2;
        cout << endl;
    }
}

void print20(int n)
{
    int spaces = 2 * n - 2;
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        // stars
        int stars = i;
        if (i > n)
            stars = 2 * n - i;
        for (int j = 1; j <= stars; j++)
        {
            {
                cout << '*' << ' ';
            }
        }

        // spaces

        for (int j = 1; j <= spaces; j++)
        {
            cout << "  ";
        }

        // stars
        for (int j = 1; j <= stars; j++)
        {
            {
                cout << '*' << ' ';
            }
        }

        if (i < n)
            spaces -= 2;
        else
            spaces += 2;

        cout << endl;
    }
}

void print21(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j == 1 || j == n || i == 1 || i == n)
            {
                cout << '*' << ' ';
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

void print22(int n)
{
    for (int i = 1; i <= 2*n-1; i++)
    {
        for(int j = 1; j <= 2*n-1; j++)
        {
            int top = i-1;
            int left = j-1;
            int bottom = (2*n-2)-i+1;
            int right = (2*n-2)-j+1;
            cout << n-min(min(left,top),min(right,bottom)) << ' ';
        }
        cout << endl;
    }
}

void print23(int n)
{                                           // sample output
                                            // 333222111
                                            // 332211
                                            // 321
    
    
    for(int i = n; i >= 1; i--)
    {
        for(int num = n; num >= 1; num--)
        {
         for(int j = 1; j <= i; j++)
         {
            cout << num;            
         }
        }
        cout << endl;
       

    }
    

}

int main()
{
    int n = 3;

    print23(n);

    return 0;
}