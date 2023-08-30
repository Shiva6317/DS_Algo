#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *Buildtree(node *root)
{
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    // enter left side data
    root->left = Buildtree(root->left);
    // enter right side data
    root->right = Buildtree(root->right);
}
// print function
void print(vector<int> &ans)
{
    cout << "tree element :"
         << " ";
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
}

// vertical order traversal function written here
void verticaltraversal(node *root)
{ // in map store value according to this style
    ///[level],[hrizontal distance],[all the tree element which is belong to this level and distance]
    map<int, map<int, vector<int>>> nodes;
    queue<pair<node *, pair<int, int>>> q;
    // ans store in this vector
    vector<int> ans;
    if (root == NULL)
    {
        return;
    }
    // queue me// [node]  , [level]  ,  [horizontal distance]
    q.push(make_pair(root, make_pair(0, 0)));
    while (!q.empty())
    {
        pair<node *, pair<int, int>> temp = q.front();
        q.pop();
        // node value
        node *frontnode = temp.first;
        // horizontal distance
        int hd = temp.second.first;
        // lavel of current node
        int lvl = temp.second.second;

        // insert value in nodes vector
        nodes[hd][lvl].push_back(frontnode->data);

        if (frontnode->left)
            q.push(make_pair(frontnode->left, make_pair(hd - 1, lvl + 1)));

        if (frontnode->right)
        {
            q.push(make_pair(frontnode->right, make_pair(hd + 1, lvl + 1)));
        }
    }
    for (auto i : nodes)
    {
        for (auto j : i.second)
        {
            for (auto k : j.second)
            {
                ans.push_back(k);
            }
        }
    }
    print(ans);
}

int main()
{
    node *root = NULL;
    cout << "enter element in tree" << endl;
    root = Buildtree(root);
    verticaltraversal(root);
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 -1
    //             1
    //          /   \ 
    //        2       3
    //     /   \     /
    //    4     5    6
    return 0;
}