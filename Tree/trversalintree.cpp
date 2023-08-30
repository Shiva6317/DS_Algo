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
// create tree function
node *buildTree(node *root)
{
    cout << "Enter the data in Tree: ";
    int data;
    cin >> data;
    //make a new node to store value
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "enter the data on left side of the root " << data << endl;
    root->left = buildTree(root->left);
    cout << "enter the data on right side of the root " << data << endl;
    root->right = buildTree(root->right);

    return root;
}
// inorder
//  LNR
//  preorder
//  NLR
//  postorder
//  LRN
void inordertraversal(node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    inordertraversal(root->left);  // L
    cout << root->data << " ";     // N
    inordertraversal(root->right); // R
}
// preorder traversal
void preordertraversal(node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";      // N
    preordertraversal(root->left);  // L
    preordertraversal(root->right); // R
}
// postordertravarsal traversal
void postordertraversal(node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    postordertraversal(root->left);  // L
    postordertraversal(root->right); // R
    cout << root->data << " ";       // N
}

int main()
{

    node *root = NULL;

    root = buildTree(root);
    cout<<"Inorder Traversal:";
    inordertraversal(root);
    cout<<"Preorder Traversal:";

    preordertraversal(root);
    cout<<"Postorder Traversal:";

    postordertraversal(root);
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