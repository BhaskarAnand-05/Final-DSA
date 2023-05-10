#include "Headerfile.h"

void solve(vector<int> &inorder, Node *root)
{
    if (root->left)
    {
        solve(inorder, root->left);
    }
    inorder.push_back(root->data);
    if (root->right)
    {
        solve(inorder, root->right);
    }
}

// Recursive Travesals
vector<int> INORDER(Node *root)
{
    vector<int> inorder;
    // edge case
    if (!root)
        return inorder;

    solve(inorder, root);
    return inorder;
}

// Level Order Traversal

vector<int> Level_Order(Node *root)
{
    vector<int> ans;

    // edge case
    if (!root)
        return ans;

    queue<Node *> q;
    q.push(root);

    Node *curr = root;

    while (!q.empty())
    {
        curr = q.front();
        q.pop();
        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);

        ans.push_back(curr->data);
    }
    return ans;
}
// Max Height of the Binary Tree

int Max_Height(Node *root)
{

    // // edge case
    // if (!root)
    //     return 0;

    int lh = Max_Height(root->left);
    int rh = Max_Height(root->right);
    return (1 + max(lh, rh));
}

int Balanced_Binary(Node *root)
{
    // edge Case
    if (!root)
        return 0;

    int leftHeight = Balanced_Binary(root->left);
    int rightHeight = Balanced_Binary(root->right);

    if (abs(leftHeight - rightHeight) > 1)
        return -1;
    if (leftHeight == -1 || rightHeight == -1)
        return -1;

    return max(leftHeight, rightHeight) + 1;
}

// Right Left View of the BT
vector<int> LeftView(Node *root)
{
    vector<int> lview;

    // edge case
    if (!root)
        return lview;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *curr = q.front();
            q.pop();
            if (i == 0)
            {
                lview.push_back(curr->data);
            }

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }
    return lview;
}
vector<int> RightView(Node *root)
{
    vector<int> rview;

    // edge case
    if (!root)
        return rview;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *curr = q.front();
            q.pop();
            if (i == size - 1)
            {
                rview.push_back(curr->data);
            }

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }
    return rview;
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
    tree->left->right->right = new Node(8);

    // cout << endl
    //      << "Inorder" << endl;
    cout << endl
         << " balanced binary" << endl;
    // vector<int> ans = RightView(tree);
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i] << " ";
    // }
    int ans = Balanced_Binary(tree);
    cout<<ans;

    return 0;
}
