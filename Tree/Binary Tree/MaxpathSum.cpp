#include "Headerfile.h"

int solve(Node *root, int &maxi)
{
    // edge case
    if (!root)
        return 0;

    int leftsum = max(0,solve(root->left, maxi));
    int rightsum = max(0,solve(root->right, maxi));

    maxi = max((leftsum + rightsum + root->data), maxi);

    return (root->data + max(leftsum, rightsum));
}

int maxpathsum(Node *root)
{
    int maxi = 0;
   solve(root, maxi);
    return maxi;
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

    int res = maxpathsum(tree);

    cout << res << endl;

    return 0;
}