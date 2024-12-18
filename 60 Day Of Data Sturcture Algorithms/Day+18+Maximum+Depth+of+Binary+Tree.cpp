#include "Headerfile.h"

int max_depth(Node *root)
{
    // base case
    if (!root)
        return 0;

    int left = max_depth(root->left);
    int right = max_depth(root->right);

    int depth = max(left, right) + 1;
    return depth;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->right->left = new Node(5);
    root->left->right->left->right = new Node(6);
    root->left->right->left->right->left = new Node(7);

    cout << max_depth(root);

    return 0;
}