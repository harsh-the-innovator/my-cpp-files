#include <bits/stdc++.h>
using namespace std;

void maxHeapify(int a[], int n, int i)
{
    int lt = 2 * i + 1;
    int rt = 2 * i + 2;
    int largest = i;

    if (lt < n && a[lt] > a[i])
    {
        largest = lt;
    }
    if (rt < n && a[rt] > a[largest])
    {
        largest = rt;
    }

    if (largest != i)
    {
        swap(a[largest], a[i]);
        maxHeapify(a, n, largest);
    }
}

void buildHeap(int a[], int n)
{
    for (int i = (n - 2) / 2; i >= 0; i--)
    {
        maxHeapify(a, n, i);
    }
}

void heapSort(int a[], int n)
{
    buildHeap(a, n);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(a[0], a[i]);
        maxHeapify(a, i, 0);
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
    heapSort(a, n);
    cout << "Sorted list:\n";
    print(a, n);
}

// if we use min heap we will get sorted in decreasing order