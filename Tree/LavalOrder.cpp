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
// lavel orderd traversal
void levelorder(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();

        q.pop();
        if (temp == NULL)
        {
            // lavel complete
            cout << endl;
            if (!q.empty())
            {
                // queue still has som element
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

int main()
{

    node *root = NULL;

    root = buildTree(root);
    cout << endl;
    cout<<"Laval Order Traversal :"<<endl;
    levelorder(root);
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 -1
}