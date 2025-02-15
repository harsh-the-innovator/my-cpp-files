#include <iostream>
using namespace std;

class Shallow
{
private:
    int *data;

public:
    void set_data(int d)
    {
        *data = d;
    }

    int get_data()
    {
        return *data;
    }

    Shallow(int d);                 //constructor
    Shallow(const Shallow &source); // copy constructor
    ~Shallow();                     // destructor
};

Shallow::Shallow(int d)
{
    data = new int;
    *data = d;
}

Shallow::Shallow(const Shallow &source) : data(source.data)
{
    cout << "Copy constructor - shallow " << endl;
}

Shallow::~Shallow()
{
    delete data;
    cout << "Destructor freeing data" << endl;
}

void display_shallow(Shallow s)
{
    cout << s.get_data() << endl;
}

int main()
{
    Shallow obj1{100};
    display_shallow(obj1);

    Shallow obj2{obj1};
    obj2.set_data(1000);

    return 0;
}