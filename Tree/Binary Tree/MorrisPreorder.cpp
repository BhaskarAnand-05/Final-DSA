#include "Headerfile.h"
// DFS Traversal is used
vector<int> Morris_Preorder(Node *root)
{
    vector<int> Preorder;
    // edge case
    if (!root)
        return Preorder;

    // No auxillary or stack space

    Node *curr = root;
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            Preorder.push_back(curr->data);
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
                Preorder.push_back(curr->data);
                curr = curr->left;
            }
            else
            {
                prev->right = NULL;
                curr = curr->right;
            }
        }
    }
    return Preorder;
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

    cout << "Morris Preorder - " << endl;
    vector<int> MPreorder = Morris_Preorder(tree);
    for (int i = 0; i < MPreorder.size(); i++)
    {
        cout << MPreorder[i] << "->";
    }
    cout << endl;

    return 0;
}