// A C++ program to put all negative
// numbers before positive numbers
#include <bits/stdc++.h>
using namespace std;

//method 1
//uisng partition process of quick sort
void rearrangeUsingPartition(int arr[], int n)
{
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            if (i != j)
            {
                swap(arr[i], arr[j]);
            }

            j++;
        }
    }
}

//method2
void rearrangeUsingTwoPointer(int arr[], int n)
{

    int i = 0, j = n - 1;

    while (i <= j)
    {
        if (arr[i] < 0 && arr[j] < 0)
        {
            i++;
        }
        else if (arr[i] > 0 && arr[j] < 0)
        {
            swap(arr[i++], arr[j--]);
        }
        else if (arr[i] > 0 && arr[j] > 0)
        {
            j--;
        }
        else
        {
            i++;
            j--;
        }
    }
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
    int n = sizeof(arr) / sizeof(arr[0]);
    // rearrangeUsingPartition(arr, n);
    rearrangeUsingTwoPointer(arr, n);
    display(arr, n);
}