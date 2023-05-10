#include"Headerfile.h"
void changeTree(Node  * root) {
    if(root == NULL) 
    return;
    if(!(root->left) && !(root->right))
    return;

    int sum = 0;

    if(root->left)
    sum += root->left->data;
    if(root->right)
    sum += root->right->data;

    if(sum > root->data)
    {
         root->data = sum;
    }
    else
    {
        root->left->data = root->data;
        root->right->data = root->data;
    }

    changeTree(root->left);
    changeTree(root->right);
    // root ki value change krne ke liye total use kiya hai
    int total = 0;

    if(root->left)
    total += root->left->data;
    if(root->right)
    total += root->right->data;
    // taaki check krle ki root ki dono me se ek vi chold node exist kre to total ko root ke data se replace kr ske
    if(root->left || root->right)
    root->data = total;
    

}  

int main()
{
    Node *Tree = new Node(1);
    Tree->left = new Node(2);
    Tree->left->left = new Node(3);
    Tree->left->left->left = new Node(4);
    Tree->left->left->left->left = new Node(5);
    Tree->right = new Node(6);
    Tree->right->right = new Node(7);

    changeTree(Tree);
    Print_Tree(Tree);
    
    
    return 0;
}