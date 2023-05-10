#include "Headerfile.h"

class Tree
{
public:
    int root_data;
    Tree *left;
    Tree *right;

    Tree(int value)
    {
        root_data = value;
        left = NULL;
        right = NULL;
    }
};

// PreOrder Traversal
void preorder(Tree *tree)
{
    if (tree == NULL)
    {
        return;
    }

    cout << tree->root_data << "    ";
    preorder(tree->left);
    preorder(tree->right);
}

// InOrder Traversal
void inorder(Tree *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->root_data << "    ";
    inorder(root->right);
}

// PostOrder Traversal
void postorder(Tree *root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->root_data << "    ";
}

/*                    1
                     / \
                    2   3
                   / \  / \
                  4   5 6  7
*/

int main()
{
    Tree *t1 = new Tree(1);
    t1->left = new Tree(2);
    t1->right = new Tree(3);
    t1->left->left = new Tree(4);
    t1->left->right = new Tree(5);
    t1->left->right->right = new Tree(6);
    // t1->right->right = new Tree(7);

    // cout << "Preorder" << endl;
    // preorder(t1);
    // cout << endl;

    cout << "InOrder" << endl;
    inorder(t1);
    cout << endl;

    // cout << "PostOrder" << endl;
    // postorder(t1);
    // cout << endl;

    return 0;
}