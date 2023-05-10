#include "Headerfile.h"

vector<int> temp;
bool is_leaf(Node *root)
{
    // edge case
    if (!root)
        return false;

    if (!(root->left) && !(root->right))
        return true;

    else
        return false;
}
class BoundaryTraversal
{
private:
    void leftboundary(Node *root, vector<int> &res)
    {
        Node *curr = root;
        while (curr)
        {
            if (!is_leaf(curr))
                res.push_back(curr->data);

            if (curr->left)
                curr = (curr->left);
            else
                curr = curr->right;
        }
    }
    void righttboundary(Node *root, vector<int> &res)
    {
        Node *curr = root;
        // edge case
        while(curr)
        {
            if (!is_leaf(curr))
                temp.push_back(curr->data);

            if (curr->right)
                curr = (curr->right);
            else
                curr = curr->left;
        }

        for (int i = temp.size() - 1; i >= 0; --i)
        {
            res.push_back(temp[i]);
        }
    }
    // we will use inorder traversal for the printing ofleaf nodes
    void leafnodes(Node *root, vector<int> &res)
    {
        if (is_leaf(root))
        {
            res.push_back(root->data);
            return;
        }

        if(root->left) leafnodes(root->left, res);
        if(root->right) leafnodes(root->right, res);
    }

public:
    vector<int> boundary_trav(Node *root)
    {
        vector<int> res;
        // edge case
        if (!root)
            return res;
        if (!is_leaf(root))
            res.push_back(root->data);
        leftboundary(root->left, res);
        leafnodes(root, res);
        righttboundary(root->right, res);

        return res;
    }
} b;

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

    vector<int> ans = b.boundary_trav(Tree);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}