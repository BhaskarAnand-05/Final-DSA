#include "Headerfile.h"
using namespace std;

Node *invert_tree(Node *root)
{
    // edge case
    if (!root)
        return root;
    auto temp = root->right;
    root->right = root->left;
    root->left = temp;

    invert_tree(root->left);
    invert_tree(root->right);
    

    return root;
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
    
    Print_Tree(tree);

    Node *ans = invert_tree(tree);
    
    cout<<endl;
    Print_Tree(ans);

    return 0;
}