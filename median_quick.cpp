#include<bits/stdc++.h>
using namespace std;
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
    swap(&a[j], &a[high]);
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


int main()
{
ofstream fout;
fout.open("med_quick.csv");
fout<<"time"<<","<<"worst_case_time"<<","<<"no_of_elements";
fout<<"\n";

for(int n=1000;n<21000;n+=1000)
{
        int f=1000;
        double t[f];
        double t1[f];
        double l=0;
        double l1=0;





    int arr[n];

    srand(time(0));
for(int m=0;m<f;m++)
  {
    for(int j=0;j<n;j++)
    {
        arr[j]=(rand()%(int((1.5*n))))+1;

    }

     auto time_start=chrono::high_resolution_clock::now();
    //sleep_for(nanoseconds(10));
    //st=clock();
    quick_sort(arr,0,n-1);

     //st=clock()-st;
    auto time_end=chrono::high_resolution_clock::now();
    auto dur=chrono::duration_cast<std::chrono::nanoseconds>(time_end-time_start).count();


    t[m]=dur;
    l+=t[m];

         auto time_start1=chrono::high_resolution_clock::now();
    //sleep_for(nanoseconds(10));
    //st=clock();
    quick_sort(arr,0,n-1);

     //st=clock()-st;
    auto time_end1=chrono::high_resolution_clock::now();
    auto dur1=chrono::duration_cast<std::chrono::nanoseconds>(time_end1-time_start1).count();


    t1[m]=dur1;
    l1+=t1[m];



}
    l=(l/f);
    l1=(l1/f);


    fout<<l<<","<<l1<<","<<n;
    fout<<"\n";

}
fout.close();
}
