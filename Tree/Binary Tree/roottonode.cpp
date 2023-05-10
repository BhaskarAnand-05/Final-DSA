#include "Headerfile.h"

bool Root_Node(Node *root, Node *node, vector<int> &ans)
{
    if (!root || !node)
        return false;
    if (root == node)
        return true;

    ans.push_back(root->data);

    if (Root_Node(root->left, node, ans) || Root_Node(root->right, node, ans))
    {
        return true;
    }

    ans.pop_back();
    return false;
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
    vector<int> result;

    if (Root_Node(tree, tree->right->right, result))

        for (int i = 0; i < result.size(); i++)
        {
            cout << result[i] << " ";
        }

    return 0;
}