#include "Headerfile.h"

int maxwidth(Node *root)
{
    // edge case
    if (!root)
    {
        return 0;
    }
    int lh = maxwidth(root->left);
    int rh = maxwidth(root->right);

    return max(lh, rh) + 1;
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

    Node *Tree = new Node(1);
    Tree->left = new Node(2);
    Tree->left->left = new Node(3);
    Tree->left->left->left = new Node(4);
    Tree->left->left->left->left = new Node(5);
    Tree->right = new Node(6);
    Tree->right->right = new Node(7);

    cout << pow(2, maxwidth(tree)) << endl
         << pow(2, maxwidth(Tree)) << endl;
    return 0;
}