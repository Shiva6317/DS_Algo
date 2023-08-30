#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;

    // constructor call
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
// cout<<"kalinethunter"<<endl;
// build tree fucntion
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
//top view of tree code start here
void topviewofbinarytree(node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return;
    }
    map<int, int> topnodes;
    queue<pair<node *, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<node *, int> temp = q.front();
        q.pop();
        node *frontnode = temp.first;
        int hd = temp.second;
        // main function of this code if value exist then not enter the value
        if (topnodes.find(hd) == topnodes.end())
        {
            topnodes[hd] = frontnode->data;
        }
        if (frontnode->left)
        {
            q.push(make_pair(frontnode->left, hd - 1));
        }
        if (frontnode->right)
        {
            q.push(make_pair(frontnode->right, hd + 1));
        }
    }
    for (auto i : topnodes)
    {
        ans.push_back(i.second);
    }

    print(ans);
}


//bottomview of tree code start here
void bottomview(node *root)
{

    vector<int> ans;
    map<int, int> nodes;
    queue<pair<node *, int>> q;
    q.push(make_pair(root, 0));
    while (!q.empty())
    {
        pair<node *, int> temp = q.front();
        q.pop();

        node *frontnode = temp.first;
        int hd = temp.second;
        // main line in this function not check any type of function
        nodes[hd] = frontnode->data;

        if (frontnode->left)
            q.push(make_pair(frontnode->left, hd - 1));

        if (frontnode->right)
        {
            q.push(make_pair(frontnode->right, hd + 1));
        }
    }
    for (auto i : nodes)
    {
        ans.push_back(i.second);
    }

    print(ans);
}
int main()
{
    node *root = NULL;
    cout << "enter tree element :"
         << " ";
    root = Buildtree(root);
    bottomview(root);
    // topviewofbinarytree(root);
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 -1
    //             1
    //          /   \ 
    //        2       3
    //     /   \     /
    //    4     5    6

    return 0;
}