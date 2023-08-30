#include <iostream>
using namespace std;

class Animal
{
public:
    int age;
    int name;
    int height;

    void barking()
    {
        cout << "barking" << endl;
    }

};

class Dog:public Animal{

    public:
    string colour;
};


class Germansepherd:public Dog{

};







 int main()
{

Germansepherd obj1;
obj1.barking();
    return 0;
}