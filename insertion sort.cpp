#include<iostream>
using namespace std;
int main(){
    int arr[5] = {4,2,9,7,1};
    int key;
    int i,j;

    for(j=1;j<=4;j++){
        key = arr[j];

        i = j-1;
        while(i>=0 && arr[i]>key){
            arr[i+1] = arr[i];
            i = i-1;
        }
        arr[i+1] = key;
    }

    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
}
