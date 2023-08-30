#include <iostream>
#include<list>
#include<unordered_map>
#include<map>
#include<stack>

using namespace std;

class graph
{
public:
    unordered_map<int, list<int>> adjlist;
    void creategraph(int u, int v, bool direction)
    {
        // direction 0->undirected graph
        // direction 1-> directed graph
        adjlist[u].push_back(v);

        if (!direction)
        {
            adjlist[v].push_back(u);
        }
    }
    void print()
    {
        cout << "grpah list" << endl;
        for (auto i : adjlist)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << j << " , ";
            }
            cout << endl;
        }
    }
    // topological sort
    // if u->v exist a edges then u always present befour v;
    // int topological sort;
    void toposort(map<int, bool> &visited, stack<int> &ans, int node)
    {
        visited[node] = true;

        for (auto neighbour : adjlist[node])
        {
            if (!visited[neighbour])
            {
                toposort(visited, ans, neighbour);
            }
        }

        ans.push(node);
    }
    // 1 2,1 3,2 3,-->topo sort-->1 2 3
    void topologicalsort(int vertex)
    {
        stack<int> ans;
        map<int, bool> visited;

        for (int i = 0; i < vertex; i++)
        {
            if(visited[i]==false){
                toposort(visited, ans, i);
            }

           
        }
         
        while (!ans.empty())
        {
            cout << ans.top() << "->";
            ans.pop();
        }
        cout << endl;
    }
};

int main()
{
    cout << "enter no of vertex:";
    int vertex;
    cin >> vertex;
    cout << "Enter no of Edges:";
    int edges;
    cin >> edges;
    cout << "Enter eges:" << endl;
    graph g;
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        g.creategraph(u, v, 1);
    }
    // g.print();
    g.topologicalsort(vertex);

    return 0;
}