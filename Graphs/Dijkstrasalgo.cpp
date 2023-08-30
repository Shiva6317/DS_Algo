#include <bits/stdc++.h>
using namespace std;
class Graaph
{

public:
    map<int, list<pair<int, int>>> adjlist;

    void addedge(int u, int v, int w)
    {
        pair<int, int> p1 = make_pair(v, w);

        adjlist[u].push_back(p1);
        pair<int, int> p2 = make_pair(u, w);

        adjlist[v].push_back(p2);
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
    void DijkstraAlgo(vector<int> &distance, int node)
    {
        set<pair<int, int>> s;
        distance[node] = 0;
        s.insert(make_pair(0, node));
        while (!s.empty())
        {
            auto top = *(s.begin());
            int topdist = top.first;
            int topnode = top.second;
            s.erase(s.begin());
            // traver all  node

            for (auto neighbour : adjlist[topnode])
            {
                if (topdist + neighbour.second < distance[neighbour.first])
                {
                    auto record = s.find(make_pair(distance[neighbour.first], neighbour.first));
                    if (record != s.end())
                    {
                        s.erase(record);
                    }
                    else
                    {
                        distance[neighbour.first] = topdist + neighbour.second;
                        s.insert(make_pair(distance[neighbour.first], neighbour.first));
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
    int n = 5;
    vector<int> distance;
    for (int i = 0; i < n; i++)
    {
        distance.push_back(INT_MAX);
    }
    int src = 0;
    distance[src] = 0;
    g.DijkstraAlgo(distance, src);
    for (int i = 0; i <= distance.size(); i++)
    {
        cout << distance[i] << "->";
    }
    cout << endl;
    return 0;
}