#include "Headerfile.h"

/* RECURSIVE SOLUTION
 WORST CASE WHEN- EITHER LEFT SKEWED TREE OR RIGHT SKEWED TREE
 */

int MaxDepth(Node *root)
{
    // egde case
    if (root == NULL)
    {
        return 0;
    }

    int left_height = MaxDepth(root->left);
    int right_height = MaxDepth(root->right);

    return max(left_height, right_height) + 1;
}

/* LEVEL ORDER SOLUTION
 WORST CASE WHEN- MAXIMUM ELEMENTS ON ONE LEVEL
 */
int Calc_Depth(Node *root)
{
    // edge case
    if (root == NULL)
    {
        return 0;
    }

    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    int count = 0;

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        
        if (temp != NULL)
        {
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
        else if (!q.empty())
        {
            q.push(NULL);
            count++;
        }
    }
    return count + 1;
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

    // cout<<"The height of the Tree is"<<endl;
    cout << MaxDepth(tree)<<endl;
    cout << Calc_Depth(tree);
    return 0;
}