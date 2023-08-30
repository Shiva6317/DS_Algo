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
    // cycle detection
    bool cycledection(map<int,int>&parent,map<int, bool> &visited, int node)
    {
        
        queue<int> q;
        q.push(node);
        visited[node] = true;
        parent[node] = -1;

        while (!q.empty())
        {
            int frontnode = q.front();
            q.pop();

            for (auto i : adj[frontnode])
            {
                if (visited[i] == true && frontnode != parent[i])
                {
                    return true;
                }
                else if (!visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                    parent[i] = frontnode;
                }
            }
        }
        return false;
    }
    void solution(int vertex)
    {
        map<int, bool> visited;
        map<int, int> parent;
        for (int i = 0; i < vertex; i++)
        {
            visited[i] = false;
        }
        bool ans;

        for (int i = 0; i <= vertex; i++)
        {
            if (!visited[i])
            {
                ans = cycledection(parent,visited, i);
            }
        }

        if (ans == true)
        {
            cout << "cycle present" << endl;
        }
        else
        {
            cout << "cycle not present" << endl;
        }
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
    g.solution(n);

    return 0;
}