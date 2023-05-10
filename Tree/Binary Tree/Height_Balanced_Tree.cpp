#include "Headerfile.h"

// int isBalanced(Node *root, bool &value)
// {
//     if (root == NULL)
//         return 0;
//     int left = isBalanced(root->left, value);
//     int right = isBalanced(root->right, value);
//     if (abs(left - right) > 1)
//         value = false;
//     return max(left, right) + 1;
// }
// bool isBalancedBT(Node *root)
// {
//     bool value = true;
//     isBalanced(root, value);
//     return value;
// }
int balancedbinarytree(Node *root)
{
    // edge case
    if (root == NULL)
        return 0;
    int left = balancedbinarytree(root->left);
    if (left == -1)
        return -1;
    int right = balancedbinarytree(root->right);
    if (right == -1)
        return -1;

    if (abs(left - right) > 1)
        return -1;
    else
        return (max(left, right) + 1);
}

int main()
{
    Node *tree = new Node(1);
    tree->left = new Node(2);
    tree->left->left = new Node(3);
    tree->left->left->left = new Node(4);
    tree->left->left->left->left = new Node(5);
    tree->left->left->left->left->left = new Node(6);
    tree->left->left->left->left->left->left = new Node(7);
    if (balancedbinarytree(tree) != -1)
        cout << true << endl;
    else
        cout << false << endl;

    Node *t1 = new Node(1);
    t1->left = new Node(2);
    t1->right = new Node(3);
    t1->left->left = new Node(4);
    t1->left->right = new Node(5);
    t1->right->left = new Node(6);
    t1->right->right = new Node(7);
    if (balancedbinarytree(t1) != -1)
        cout << true << endl;
    else
        cout << false << endl;

    return 0;
}