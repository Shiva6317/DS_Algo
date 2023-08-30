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

node *lca(node *root, int n1, int n2)
{
    // base case
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == n1 || root->data == n2)
    {
        return root;
    }
    node *leftans = lca(root->left, n1, n2);
    node *rightans = lca(root->right, n1, n2);

    if (leftans != NULL && rightans != NULL)
    {
        return root;
    }
    if (leftans != NULL && rightans == NULL)
    {
        return leftans;
    }
    if (leftans == NULL && rightans != NULL)
    {
        return rightans;
    }
}
void lca2(node*root,int n1,int n2){
if(root==NULL){
    return;
}
vector<int>path1;
vector<int>path2;
while(root->left->data !=n1 || root->right->data!=n2){
    root=root->left;
    
}





}
int main()
{
    node *root = NULL;
    cout << "enter tree element :"
         << " ";
    root = Buildtree(root);
    root = lca(root, 4, 3);
    cout << "lca : " << root->data << endl;
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 -1
    //             1
    //          /   \ 
    //        2       3
    //     /   \     /
    //    4     5    6

    return 0;
}