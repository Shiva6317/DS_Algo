#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    // constructor of tree

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
void inordertraversal(node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    // left call
    inordertraversal(root->left);
    // node print
    cout << root->data << " ";
    // right call
    inordertraversal(root->right);
}

void lavalordertraversal(node *root)
{
    //             1
    //          /   \ 
//        2       3
    //     /   \     /
    //    4     5    6

    // make a queue
    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if (temp->left)
            q.push(temp->left);

        if (temp->right)
            q.push(temp->right);
    }
}
void print(vector<int> &ans)
{
    cout << "tree element"
         << " :";
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
}
void ziczacktraversal(node *root)
{
    vector<int> result;
    if (root == NULL)
    {
        return;
    }

    // lavel order traversal base qustion
    queue<node *> q;
    q.push(root);
    bool left_to_right = true;

    while (!q.empty())
    {
        int size = q.size();
        vector<int> ans(size);
        for (int i = 0; i < size; i++)
        {
            node *temp = q.front();
            q.pop();
            // one line code if statement
            int index = left_to_right ? i : size - i - 1;
            ans[index] = temp->data;

            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
        left_to_right = !left_to_right;
        for (auto i : ans)
        {
            result.push_back(i);
        }
    }
    print(result);
}

int main()
{
    node *root = NULL;
    cout << "enter element in tree" << endl;
    root = Buildtree(root);
    // cout << "inorder traversal " << endl;
    // inordertraversal(root);
    // cout << "lavel order traversal  :" << endl;
    // lavalordertraversal(root);

    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 -1
    // ziczaktraversal
    ziczacktraversal(root);

    return 0;
}