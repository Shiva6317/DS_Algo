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








 int main()
{

Dog ani1;

ani1.barking();
    return 0;
}