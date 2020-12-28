#include<iostream>
using namespace std;
int main()
{
    //in binary search the array is to be sorted
    int arr[5] = {1,8,18,21,30};
    int first = 0,last = 4;
    int num,mid;
    cout<<"Enter number to be find:\n";
    cin>>num;

    do{
        mid = (first+last)/2;
        if(arr[mid]==num)
        {
            cout<<"Found the number at location "<<mid+1;
            break;
        }
        else if(arr[mid]<num)
        {
            first = mid+1;
        }
        else
            last = mid-1;
    }
    while(first<=last);

    if(first>last){
        cout<<"Element not found\n";
    }
}
