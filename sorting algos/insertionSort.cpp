#include <bits/stdc++.h>
using namespace std;

//best case - sorted - O(n)
//worst case - reverse sorted - O(n^2)

void insertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int value = a[i];
        int hole = i;

        while (hole > 0 && a[hole - 1] > value)
        {
            a[hole] = a[hole - 1];
            hole--;
        }
        a[hole] = value;
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
    insertionSort(a, n);
    cout << "Sorted list:\n";
    print(a, n);
}