#include "Headerfile.h"
#include <queue>
// class Node
// {
// public:
//     int data;
//     Node *left;
//     Node *right;

//     Node(int val)
//     {
//         data = val;
//         left = NULL;
//         right = NULL;
//     }
//     ~Node();
// };

vector<int> LevelOrdertraversal(Node *root)
{
    vector<int> ans;

    if (root == NULL)
        return ans;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {

        Node *temp = q.front();
        q.pop();

        if (temp->left != NULL)
            q.push(temp->left);
        if (temp->right != NULL)
            q.push(temp->right);

        ans.push_back(temp->data);
    }
    return ans;

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

    vector<int> ans =  LevelOrdertraversal(t1);

    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
    cout << endl;

    return 0;
}