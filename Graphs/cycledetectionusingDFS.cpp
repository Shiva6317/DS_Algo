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

    bool cycleDFS(map<int, bool> &visited, map<int, int> &parent, int node)
    {
        visited[node] = true;

        for (auto i : adj[node])
        {
            parent[i] = node;
            if (visited[i] == false && i != parent[node])
            {
                return true;
            }
            else if (!visited[i]){
                cycleDFS(visited, parent, i);
            }
        }
        return false;
    }

    void solution(int vertex)
    {
        map<int, bool> visited;
        map<int, int> parent;
        bool ans;

        for (int i = 0; i < vertex; i++)
        {
            ans = cycleDFS(visited, parent, i);
        }

        if (ans)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
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