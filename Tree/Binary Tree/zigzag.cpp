#include "Headerfile.h"

// vector<vector<int>> zigzag(Node *root)
// {
//     vector<vector<int>> ans;

//     // edge case
//     if (!root)
//         return ans;

//     queue<Node *> q;
//     q.push(root);
//     int lr = 0;

//     while (!q.empty())
//     {
//         int size = q.size();
//         vector<int> row(size);

//         for (int i = 0; i < size; i++)
//         {
//             Node *temp = q.front();
//             q.pop();

//             int index = (lr) ? i : (size - 1 - i);

//             row[index] = temp->data;

//             if (temp->left)
//                 q.push(temp->left);
//             if (temp->right)
//                 q.push(temp->right);
//         }
//         lr = !(lr);
//         ans.push_back(row);
//     }
//     return ans;
// }
// vector<int> zigZagTraversal(Node *root)
// {
    // vector<int> ans;
    // // edge case
    // if (!root)
    //     return ans;

    // queue<Node *> q;
    // q.push(root);
    // bool lefttoright = false;

    // while (!q.empty())
    // {
    //     int size = q.size();
    //     vector<int> row(size);
    //     for (int i = 0; i < size; i++)
    //     {
    //         Node *temp = q.front();
    //         q.pop();

    //         int index = (lefttoright) ? i : (size - 1 - i);

    //         row[index] = temp->data;

    //         if (temp->left)
    //             q.push(temp->left);
    //         if (temp->right)
    //             q.push(temp->right);
    //     }
    //     ans.insert(ans.end(), row.begin(), row.end());
    //     lefttoright = !(lefttoright);
    // }

    // return ans;
// }

vector<int> zigZagTraversal(Node *root)
{
    vector<int> ans;
    // edge case
    if (!root)
        return ans;

    queue<Node *> q;
    q.push(root);
    bool lefttoright = false;

    stack<int> st;

    while (!q.empty())
    {
        int size = q.size();
        vector<int> row;
        if (lefttoright)
        {
            while (size)
            {
                Node *temp = q.front();
                q.pop();
                ans.push_back(temp->data);

                if(temp->left)
                q.push(temp->left);
                if(temp->right)
                q.push(temp->right);

                size--;

            }
        }
        else
        {
            while (size)
            {
                Node *temp = q.front();
                q.pop();
                st.push(temp->data);

                if (temp->left)
                q.push(temp->left);
                if (temp->right)
                q.push(temp->right);

                size--;
            }
            while (!st.empty())
            {
                row.push_back(st.top());
                st.pop();
            }
            
        }

        ans.insert(ans.end(), row.begin(), row.end());
        lefttoright = !(lefttoright);
    }

    return ans;
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

    vector<int> result = zigZagTraversal(tree);
    // for (int i = 0; i < result.size(); i++)
    // {
    //     for (int j = 0; j < result[i].size(); j++)
    //     {
    //         cout<<result[i][j]<<" ";
    //     }
    //     cout<<endl;

    // }
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}