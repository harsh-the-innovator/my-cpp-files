#include<bits/stdc++.h>
using namespace std;
int right(int i){
    return 2*i+2;
}
int left(int i){
    return 2*i+1;
}

void minHeapify(int arr[],int n,int i){
    int lt = left(i),rt = right(i);
    int smallest = i;
    if(lt<n && arr[lt]<arr[i]) smallest = lt;
    if(rt<n && arr[rt]<arr[smallest]) smallest = rt;
    if(smallest!=i){
        swap(arr[smallest],arr[i]);
        minHeapify(arr,n,i);
    }
}
void buildHeap(int arr[],int n){
    for(int i=(n-2)/2;i>=0;i--){
        minHeapify(arr,n,i);
    }
}
int main(){
    int arr[] = {10,5,20,2,4,8};
    buildHeap(arr,sizeof(arr)/sizeof(arr[0]));
    cout<<"After building heap:-\n";
    for(auto i : arr){
        cout<<i<<" ";
    }
    cout<<endl;
}