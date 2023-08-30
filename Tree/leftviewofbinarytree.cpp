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
void solve(node *root, vector<int> &ans, int level)
{
    if (root == NULL)
    {
        return;
    }

    if (ans.size() == level)
    {
        ans.push_back(root->data);
    }

    solve(root->left, ans, level + 1);
    solve(root->right, ans, level + 1);

    
}
// left view of a binary tree
void leftview(node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return;
    }

    solve(root, ans, 0);
    print(ans);
}

int main()
{
    node *root = NULL;
    cout << "enter tree element :"
         << " ";
    root = Buildtree(root);
    leftview(root);
    // topviewofbinarytree(root);
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 -1
    //             1
    //          /   \ 
    //        2       3
    //     /   \     /
    //    4     5    6

    return 0;
}