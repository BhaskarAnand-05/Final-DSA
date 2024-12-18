#include "Headerfile.h"


Node* build_tree()
{
    cout<<"Enter data"<<endl;
    int val;
    cin>> val;
    Node* root = new Node(val);

    if(val == -1)
    return NULL;

    cout<<"Enter "<<root->data<<"->left"<<endl;
    root->left = new Node(val);

    cout<<"Enter "<<root->data<<"->right"<<endl;
    root->right = new Node(val);

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
    tree->right->right = new Node(7);;
    
    Print_Tree(tree);

    Node* root = build_tree();
    Print_Tree(root);
    return 0;
}