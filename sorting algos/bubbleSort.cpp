#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int a[], int n)
{
    bool swapped;
    for (int i = 0; i < n - 1; i++) //n-1 times pass we have to do
    {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++)
            if (a[j + 1] < a[j])
            {
                swap(a[j + 1], a[j]);
                swapped = true;
            }

        if (swapped == false) //for optimization // checking if already sorted
            break;
    }
}

void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    int a[] = {22,
               5,
               7,
               10,
               8,
               18};
    int n = sizeof(a) / sizeof(a[0]);

    cout << "Before sorting:\n";
    print(a, n);
    bubbleSort(a, n);
    cout << "Sorted list:\n";
    print(a, n);
}