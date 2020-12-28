#include<iostream>
using namespace std;
int main()
{
    int a[5];
    int num;
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
    cout<<"\nEnter the number to be deleted:";
    cin>>num;
    //search algorithm
    for(int i=0;i<5;i++)
    {
        if(a[i]==num)
        {
            for(int j=i;j<5;j++)
            {
                a[j]=a[j+1];
            }
            break;
        }
        else
            continue;
    }

    cout<<"\nNew Array:\n";
    for(int i=0;i<4;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n"<<a[5];
    return 0;
}
