#include <bits/stdc++.h>
using namespace std;
class graph
{
public:
    unordered_map<int, list<int>> adj;

    void insert_edge(int u, int v, bool direction)
    {
        // direction 0->undirected graph
        // direction 1->directed graph
        adj[u].push_back(v);
        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    void print()
    { cout<<"adj list :"<<endl;
        for (auto i : adj)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << j << " ,";
            }
            cout << endl;
        }
        cout << endl;
        
    }
};
int main()
{
    cout<<"enter the no of node:"<<endl;
    int n;cin>>n;
    cout<<"enter the no of edges:"<<endl;
    int m;
    cin>>m;
    graph g;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g.insert_edge(u,v,0);
        
    }
    g.print();

    return 0;
}