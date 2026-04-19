#include <iostream>
using namespace std;

void display(vector<int> &arr)
{
    for (auto x : arr)
    {
        cout << x << ' ';
    }
    cout << endl;
}

int getMedian1(vector<int> &arr1, vector<int> &arr2)
{
    int n1 = arr1.size();
    int n2 = arr2.size();
    int n = n1 + n2;
    int ind1 = (n / 2), ind2 = (n / 2) - 1;
    int ele1 = -1, ele2 = -1;

    int i = 0, j = 0, count = 0;

    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            if (count == ind1)
            {
                ele1 = arr1[i];
            }
            if (count == ind2)
            {
                ele2 = arr1[i];
            }
            count++;
            i++;
        }

        else
        {
            if (count == ind1)
            {
                ele1 = arr2[j];
            }
            if (count == ind2)
            {
                ele2 = arr2[j];
            }
            count++;
            j++;
        }
    }

    while (i < n1)
    {
        if (count == ind1)
        {
            ele1 = arr1[i];
        }
        if (count == ind2)
        {
            ele2 = arr1[i];
        }
        count++;
        i++;
    }

    while (j < n2)
    {
        if (count == ind1)
        {
            ele1 = arr2[j];
        }
        if (count == ind2)
        {
            ele2 = arr2[j];
        }
        count++;
        j++;
    }

    if (n % 2 == 1)
    {
        return ele1;
    }
    return (double)(double(ele1 + ele2) / 2.0);
}

int main()
{

    vector<int> arr1 = {1, 2, 4, 8, 16, 32};
    vector<int> arr2 = {1, 3, 9, 27, 81};

    cout << "Array1 : ";
    display(arr1);
    cout << "Array2 : ";
    display(arr2);



    int median = getMedian1(arr1, arr2);

    cout << "Median of Array1 and Array2 : " << median;

    

    return 0;
}