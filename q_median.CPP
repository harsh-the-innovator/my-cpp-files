#include<iostream>
#include<cstdlib>
#include<time.h>
#include<chrono>
#include<ctime>
#include<algorithm>
#include<fstream>

using namespace std::chrono;
using namespace std;
double un_avgtime = 0.0;
double s_avgtime = 0.0;
double timegap=0.0;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[],int low,int high,int mid)
{

    int j;
for (j=low; j<high; j++)
    if (a[j] == mid)
           break;
    swap(&a[j],&a[high]);
    int pivot=a[high];
    int i=low-1;
    for(int j=low;j<high;j++)
    {
        if(a[j]<pivot)
        {
            swap(&a[j],&a[i]);
            i++;
        }

    }

    swap(&a[i+1],&a[high]);
    return i+1;
}

int median_func(int a[],int n)
{

    sort(a,a+n);
    return a[n/2];
}

int medianofmedian(int arr[],int low, int high, int mid)
{
    if(mid>0 && mid<high-low+1)
    {
    int n=high-low+1;
    int i;
    int main_mid,median[(n+4)/5];
       for(i=0;i<n/5;i++)
       {
           median[i]=median_func(arr+low+i*5,5);
       }
       if(5*i<n)
       {
            median[i] = median_func(arr+low+i*5,n%5);
            i++;

       }


       if(i==1)
       {
           main_mid=median[i-1];
       }
       else
       {
           main_mid=medianofmedian(median,0,i-1,i/2);
       }

       if(low==high)
        {
         return high;
         }

       int pos= partition(arr,low,high,main_mid);


       if(pos-low==mid)
       {
           return arr[pos];
       }
       else if(pos-low<mid)
       {
           return medianofmedian(arr,pos+1,high,mid-pos+high-1);
       }
       else
       {
           medianofmedian(arr,low,pos-1,mid);
       }
    }
}

void quick_sort(int arr[], int low ,int high)
{
if(low<high)
{

int temp_mid=(low+high+1)/2;
int mid=medianofmedian(arr,low,high,temp_mid);
int p=partition(arr,low,high,mid);
quick_sort(arr,low,p-1);
quick_sort(arr,p+1,high);
}
}

int main(){

    ofstream fout;
    fout.open("median_quicksort.csv",ios::out | ios::app);
    int n;
    for(int n=500;n<=25000;n+=500){
        un_avgtime = 0;
        s_avgtime = 0;
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
            un_avgtime = un_avgtime + timegap;

           //qsort on sorted array
            auto s_start = chrono::high_resolution_clock::now();
            quick_sort(arr,0,n-1);
            auto s_end = chrono::high_resolution_clock::now();
            timegap = chrono::duration_cast<chrono::nanoseconds>(s_end-s_start).count();
            timegap = timegap*1e-9;
            s_avgtime = s_avgtime + timegap;
        }
        std::cout<<"Average time"<<" "<<fixed<<un_avgtime/10000<<" "<<fixed<<s_avgtime/10000<<endl;
        fout<<n<<","<<un_avgtime/10000<<","<<s_avgtime/10000<<endl;
    }
    fout.close();
  return 0;  
}