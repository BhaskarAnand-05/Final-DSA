#include "Headerfile.h"

void Level_order_traversal(Node *root)
{
    // base case
    if (!root)
        return;

    queue<Node *> q;
    q.push(root);

    int i = 0;

    while (!q.empty())
    {
        int size = q.size();
        cout << " Level " << i++ << "-->  ";
        while (size--)
        {
            Node *temp = q.front();
            cout << temp->data << " ";
            q.pop();

            if (temp->left)
                q.push(temp->left);

            if (temp->right)
                q.push(temp->right);
        }
        cout << endl;
    }

    return;
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

    Level_order_traversal(tree);

    return 0;
}