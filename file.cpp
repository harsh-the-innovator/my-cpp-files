#include<iostream>
using namespace std;
void isFibo(int num){
    int a =0, b= 1,f= 0;
    do {
        f= a+b;
        a=b;
        b=f;
        if(f == num){
        cout<<num;
        }
    }
    while(f<=num);
    
    
}

int main()
 {
     int arr[] {1,2,3,4,5,6,7,8,9,10,11};
     for(int i = 0; i<11 ; i++){
         isFibo(arr[i]);
     }
return 0;
}