#include<iostream>
using namespace std;
template <typename T1,typename T2>
void func(T1 a,T2 b){
    std::cout<<a<<" "<<b;
}

template <typename T>
T maxx(T a,T b){
    return (a>b) ? a : b;
}

int main()
{
    func<int,double>(10,20.2);
    std::cout<<endl;
    std::cout<<maxx<int>(20,30)<<std::endl;
    return 0;
}
