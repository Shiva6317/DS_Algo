#include <bits/stdc++.h>
using namespace std;
class Graaph
{

public:
    map<int, list<pair<int, int>>> adjlist;

    void addedge(int u, int v, int w)
    {
        pair<int, int> p = make_pair(v, w);
        adjlist[u].push_back(p);
    }

    void printadjlist()
    {
        for (auto i : adjlist)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << "{" << j.first << "," << j.second << "}";
            }
            cout << endl;
        }
    }
    void toposort(map<int, bool> &visited, stack<int> &s, int node)
    {
        visited[node] = true;
        for (auto neighbour : adjlist[node])
        {
            if (!visited[neighbour.first])
            {
                toposort(visited, s, neighbour.first);
            }
        }
        s.push(node);
    }
    void printtoposort(stack<int> s)
    {
        while (!s.empty())
        {
            cout << s.top() << "->";
            s.pop();
        }
        cout << endl;
    }
    void sortestpath(stack<int> &s, vector<int> &distance, int src)
    {
        while (!s.empty())
        {
            int top = s.top();
            s.pop();
            for (auto neighbour : adjlist[top]) 
            {
                if (distance[top] != INT_MAX)
                {
                    if (distance[neighbour.first] > distance[top] + neighbour.second)
                    {
                        distance[neighbour.first] = distance[top] + neighbour.second;
                    }
                }
            }
        }
    }
};
int main()
{
    Graaph g;
    g.addedge(0, 1, 5);
    g.addedge(0, 2, 3);
    g.addedge(1, 2, 2);
    g.addedge(1, 3, 6);
    g.addedge(2, 3, 7);
    g.addedge(2, 4, 4);
    g.addedge(2, 5, 2);
    g.addedge(3, 4, -1);
    g.addedge(4, 5, -2);

    g.printadjlist();
    map<int, bool> visited;
    stack<int> s;
    int n = 6;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            g.toposort(visited, s, i);
        }
    }
    // g.printtoposort(s);
    vector<int> distance;
    for (int i = 0; i < n; i++)
    {
        distance.push_back(INT_MAX);
  
    }
    int src = 0;
    distance[src]=0;
    g.sortestpath( s, distance, src);

    for (int i = 0; i < distance.size(); i++)
    {
        cout << distance[i] << "->";
    }
    cout << endl;
    return 0;
}