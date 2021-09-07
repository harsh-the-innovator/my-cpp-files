#include <bits/stdc++.h>
using namespace std;

class Base
{
public:
    int base_var;
    virtual void print()
    {
        cout << "BASE CLASS PRINT FUNCTION " << base_var << endl;
    }
};

class Derived : public Base
{
public:
    int derived_var;
    void print()
    {
        cout << "DERIVED CLASS PRINT FUNCTION " << derived_var << endl;
    }
};

int main()
{
    Base *basePtr;
    Base baseObj;
    Derived derivedObj;

    basePtr = &derivedObj;

    basePtr->print(); // this will call derived class print function because we have made print function virtual in base class
}

//  RULES FOR VIRTUAL FUNCTIONS

// 1. THEY CANNOT BE STATIC
// 2. THEY ARE ACCESSED BY OBJECT POINTERS
// 3. VIRTUAL FUNCTIONS CAN BE FRIEND OF ANOTHER CLASS
// 4. A VIRTUAL FUNCTION IN BASE CLASS MIGHT NOT BE USED
// 5. IF A FUNCTION IS NOT REDEFINED IN DERIVED CLASS AND WE CALL THE FUNCTION , THEN BASE CLASS FUNCTION WILL BE CALLED