#include<iostream>
using namespace std;
int main(){
    bool flag;
    int arr[5] = {4,2,7,5,9};
    for(int k=0;k<=3;k++){
        flag = 0;
        for(int i=0;i<=4-k;i++){
            if(arr[i]>arr[i+1]){
                swap(arr[i],arr[i+1]);
                flag = 1;
            }
        }
        if(flag==0)
            break;
    }

    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
}
