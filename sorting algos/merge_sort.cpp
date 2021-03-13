#include <iostream>
using namespace std;
void Merge(int a[], int l, int m, int r)
{
    int nL = m - l + 1;
    int nR = r - m;
    int left[nL], right[nR];

    for (int i = 0; i < nL; i++)
        left[i] = a[l + i];
    for (int i = 0; i < nR; i++)
        right[i] = a[m + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < nL && j < nR)
    {
        if (left[i] <= right[j])
        {
            a[k] = left[i];
            i = i + 1;
        }
        else
        {
            a[k] = right[j];
            j = j + 1;
        }
        k = k + 1;
    }

    while (i < nL)
    {
        a[k] = left[i];
        i = i + 1;
        k = k + 1;
    }
    while (j < nR)
    {
        a[k] = right[j];
        j = j + 1;
        k = k + 1;
    }
}
void MergeSort(int a[], int l, int r)
{
    int nL, nR;
    if (l < r)
    {
        int mid = (l + r) / 2;
        MergeSort(a, l, mid);
        MergeSort(a, mid + 1, r);
        Merge(a, l, mid, r);
    }
}
int main()
{
    int arr[] = {4, 2, 7, 4, 9, 70, 10, 34};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "\n"
         << "Original Array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << " " << arr[i];
    }
    MergeSort(arr, 0, n - 1);

    cout << "\nSorted Array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << " " << arr[i];
    }
}
