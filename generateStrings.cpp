//we have to generate all strings of length n from numbers 0 to k-1
#include <iostream>
using namespace std;
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void generateString(int arr[], int n, int k, int size)
{
    if (n < 1)
    {
        printArray(arr, size);
        return;
    }

    for (int i = 0; i < k; i++)
    {
        arr[n - 1] = i;
        generateString(arr, n - 1, k, size);
    }
}
int main()
{
    int n = 3, k = 3;
    int arr[n];
    int size = n;
    generateString(arr, n, k, size);
}