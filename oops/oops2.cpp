#include <bits/stdc++.h>
using namespace std;

class Human
{
public:
    string name;
    int weight;
    int height;
    int age;

    int getage()
    {
        return this->age;
    }

    void setage(int w)
    {
        this->age = w;
    }
};


//inheritence
class Male : public Human
{

public:
    string color;

    void sleeping()
    {

        cout << "Male is sleeping" << endl;
    }

};




int main()
{
Male object1;

cout<<object1.age<<endl;
cout<<object1.weight<<endl;
cout<<object1.height<<endl;
cout<<object1.color<<endl;





}