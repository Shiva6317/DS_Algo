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
int solve(node *root, int sum, int &maxsum, int len, int &maxlen)
{
    // base case
    // 2 case if you reach leaf node and if tree left child null but right child exits
    if (root == NULL)
    {
        // priority hamesha length ko deni hai brother
        if (len > maxlen)
        {
            maxlen = len;
            maxsum = sum;
        }
        else if (len == maxlen)
        {
            maxsum = max(sum, maxsum);
        }
        return 0;
    }
    sum = sum + root->data;
    solve(root->left, sum, maxsum, len + 1, maxlen);
    solve(root->right, sum, maxsum, len + 1, maxlen);
    return maxsum;
}
void bioodlineofatree(node *root)
{
    if (root == NULL)
    {
        return;
    }
    int ans = 0;
    int sum = 0;
    int len = 0;
    int maxsum = INT_MIN;
    int maxlen = 0;

    ans = solve(root, sum, maxsum, len, maxlen);

    cout << "sum of bloodline of a tree :" << ans << endl;
}

int main()
{
    node *root = NULL;
    cout << "enter tree element :"
         << " ";
    root = Buildtree(root);
    bioodlineofatree(root);

    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 10 -1 -1
    //             1
    //          /   \ 
    //        2       3
    //     /   \     /  \ 
    //    4     5    6   10

    return 0;
}