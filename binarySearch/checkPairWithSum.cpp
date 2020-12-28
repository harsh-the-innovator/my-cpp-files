// find if there is a pair with given sum in a sorted array
// in unsorted you can use hashing
// in sorted two pointer approach is best
#include <bits/stdc++.h>
using namespace std;
bool isPair(int arr[], int n, int x)
{
    int left = 0, right = n - 1;
    while (left < right)
    {
        int sum = arr[left] + arr[right];
        if (sum == x)
        {
            return true;
        }
        else if (sum > x)
        {
            right--;
        }
        else
        {
            left++;
        }
    }
    return false;
}
int main()
{
    int arr[] = {2, 5, 8, 12, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 17;
    cout << isPair(arr, n, x) << endl;
}