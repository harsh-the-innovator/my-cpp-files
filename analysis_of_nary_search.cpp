#include<iostream>
#include<cstdlib>
#include<fstream>
#include<chrono>
#include<ctime>
#include<time.h>
#include<iomanip>
#include<algorithm>
using namespace std::chrono;
using namespace std;
int narySearch(int arr[],int low,int high,int n,int key){
    if(low<=high){
        int pivot[n-1];
        for(int j=1;j<n;j++){
            pivot[j] = low + j*(high-low)/n;
        }
        int i=0;
        int c=0;
        while(i<n){
            if(arr[pivot[i]]==key){
                return pivot[i];
            }else if(arr[pivot[i]]>key){
                if(i>1){
                    low = pivot[i-1];
                }
                i++;
                c++;
                break;
            }else{
                i++;
            }
        }
        i--;
        if(c==1)
            return narySearch(arr,low,pivot[i]-1,n,key);
        else if(arr[pivot[i]]<key)
            return narySearch(arr,pivot[i]+1,high,n,key);
        else
            return -1;
    }
    else{
        return -1;
    }
}
int main(){
    ofstream fout;
    fout.open("narySearch.csv",ios::out | ios::app);
    for(int division=2;division<=15;division++){
        int size1 = 6000;
        int frequency = 1000;
        double total = 0,presence = 0;
        int arr[size1];
        srand(time(0));

        for(int i=0;i<frequency;i++){
            for(int j=0;j<size1;j++){
                arr[j] = rand()%(int(1.4*size1)) + 1;
            }
            int key = rand()%(int(1.4*size1)) + 1;
            sort(arr,arr+size1);

            auto start = chrono::high_resolution_clock::now();
            int result = narySearch(arr,0,size1-1,division,key);
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<std::chrono::microseconds>(end-start).count();

            if(result!=-1){
                presence++;
            }

            total += duration;

        }
        double time = total/frequency;
        double probability = presence/frequency;

        cout<<fixed<<setprecision(9)<<"("<<division<<") "<<time<<endl;
        fout<<division<<","<<time<<","<<presence<<","<<frequency-presence<<","<<probability<<endl;
    }
    fout.close();
    return 0;
}