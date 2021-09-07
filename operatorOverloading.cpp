#include <bits/stdc++.h>
using namespace std;

class Complex
{
    int real, imag;

public:
    Complex() {}
    Complex(int real, int imag)
    {
        this->real = real;
        this->imag = imag;
    }

    Complex operator+(Complex const &obj)
    {
        Complex res;
        res.real = real + obj.real;
        res.imag = imag + obj.imag;

        return res;
    }

    void display();
};

void Complex::display()
{
    cout << real << " + i" << imag << endl;
}

int main()
{
    Complex c1(1, 2), c2(2, 3);
    Complex c3 = c1 + c2;
    c3.display();
}