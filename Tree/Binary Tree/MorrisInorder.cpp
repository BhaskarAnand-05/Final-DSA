#include "Headerfile.h"
// DFS Traversal is used
vector<int> Morris_Inorder(Node *root)
{
    vector<int> inorder;
    // edge case
    if (!root)
        return inorder;

    // No auxillary or stack space

    Node *curr = root;
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            inorder.push_back(curr->data);
            curr = curr->right;
        }
        else
        {
            Node *prev = curr->left;
            while (prev->right != NULL && prev->right != curr)
            {
                prev = prev->right;
            }
            if (prev->right == NULL)
            {
                prev->right = curr;
                curr = curr->left;
            }
            else
            {
                prev->right = NULL;
                inorder.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return inorder;
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

    cout << "Morris Inorder - " << endl;
    vector<int> Minorder = Morris_Inorder(tree);
    for (int i = 0; i < Minorder.size(); i++)
    {
        cout << Minorder[i] << "->";
    }
    cout << endl;

    return 0;
}