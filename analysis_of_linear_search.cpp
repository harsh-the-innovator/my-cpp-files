#include<iostream>
#include<cstdlib>
#include<fstream>
#include<chrono>
#include<ctime>
#include<time.h>
#include<iomanip>
using namespace std;
using namespace std::chrono;
double favcount;
double timegap=0;
double avgtime;
int linearSearch(int a[],int key,int n){
    int pos;
    bool found = false;

    auto start = chrono::high_resolution_clock::now();

    for(int i=0;i<n;i++){
        if(a[i]==key){
            pos = i;
            found = true;
            break;
        }
    }

    auto end = chrono::high_resolution_clock::now();
    timegap = chrono::duration_cast<chrono::nanoseconds>(end-start).count();
    timegap = timegap*1e-9;
    avgtime = avgtime + timegap;

    if(found)
        return pos;
    else
        return -1;
}

int main(){
    int n,key,index;
    string status;
    ofstream fout;
    fout.open("sample.csv",ios::out | ios::app);
    for(int n=1000;n<=5000;n+=500){
        avgtime = 0.0;
        favcount = 0.0;
        int arr[n];
        srand((unsigned) time(0));
        for(int i=0;i<100000;i++){
        for(int i=0;i<n;i++){
            arr[i] = rand()%(n) + 1;
        }
        key = rand()%(n)+1;
        index = linearSearch(arr,key,n);

        if(index==-1){
            status = "not found";
        }else{
            status = "found";
            favcount++;
        }

        if(status=="found"){
            fout<<fixed<<setprecision(9)<<n<<","<<timegap<<","<<index<<","<<status<<endl;
        }else{
            fout<<fixed<<setprecision(9)<<n<<","<<timegap<<","<<index<<","<<status<<endl;
        }
    }
    fout<<fixed<<setprecision(9)<<"Avg("<<n<<")"<<","<<avgtime/100000<<endl;

    std::cout<<"Average time("<<n<<")"<<","<<fixed<<setprecision(9)<<avgtime/100000<<" count="<<favcount<<endl;
    std::cout<<"Prob("<<n<<")"<<favcount/(100000)<<endl<<endl;
    }

    fout.close();
    return 0;
}

