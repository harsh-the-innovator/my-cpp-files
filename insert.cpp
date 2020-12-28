#include<iostream>
using namespace std;
int main()
{
    char option;
    int a[10];
    int num,index;
    cout<<"Enter the array of 5 numbers:\n";
    for(int i=0;i<5;i++)
    {
        cin>>a[i];
    }
    cout<<"Original array:\n";
    for(int i=0;i<5;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\nEnter the number to be inserted:";
    cin>>num;
    cout<<"Index:";
    cin>>index;

    //algorithm for insertion
    for(int i=6;i>index;i--)
    {
        a[i] = a[i-1];
    }
    a[index] = num;
    cout<<"\nArray after insertion:\n";
    for(int i=0;i<6;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
