#include <bits/stdc++.h>
using namespace std;

class Base
{
public:
    int base_var;
    virtual void print() = 0; //pure virtual function   //do nothing function - used for making abstract base class

    // it is compulsory that we have to redefine the print function in the derived class if we are making pure virtual function
};

class Derived1 : public Base
{
public:
    int derived_var1;
    void print()
    {
        cout << "DERIVED CLASS 1 PRINT FUNCTION " << derived_var1 << endl;
    }
};

class Derived2 : public Base
{
    int derived_var2;
    void print()
    {
        cout << "DERIVED CLASS 2 PRINT FUNCTION " << derived_var2 << endl;
    }
};

int main()
{
    Base *base_ptr;

    Derived2 derived2Obj;

    base_ptr = &derived2Obj;
    base_ptr->print();
}
