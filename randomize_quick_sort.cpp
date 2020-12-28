#include<iostream>
#include<cstdlib>
#include<time.h>
#include<chrono>
#include<ctime>
#include<algorithm>
using namespace std::chrono;
using namespace std;
double avgtime = 0.0;
double timegap=0.0;

int partition(int a[],int start,int end)
{
    int temp;
    int pivot = a[end];
    int pIndex = start;
    for(int i=start;i<=end-1;i++)
    {
        if(a[i]<pivot)
        {
            //swap
            temp = a[i];
            a[i] = a[pIndex];
            a[pIndex] = temp;
            //
            
            
            pIndex = pIndex+1;
        }
        
    }
    
    //swapping of pivot and the element at pIndex
    temp = a[pIndex];
    a[pIndex] = a[end];
    a[end] = temp;
    
    return pIndex;
}

int generateRandomPivot(int a[],int low,int high){

    srand(unsigned(time(0)));
    int randomnumber = low + rand() % (high - low); 
    swap(a[high],a[randomnumber]);
    return partition(a,low,high);
}

void quick_sort(int a[],int start,int end)
{

    if(start<end)
    {
        int pIndex = generateRandomPivot(a,start,end);
        quick_sort(a,start,pIndex-1);
        quick_sort(a,pIndex+1,end);
    }
}

int main(){
    int n;
    for(int n=500;n<=5000;n+=500){
        int arr[n];
        srand(unsigned(time(0)));
        for(int i=0;i<10000;i++){
            for(int i=0;i<n;i++){
                arr[i] = rand()%(n) + 1;
            }   

            auto start = chrono::high_resolution_clock::now();
            quick_sort(arr,0,n-1);
            auto end = chrono::high_resolution_clock::now();
            timegap = chrono::duration_cast<chrono::nanoseconds>(end-start).count();
            timegap = timegap*1e-9;
            avgtime = avgtime + timegap;
        }
        std::cout<<"Average time("<<n<<")"<<","<<fixed<<avgtime/10000<<endl;
       
    }
}