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
    {
        cout << "adj list :" << endl;
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
    void sortpath(map<int, bool> &visited, map<int, int> &parent, int node)
    {
        queue<int> q;
        q.push(node);
        parent[node] = -1;
        visited[node] = true;

        while (!q.empty())
        {
            int frontnode = q.front();
            q.pop();
            for (auto neighbour : adj[frontnode])
            {

                if (!visited[neighbour])
                {
                    q.push(neighbour);
                    parent[neighbour] = frontnode;
                    visited[neighbour] = true;
                }
            }
        }
    }

    void sortestpath(int vertex, int src, int dst)
    {
        map<int, bool> visited;
        map<int, int> parent;

        for (int i = 0; i < vertex; i++)
        {

            visited[i] = false;
        }
        for (int i = 0; i < vertex; i++)
        {

            if (!visited[i])
            {
                sortpath(visited, parent, i);
            }
        }

        // for (auto i : parent)
        // {
        //     cout << i.first << "->" << i.second << endl;
        // }
        // for(int i=0;i<parent.size();i++){
        //     cout<<i<<"->"<<parent[i]<<endl;
        // }
        vector<int> ans;
        ans.push_back(dst);
        while (dst != src)
        {
            

            dst = parent[dst];
        ans.push_back(dst);
        }
        reverse(ans.begin(),ans.end());
        for(auto i:ans){
            cout<<i<<"->";
        }
        cout<<endl;

        
    }
};
int main()
{
    cout << "enter the no of node:" << endl;
    int n;
    cin >> n;
    cout << "enter the no of edges:" << endl;
    int m;
    cin >> m;
    graph g;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g.insert_edge(u, v, 0);
    }
    // g.print();
    g.sortestpath(n, 1, 3);
    return 0;
} 