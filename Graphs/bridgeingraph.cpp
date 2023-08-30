#include<bits/stdc++.h>
using namespace std;

class graph{
public:
map<int,list<int>>adjlist;


void addedge(int u,int v){
    adjlist[u].push_back(v);
    adjlist[v].push_back(u);
}


void print(){
    for(auto i:adjlist){
        cout<<i.first<<"->"<<"{";
        for(auto j:i.second){
            cout<<j<<",";
        }
        cout<<"}"<<endl;
    }
}

    





};

int main(){

graph g;

g.addedge(2,0);
g.addedge(1,0);
g.addedge(2,1);
g.addedge(4,0);
g.addedge(4,5);
g.addedge(4,3);
g.addedge(5,3);


g.print();







    return 0;
}