#include "Headerfile.h"

pair<int, int> Daimeter_BT(Node *root)
{
    pair<int, int> ans;

    // base case
    if (root == NULL)
        return make_pair(0, 0);

    pair<int, int> left_dia = Daimeter_BT(root->left);
    pair<int, int> right_dia = Daimeter_BT(root->right);

    int left_height = left_dia.second;
    int right_height = right_dia.second;

    int height = max(left_height, right_height) + 1;

    ans.second = height;

    int diameter = (max(left_dia, right_dia), left_height + right_height + 1);

    ans.first = diameter;

    return ans;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->right->left = new Node(5);
    root->left->right->left->right = new Node(6);
    root->left->right->left->right->left = new Node(7);

    Node *tree = new Node(1);
    tree->left = new Node(2);
    tree->right = new Node(3);
    tree->left->left = new Node(4);
    tree->left->right = new Node(5);
    tree->right->left = new Node(6);
    tree->right->right = new Node(7);

    cout << Daimeter_BT(root).first << endl;

    cout << Daimeter_BT(tree).first;

    return 0;
}