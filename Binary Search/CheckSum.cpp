#include <iostream>
#include <string>
using namespace std;

// Function to add two binary strings
string binaryAdd(string a, string b)
{
    string result = "";
    int carry = 0;

    int i = a.length() - 1;
    int j = b.length() - 1;

    while (i >= 0 || j >= 0 || carry)
    {
        int sum = carry;

        if (i >= 0)
            sum += a[i--] - '0';
        if (j >= 0)
            sum += b[j--] - '0';

        result = char((sum % 2) + '0') + result;
        carry = sum / 2;
    }

    return result;
}

// Function to compute 1's complement
string onesComplement(string bin)
{
    for (int i = 0; i < bin.length(); i++)
    {
        bin[i] = (bin[i] == '0') ? '1' : '0';
    }
    return bin;
}

// Function to compute checksum
string checksum(string data, int blockSize)
{
    int n = data.length();

    // Pad with zeros if needed
    if (n % blockSize != 0)
    {
        int pad = blockSize - (n % blockSize);
        data = string(pad, '0') + data;
    }

    string sum = data.substr(0, blockSize);

    for (int i = blockSize; i < data.length(); i += blockSize)
    {
        string block = data.substr(i, blockSize);
        sum = binaryAdd(sum, block);

        // Handle overflow (carry-around)
        if (sum.length() > blockSize)
        {
            string carry = sum.substr(0, sum.length() - blockSize);
            sum = sum.substr(sum.length() - blockSize);
            sum = binaryAdd(sum, carry);
        }
    }

    // Final checksum = 1's complement
    return onesComplement(sum);
}

int main()
{
    string data;
    int blockSize;

    cout << "Enter binary data: ";
    cin >> data;

    cout << "Enter block size: ";
    cin >> blockSize;

    string result = checksum(data, blockSize);

    cout << "Checksum: " << result << endl;

    return 0;
}