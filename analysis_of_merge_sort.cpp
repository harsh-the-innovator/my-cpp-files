#include<iostream>
#include<cstdlib>
#include<fstream>
#include<chrono>
#include<ctime>
#include<time.h>
#include<iomanip>
using namespace std::chrono;
using namespace std;
double avgtime = 0.0;
double timegap=0.0;
void merge(int a[],int l[],int r[],int n)
{
    int i=0,j=0,k=0;
    int nL,nR;//length of left and right
    nL = n/2;
    nR = n-nL;
    
    while(i<nL && j<nR)
    {
        if(l[i]<r[j])
        {
            a[k] = l[i];
            i = i+1;
        }
        else
        {
            a[k] = r[j];
            j = j+1;
        }
        k = k+1;
    }
    
    //when one of the two sub lists is full use then number will be taken from other sub list
    while(i<nL)
    {
        a[k] = l[i];
        i = i+1;
        k = k+1;
    }
    
    while(j<nR)
    {
        a[k] = r[j];
        j = j+1;
        k = k+1;
    }
    
}

//function for merge sort
void merge_sort(int a[],int n)
{
    if(n<2)
        return;
    else
    {
        int mid=n/2;
        int left[mid],right[n-mid];
        for(int i=0;i<mid;i++)
        {
            left[i] = a[i];
        }
        for(int i=mid;i<n;i++)
        {
            right[i-mid] = a[i];
        }
    
        merge_sort(left,mid);
        merge_sort(right,n-mid);
        merge(a,left,right,n);
    }
}
int main(){
    ofstream fout;
    int n;
    fout.open("mergesort.csv", ios::out | ios::app);
    for(int n=500;n<=5000;n+=500){
        int arr[n];
        avgtime = 0.0;
        srand(unsigned(time(0)));
        for(int i=0;i<10000;i++){
            for(int i=0;i<n;i++){
                arr[i] = rand()%(n)+1;
            }

            auto start = chrono::high_resolution_clock::now();
            merge_sort(arr,n);
            auto end = chrono::high_resolution_clock::now();
            
            timegap = chrono::duration_cast<chrono::nanoseconds>(end-start).count();
            timegap = timegap*1e-9;
            avgtime = avgtime + timegap;
            fout<<n<<","<<timegap<<endl;

        }
        std::cout<<"Average time("<<n<<")"<<","<<fixed<<avgtime/10000<<endl;
    }
    fout.close();
    return 0;
}