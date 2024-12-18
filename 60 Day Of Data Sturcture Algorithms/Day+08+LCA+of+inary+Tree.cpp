// Brute Force O(n)
#include "Headerfile.h"

bool root2node(Node *root, int node, vector<int> &ans)
{
    if (root == NULL)
        return false;

    if (root->data == node)
        return true;

    ans.push_back(root->data);
    if (root2node(root->left, node, ans) || root2node(root->right, node, ans))
    {
        return true;
    }

    ans.pop_back();
    return false;
}

int lowest_common_ancestor(Node *root, int firstnode, int secondnode)
{
    int ans = -1;
    // base case
    if (!root || firstnode < 0 || secondnode < 0)
        return ans;

    vector<int> root2one;
    root2node(root, firstnode, root2one);
    vector<int> root2two;
    root2node(root, secondnode, root2two);

    for (int i = 0; i < root2one.size() && i < root2two.size(); i++)
    {
        if (root2one[i] == root2two[i])
            ans = root2one[i];
    }

    return ans;
}

int main()
{
    Node *tree = new Node(1);
    tree->left = new Node(2);
    tree->right = new Node(3);
    tree->left->left = new Node(4);
    tree->left->right = new Node(5);
    tree->right->left = new Node(6);
    tree->right->right = new Node(7);

    // vector<int> root2one;
    // root2node(tree, 4, root2one);
    // vector<int> root2two;
    // root2node(tree, 5, root2two);
    // for (int i = 0; i < root2one.size(); i++)
    // {
    //     cout << root2one[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < root2two.size(); i++)
    // {
    //     cout << root2two[i] << " ";
    // }
    // cout << endl;
    cout << lowest_common_ancestor(tree, 4, 5);
    return 0;
}

// Recursive Approach O(n) But single tree traversal


