#include <iostream>
using namespace std;
int main(){
    int n;

    int minIndex;

    cout<<"Enter number of element to sort:";
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++){
        cout<<"\nEnter element:";
        cin>>arr[i];
    }

    for(int i=0;i<=n-2;i++){
        minIndex = i;
        for(int j=i+1;j<=n-1;j++){
            if(arr[i]<arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[i],arr[minIndex]);
    }

    cout<<"\nSorted array:\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
