#include<iostream>
#include<chrono>
#include<ctime>
#include<time.h>
#include<algorithm>
#include<iomanip>
#include<fstream>
using namespace std;
using namespace std::chrono;
double timegap1 = 0.0;
double timegap2 = 0.0;
double avgtime1;
double avgtime2;
double favcount1;
double favcount2;
int stepcount;
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
    timegap1 = chrono::duration_cast<chrono::nanoseconds>(end-start).count();
    timegap1 = timegap1*1e-9;
    avgtime1 = avgtime1 + timegap1;

    if(found)
        return pos;
    else
        return -1;
}

int BinarySearch(int a[],int low,int high,int k){
    
    while(low<=high){
        int mid = (low+high)/2;
        if(a[mid]==k){
            stepcount++;
            return mid;
        }  
        else if(k<a[mid]){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return -1;
    
}
int main(){
    ofstream fbinary,flinear;
    string status1,status2;
    fbinary.open("binaryfile.csv",ios::out | ios::app);
    flinear.open("linearfile.csv",ios::out | ios::app);

    for(int n=500;n<=3500;n+=500){
        int arr[n];
        avgtime1 = 0.0;
        avgtime2 = 0.0;
        favcount1 = 0.0;
        favcount2 = 0.0;
        stepcount = 0;
        srand(unsigned(time(0)));
        for(int i=0;i<100000;i++){
            for(int i=0;i<n;i++){
                arr[i] = rand()%n + 100;
            }
            sort(arr,arr+n);
            int key = rand()%n + 100;

            int index1 = linearSearch(arr,key,n);

            auto start2 = chrono::high_resolution_clock::now();
            int index2 = BinarySearch(arr,0,n-1,key);
            auto end2 = chrono::high_resolution_clock::now();


            timegap2 = chrono::duration_cast<chrono::nanoseconds>(end2-start2).count();
            timegap2 = timegap2*1e-9;
            avgtime2 = avgtime2 + timegap2;

            if(index1==-1){
                status1 = "not found";
            }else{
                status1 = "found";
                favcount1++;
            }

            if(index2==-1)
                status2="not found";
            else{
                status2 = "found";
                favcount2++;
            }
                
            
            if(status1=="found")
                flinear<<fixed<<setprecision(9)<<n<<","<<timegap1<<","<<index1<<","<<status1<<endl;
            else
                flinear<<fixed<<setprecision(9)<<n<<","<<timegap1<<","<<index1<<","<<status1<<endl;
            
            if(status2=="found"){
                fbinary<<fixed<<setprecision(9)<<n<<","<<timegap2<<","<<index2<<","<<status2<<endl;
            }else{
                fbinary<<fixed<<setprecision(9)<<n<<","<<timegap2<<","<<index2<<","<<status2<<endl;
            }
        }
        std::cout<<"(Linear)Average time("<<n<<")"<<","<<fixed<<setprecision(9)<<avgtime1/100000<<" count="<<favcount1<<" Prob="<<favcount1/(100000)<<endl;
        std::cout<<"(Binary)Average time("<<n<<")"<<","<<fixed<<setprecision(9)<<avgtime2/100000<<" count="<<favcount2<<" Prob="<<favcount2/(100000)<<endl;
        std::cout<<stepcount/100000<<endl;
        std::cout<<endl;
        
    }
    fbinary.close();
    flinear.close();
    return 0;
}