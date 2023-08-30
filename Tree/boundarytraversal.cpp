#include <bits/stdc++.h>
using namespace std;
// tree is a non lonear datastructure
//  node
//  root
//  children
//  parent
//  siblings
//  ancester
//  decendent
//  leaf
// these are some binary search tree terminology
class node
{

public:
    int data;
    node *left;
    node *right;

    // constructor call here
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
/////////////////////////////////////////////////////////////////////////////////////////////////
// create tree function
node *Buildtree(node *root)
{
    int data;
    cin >> data;
    // make a new node to store value

    root = new node(data);
    if (data == -1)
    {
        return NULL;
    }
    // build left tree
    root->left = Buildtree(root->left);
    // build right tree

    root->right = Buildtree(root->right);
}

////////////////////////////////////////////////////////////////////////////////////////////////
void traverseleft(node *root, vector<int> &ans)
{

    if (root == NULL)
    {
        return;
    }
    ans.push_back(root->data);
    // agar leaf hai to bhi return
    if (root->left==NULL && root->right==NULL)
    {
        return;
    }
    if (root->left==NULL)
    {
        traverseleft(root->left, ans);
    }

    // else
    // {
    //     traverseleft(root->right, ans);
    // }
}
void traverseleaf(node *root, vector<int> &ans)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    // agar leaf hai to store karo aur return kar jao
    if (root->left==NULL && root->right==NULL)
    {
        ans.push_back(root->data);
        return;
    }
    // left part me jao
    traverseleaf(root->left, ans);
    // right part me jao
    traverseleaf(root->right, ans);
}

void traverseright(node *root, vector<int> &ans)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    if (root->left==NULL && root->right==NULL)
    {
        return;
    }
    if (root->right==NULL)
    {
        traverseright(root->right, ans);
    }
    else
    {
        traverseright(root->left, ans);
    }
    // wapas aaye ho bhaiyya
    // print kar do yaha pe
    ans.push_back(root->data);
}
void print(vector<int> &ans)
{
    cout << "all tree element :";
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
}
void BoundaryTraversal(node *root)
{
    vector<int> result;
    if (root == NULL)
    {
        return;
    }
    result.push_back(root->data);
    // left part print
    traverseleft(root->left, result);
    // leaf node print
    // left part leaf node print
    traverseleaf(root->left, result);
    // right part leaf node
    traverseleaf(root->right, result);

    // right part print
    traverseright(root->right, result);

    // print tree element
    print(result);
}

int main()
{

    node *root = NULL;
    cout << "enter element in tree" << endl;
    root = Buildtree(root);
    BoundaryTraversal(root);
    // cout<<"Inorder Traversal:";
    // inordertraversal(root);
    // cout<<"Preorder Traversal:";

    // preordertraversal(root);
    // cout<<"Postorder Traversal:";

    // postordertraversal(root);
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 -1
    //             1
    //          /   \ 
    //        2       3
    //     /   \     /
    //    4     5    6
    // inorder
    //  LNR
    //  preorder
    //  NLR
    //  postorder
    //  LRN

    
}