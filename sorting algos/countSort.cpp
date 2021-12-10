#include <bits/stdc++.h>
using namespace std;
//see apna college video for better understanding
void countSort(int arr[], int n)
{
    int maxEl = arr[0];
    for (int i = 1; i < n; i++)
    {
        maxEl = max(maxEl, arr[i]);
    }

    //making count array to store count of every element
    //we can use map also to store count
    int count[maxEl + 1]{0};
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    // update the count array to position array
    for (int i = 1; i <= maxEl; i++)
    {
        count[i] += count[i - 1];
    }

    //Creating output array
    int output[n];
    for (int i = n - 1; i >= 0; i--)
    {
        count[arr[i]] -= 1;
        output[count[arr[i]]] = arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

int main()
{
    int arr[] = {1, 3, 2, 3, 4, 1, 6, 4, 3};

    int n = 9;

    countSort(arr, n);

    //print sorted array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}