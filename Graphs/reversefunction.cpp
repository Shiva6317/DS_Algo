#include<bits/stdc++.h>
using namespace std;
    vector<long>v={2,345,13,345,13,13,234,5,13,13,5,25};

// reverse(yaha se,yaha tak-1)
void print(){
    for(auto i:v){
        cout<<i<<"->";

    }
    cout<<endl;
}
int main(){
    cout<<v.size()<<endl;

    // reverse(v.begin()+3,v.begin()+5);
    sort(v.begin(),v.end());
    
    print();


}