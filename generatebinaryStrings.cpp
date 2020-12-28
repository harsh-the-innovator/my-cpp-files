//its a backtracking problem
#include <iostream>
using namespace std;
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}
void generateBinaryString(int arr[], int n, int i)
{
    if (n == i)
    {
        printArray(arr, n);
        return;
    }

    arr[i] = 0;
    generateBinaryString(arr, n, i + 1);
    arr[i] = 1;
    generateBinaryString(arr, n, i + 1);
}
int main()
{
    int n;
    cout << "Enter n:";
    cin >> n;
    int arr[n];
    generateBinaryString(arr, n, 0);
    return 0;
}