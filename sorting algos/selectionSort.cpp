#include <bits/stdc++.h>
using namespace std;

void selectionSort(int a[], int n)
{
    for (int i = 0; i <= n - 2; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[minIndex])
            {
                minIndex = j;
            }
        }
        swap(a[i], a[minIndex]);
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
    selectionSort(a, n);
    cout << "Sorted list:\n";
    print(a, n);
}