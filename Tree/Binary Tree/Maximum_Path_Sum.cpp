#include"Headerfile.h"

int sum(Node *root)
{
    // edge case
    if (root  == NULL)
    {
        return -1;
    }
    int leftSum += sum(root->left);
    int rightSum += sum(root->right);
    int TotalSum = leftSum + rightSum + root->data;
    return max(leftSum , rightSum)
}
int max_pathsum(Node *root)

int main()
{
    return 0;
}