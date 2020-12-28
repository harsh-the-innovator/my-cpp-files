#include<iostream>
using namespace std;
int main()
{
    int a[5] = {2,4,6,3,9};
    int position;
    cout<<"Enter the position of number to be deleted:\n";
    cin>>position;
    for(int i=position;i<5;i++)
    {
        a[i] = a[i+1];
    }
    cout<<"New Array:\n";
    for(int i=0;i<4;i++)
    {
        cout<<a[i]<<" ";
    }
}
