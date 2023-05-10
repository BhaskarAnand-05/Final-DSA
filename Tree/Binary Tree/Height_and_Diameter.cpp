#include "Headerfile.h"

class Node
{
public:
    int data;
    Node *left = NULL;
    Node *right = NULL;

    Node(int val)
    {
        data = val;
    }
};

// Time Complexity = O(n)
int height(Node *root)
{
    // edge case
    if (root == NULL)
    {
        return 0;
    }

    int lheight = height(root->left);
    int rheight = height(root->right);

    return max(lheight, rheight) + 1;
}

// Time Complexity of calculating diameter = O(n^2)
int diameter(Node *root)
{
    // edge case
    if (root == NULL)
    {
        return 0;
    }

    int left_height = height(root->left);
    int right_height = height(root->right);

    int cum_diameter = left_height + right_height + 1;

    int left_diameter = diameter(root->left);
    int right_diameter = diameter(root->right);

    return max(max(left_diameter, right_diameter), cum_diameter);
}

int calc_diameter(Node *root, int *height)
{
    // edge case
    if (root == NULL)
    {
        *height = 0;
        return 0;
    }
    int left_height = 0, right_height = 0;

    int left_diameter = calc_diameter(root->left, &left_height);
    int right_diameter = calc_diameter(root->right, &right_height);

    int curr_diameter = left_height + right_height + 1;
    *height = max(left_height, right_height) + 1;

    return max(curr_diameter, (left_diameter, right_diameter)) + 1;
}
int main()
{
    Node *tree = new Node(1);
    tree->left = new Node(2);
    tree->left->left = new Node(3);
    tree->left->left->left = new Node(4);
    tree->left->left->left->left = new Node(5);
    tree->right = new Node(6);
    tree->right->right = new Node(7);

    cout << height(tree) << endl;

    cout << calc_diameter(tree,0);

    cout << endl;

    return 0;
}
