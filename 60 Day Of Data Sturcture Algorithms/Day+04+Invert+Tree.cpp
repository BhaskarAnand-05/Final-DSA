#include <bits/stdc++.h>
#include "Headerfile.h"
using namespace std;

Node *invert_Tree(Node *root)
{
    Node *temp;
    if (root == NULL)
        return NULL;
    
    // swap krna hai nodes koo
    temp = root->left;
    root->left = root->right;
    root->right = temp;

    // recursion se baaki saare nodes koo replace krdo
    invert_Tree(root->left);
    invert_Tree(root->right);

    return root;
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Print_Tree(root);
    cout<<endl;

    Node *root2 = invert_Tree(root);

    Print_Tree(root2);
    return 0;
}