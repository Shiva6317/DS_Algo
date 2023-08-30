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

    void printlist(vector<int> &ans)
    {
        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    vector<int> bfstraverssal(unordered_map<int, list<int>> &adj, vector<int> &ans, map<int, bool> &visited, int node)
    {
        queue<int> q;
        q.push(node);
        visited[node] = true;

        while (!q.empty())
        {
            int frontnode = q.front();
            q.pop();
            ans.push_back(frontnode);
            for (auto i : adj[frontnode])
            {
                if (visited[i] == false)
                {
                    q.push(i);
                    visited[i] = true;
                    // ans.push_back(i);
                }
            }
        }
        return ans;
    }

    void solve(int vertex)
    {
        vector<int> ans;
        map<int, bool> visited;
        for (int i = 0; i < vertex; i++)
        {
            visited[i] = false;
        }

        for (int i = 0; i < vertex; i++)
        {
            if (visited[i] == false)
            {
                ans = bfstraverssal(adj, ans, visited, i);
            }
        }

        printlist(ans);
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
    g.solve(n);

    return 0;
}