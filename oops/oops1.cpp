
//////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////[       OOPS Concepts       ]////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////



#include<bits/stdc++.h>
using namespace std;


// Collection of objects is called class. It is a logical entity.
class Hero{



private:
//properties of an object
string name="Superman";
char health;
string level;









//behavoir of an object of real world
//this is a set function which is set value of the private member

public:


///constructor
//there are many type of constructor what we call 
// that depend upon the parameter of the constructor

Hero(){

    cout<<"constructor called"<<endl;
}

Hero(string name){
    this->name=name;
}


Hero (string name,char level){
    this->name=name;
    this->level=level;
}

/////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////[    COPY CONSTRUCTOR     ]///////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////

// Hero( Hero &C){
//     this->level=C.level;
//     // this->name=C.name;
//     this->health=C.health;
// }



void sethealth(char health){
    this->health=health;
}

void setlevel(string level){
    this->level=level;
}

void setname(string name){
    this->name=name;
}


void Attack(){


cout<<"[  Player name:>>"<<name<<",  level of palyer:  "<<level<<",  and health :"<<health<<"  ]"<<endl;
}


//static allocation distructor autometically called
//but in dynamically we called distructor manually
~Hero(){
    cout<<"distructor called"<<endl;
}


// Padding in Cpp
// Size of the class should be sum of all the 
// non-static data member+ padding, which is like below:
// Above is the alignment of class A and that's why the size of the class is 8 Bytes. Static data members and member functions have no contribution.


};

int main(){

Hero Ramesh;


Ramesh.sethealth('A');
Ramesh.setlevel("30");
Ramesh.setname("shahid kapoor");
// Ramesh.health='2';
// Ramesh.level='A';
// Ramesh.Attack();
//////////////////////////////////////////////////////////////////////////////////////
// dynamic allocation 

Hero *dyanamically =new Hero;
// manually called distructor
delete dyanamically;
//////////////////////////////////////////////////////////////////////////////////////
// cout<<Ramesh.health<<endl;
// cout<<Ramesh.level<<endl;
// Ramesh.Attack();



//constructor called in which one parameter only name
// Hero Mukesh("Ironman");
// Mukesh.Attack();


//another construcntor called in which two parameter name and level
// Hero Bipin("SpiderMan",'A');
// Bipin.Attack();

//////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////Copy Constructor////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////

// Hero Awneesh(Ramesh);
// Awneesh.Attack();

//////////////////////////////////////////////////////////////////////////////////////
////////////////////////////// Shallow Copy and Deep Copy////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////


Hero Awneesh(Ramesh);
// Awneesh.Attack();

Ramesh.setname("shivjeet");
Ramesh.Attack();


Awneesh.Attack();



    return 0;
}