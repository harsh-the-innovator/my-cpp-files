#include<iostream>
using namespace std;
int main()
{
    int a=4,b=8;
    int *p1,*p2;
    int temp;
    cout<<"Values before swapping:\n"<<"a="<<a<<" "<<"b="<<b;
    p1 = &a;
    p2 = &b;

    //swappping
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;

    cout<<"\nValues after swapping:\n";
    cout<<"a="<<a<<" "<<"b="<<b;
    return 0;
}
