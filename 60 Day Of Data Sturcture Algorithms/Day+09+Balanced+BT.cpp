// TC O(n)

#include "Headerfile.h"
#include <bits/stdc++.h>

pair<int, bool> balanced_BT(Node *root)
{
    // base case
    if (!root)
    {
        pair<int, bool> p = make_pair(0, true);
        return p;
    }

    pair<int, bool> ans;

    pair<int, bool> left = balanced_BT(root->left);
    pair<int, bool> right = balanced_BT(root->right);

    int leftheight = left.first;
    int rightheight = right.first;

    int height = max(leftheight, rightheight) + 1;
    bool diff = abs(leftheight - rightheight) <= 1;

    ans.first = height;
    if (leftheight && rightheight && diff)
    {
        ans.second = true;
    }

    else
        ans.second = false;

    return ans;
}

//  ye wo approach hai jisme if balanced nhi hai then return  -1 and if balanced hai then return height
int balancedbinarytree(Node *root)
{
    // edge case
    if (root == NULL)
        return 0;
    int left = balancedbinarytree(root->left);
    int right = balancedbinarytree(root->right);

    int diff = abs(left - right) > 1;

    if (left && right && diff)
        return -1;
    else
        return (max(left, right) + 1);
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

    cout << balanced_BT(tree).second << endl;
    cout << balancedbinarytree(tree) << endl;
    return 0;
}