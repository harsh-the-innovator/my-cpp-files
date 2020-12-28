#include<iostream>
#include<string>
#include<vector>
using namespace std;

template <typename T>
class Item{
private:
    string name;
    T value;
public:
    Item(string name,T value) : name{name},value{value}{};
    string get_name() const {return name;}
    T get_value() const {return value;}
};


int main(){

    Item<double> item1("Frank",100.87);
    std::cout<<item1.get_name()<<" "<<item1.get_value()<<std::endl;

    Item<string> item2("Frank","Professor");
    cout<<"\n";
    std::cout<<item2.get_name()<<" "<<item2.get_value()<<std::endl;


    //nested template
    Item< Item<string> > item3("Frank",{"Professor","hello"});
    cout<<"\n";
    cout<<item3.get_name()<<" "<<item3.get_value().get_name()<<" "<<item3.get_value().get_value()<<"\n";


}
