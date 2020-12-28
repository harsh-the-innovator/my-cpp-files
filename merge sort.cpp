#include<iostream>
using namespace std;
void Merge(int [],int [],int*);
void MergeSort(int *a,int n){
    int nL,nR;
    if(n<2)
        return;
    else{
        int mid = n/2;
    int left[mid],right[n-mid];

    for(int i=0;i<mid;i++){
        left[i] = a[i];
    }
    for(int i=mid;i<n;i++){
        right[i-mid] = a[i];
    }
    MergeSort(left,mid);
    MergeSort(right,n-mid);
    Merge(left,right,a);
    }

}
void Merge(int left[],int right[],int* a){
    int i,j,k;
    int nL = sizeof(left)/sizeof(left[0]);
    int nR = sizeof(right)/sizeof(right[0]);
    while(i<nL && j<nR){
        if(left[i] <= right[j]){
            a[k] = left[i];
            i = i+1;
        }else{
            a[k] = right[j];
            j = j+1;
        }
        k = k+1;
    }

    while(i<nL){
        a[k] = left[i];
        i = i+1;
        k = k+1;
    }
    while(j<nR){
        a[k] = right[j];
        j = j+1;
        k = k+1;
    }
}
int main(){
    int arr[8] = {4,2,7,4,9,70,10,34};
    cout<<"\n"<<"Original Array:";
    for(int i=0;i<8;i++)
    {
        cout<<" "<<arr[i];
    }
    MergeSort(arr,8);

    cout<<"Sorted Array:\n";
    for(int i=0;i<8;i++)
    {
        cout<<" "<<arr[i];
    }
}
