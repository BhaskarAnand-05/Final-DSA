#include "Headerfile.h"

class Tree
{
public:
    int root_data;
    Tree *left;
    Tree *right;

    Tree(int value)
    {
        root_data = value;
        left = NULL;
        right = NULL;
    }
};

void RightView(Tree *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<Tree *> q1;
    q1.push(root);

    while (!q1.empty())
    {
        int n = q1.size();
        for (int i = 0; i < n; i++)
        {
            Tree *temp = q1.front();
            q1.pop();
            if (i == n - 1)
            {
                cout << temp->root_data << " ";
            }
            if (temp->left)
                q1.push(temp->right);
            if (temp->right)
                q1.push(temp->right);
        }
    }
}

void LeftView(Tree *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<Tree *> q1;
    q1.push(root);

    while (!q1.empty())
    {
        int n = q1.size();
        for (int i = 0; i < n; i++)
        {
            Tree *temp = q1.front();
            q1.pop();
            
            if (i == 0)
            {
                cout<<temp->root_data<<" ";
            }

            if (temp->left)
            {
                q1.push(temp->left);
            }
            if (temp->right)
            {
                q1.push(temp->right);
            }
        }
    }
}

/*                    1
                     / \
                    2   3
                   / \  / \
                  4   5 6  7
*/

int main()
{
    Tree *t1 = new Tree(1);
    t1->left = new Tree(2);
    t1->right = new Tree(3);
    t1->left->left = new Tree(4);
    t1->left->right = new Tree(5);
    t1->right->left = new Tree(6);
    t1->right->right = new Tree(7);

    RightView(t1);
    cout << endl;

    LeftView(t1);
    cout << endl;
    return 0;
}