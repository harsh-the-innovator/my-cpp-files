#include <bits/stdc++.h>
using namespace std;

class Base
{
public:
    int base_var = 0;
    void print()
    {
        cout << "BASE CLASS PRINT FUNCTION " << base_var << endl;
    }
};

class Derived : public Base
{
public:
    int derived_var = 0;
    void print()
    {
        cout << "DERIVED CLASS PRINT FUNCTION" << derived_var << endl;
    }
};

int main()
{
    Base *basePtr;
    Base baseObj;
    Derived derivedObj;

    basePtr = &derivedObj; //pointing base class pointer to derived class object
    basePtr->base_var = 34;
    basePtr->print(); //will call base class print function because pointer os of base class

    //basePtr->derived_var; //this will not work, will throw error

    Derived *derivedPtr;
    derivedPtr = &derivedObj;
    derivedPtr->derived_var = 100;
    derivedPtr->print(); //will call derived class print function
}