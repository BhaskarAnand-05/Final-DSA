#include "Headerfile.h"

class Node
{
public:
    int root_data;
    Node *left;
    Node *right;

    Node(int value)
    {
        root_data = value;
        left = NULL;
        right = NULL;
    }
};

int Sum_KLevel(Node *root, int k)
{
    // Edge Case
    if (root == NULL)
        return -1;

    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    int count = 0;
    int sum = 0;

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp != NULL)
        {
            if (count == k)
            {
                sum += temp->root_data;
            }

            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
        else if(!q.empty())
        {
            q.push(NULL);
            count ++;
        }   
    }
    return sum;

}

int main()
{
    Node *t1 = new Node(1);
    t1->left = new Node(2);
    t1->right = new Node(3);
    t1->left->left = new Node(4);
    t1->left->right = new Node(5);
    t1->right->left = new Node(6);
    t1->right->right = new Node(7);
    

    cout << Sum_KLevel(t1, 2);
    cout << endl;

    return 0;
}