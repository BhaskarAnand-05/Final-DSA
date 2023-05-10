#include "Headerfile.h"

// USING EXTRA SPACE OF ARRAYS
bool root_to_node(Node *root, int node, vector<int> &ans)
{
    if (!root)
        return false;

    ans.push_back(root->data);

    if (root->data == node)
        return true;

    if (root_to_node(root->left, node, ans) || root_to_node(root->right, node, ans))
    {

        return true;
    }
    ans.pop_back();
    return false;
}

int least_comm_ances(Node *root, int root1, int root2)
{
    vector<int> arr1, arr2;99

    // edge case
    if (!root || !root1 || !root2)
        return -2;

    if (root_to_node(root, root1, arr1) && root_to_node(root, root2, arr2))
    {
        for (int i = 0; i < arr1.size() && i < arr2.size(); i++)
        {
            if (arr1[i] == arr2[i])
                continue;

            return arr1[i - 1];
        }
        return (root1 < root2 ? root1 : root2);
    }

    return -1;
}

// RECURSIVE WAY OF LCA

Node *lca(Node *root, int root1, int root2)
{
    // edge case
    if (!root )
    {
        return root;
    }
    if(root->data == root1 || root->data == root2)
    {
        return root;
    }

    Node *leftside = lca(root->left, root1, root2);
    Node *rightside = lca(root->right, root1, root2);

    if (leftside == NULL)
        return rightside;
    if (rightside == NULL)
        return leftside;

    else
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

    

    cout << lca(tree, 6, 3)->data << endl;


    return 0;
}