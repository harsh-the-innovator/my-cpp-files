#include <iostream>
using namespace std;

int partition(int arr[], int start, int end)
{
    int pIndex = start;
    int pivot = arr[end];

    for (int i = start; i <= end - 1; i++)
    {
        if (arr[i] <= pivot)
        {
            swap(arr[i], arr[pIndex]);
            pIndex++;
        }
    }

    swap(arr[pIndex], arr[end]);

    return pIndex;
}

void quickSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int pIndex = partition(arr, start, end);
        quickSort(arr, start, pIndex - 1);
        quickSort(arr, pIndex + 1, end);
    }
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1, -4, -5};
    int n = 7;
    quickSort(arr, 0, n - 1);
    print(arr, n);

    return 0;
}
