#include"Headerfile.h"

bool checkidentical(Node* root1,Node* root2)
{
    //edge case
    if(!root1 || !root2)
    return (root1 == root2);

    if(root1->data != root2->data)
    return false;

    return (checkidentical(root1->left,root2->left) && checkidentical(root1->right,root2->right));
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

    cout<<checkidentical(tree,Tree)<<endl;
    return 0;
}