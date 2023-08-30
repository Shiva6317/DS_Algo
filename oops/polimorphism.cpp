#include<iostream>
using namespace std;
// polimorphism
//same thing store in deffrents froms
// 1-compile time polimorphism
// [function overloading and operator overloading]
// 2-run time polimorphism
// []


class A{
    public:

    void sayhello(){
        cout<<"hello shivjeet"<<endl;
    }
    // int sayhello(){
    //     cout<<"hello shivjeet"<<endl;
    //     return 0;
    // }
    void sayhello(string name){
        cout<<"hello " <<name<<endl;
    }


};


class B{

    public:

};




int main(){

A obj1;
obj1.sayhello();
obj1.sayhello("shivjeet");



    return 0;
}