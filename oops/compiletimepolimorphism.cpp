#include <iostream>
using namespace std;

class Complex
{
private:
    int real, imag;

public:
    Complex(int r = 0, int i = 0)
    {
        real = r;
        imag = i;
    }
    // This is automatically called when '+' is used with
    // between two Complex objects
    Complex operator+(Complex const &b)
    {
        Complex a;
        a.real = real + b.real;
        a.imag = imag + b.imag;
        return a;
    }
    void print()
    {
        cout << real << " + " << imag << "i" << endl;
    }
};

class B
{
public:
    int a;
    int b;

    void add()
    {
        cout << "Answer" << a + b << endl;
    }
    // operater overloading

    int operator+(B &obj)
    {
        int value1 = this->a;
        int value2 = obj.a;
        return value2 - value1;
    }
};

class ComplexADD
{

public:
    int real;
    int imag;
    ComplexADD(int r = 0, int i = 0)
    {
        real = r;
        imag = i;
    }
    void operator+(ComplexADD &obj)
    {
        int real1 = this->real;
        int real2 = obj.real;
        int imag1 = this->imag;
        int imag2 = obj.imag;

        cout << "Answer = " << real1 + real2 << " + " << imag1 + imag2 << "i" << endl;
    }
};

int main()
{

    ComplexADD obj1(12, 4), obj2(34, 6);

    obj1+obj2;

    // {
    // B obj1,obj2;
    // obj1.a=34;
    // // obj1.b=36;
    // obj2.a=30;

    // cout<<"Answer  "<<obj1+obj2<<endl;
    // // obj1.add();

    // Complex c1(10, 5), c2(2, 4);
    // Complex c3 = c1 + c2; // An example call to "operator+"
    // c3.print();
}
