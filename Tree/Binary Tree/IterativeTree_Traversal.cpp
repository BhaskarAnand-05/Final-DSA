#include "Headerfile.h"

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

vector<int> Preorder(Node *root)
{
    vector<int> preorder;

    // Edge Case
    if (root == NULL)
    {
        return preorder;
    }

    stack<Node *> st;
    st.push(root);

    while (!st.empty())
    {
        Node *temp = st.top();
        preorder.push_back(temp->data);
        st.pop();

        if (temp->right)
        {
            st.push(temp->right);
        }
        if (temp->left)
        {
            st.push(temp->left);
        }
    }
    return preorder;
}

vector<int> Inorder(Node *root)
{
    vector<int> inorder;
    // Edge Case
    if (root == NULL)
        return inorder;

    stack<Node *> st;
    st.push(root);

    Node *temp = root;

    while (!st.empty())
    {
        while (temp != NULL)
        {
            st.push(temp);
            temp = temp->left;
            // cout<<temp->data<<"->";
        }

        temp = st.top();
        st.pop();

        cout << temp->data << " "<<endl;
        temp = temp->right;
        
    }
    return inorder;
}

vector<int> PostOrder(Node *root)
{
    vector<int> ans;
    // edge case
    if (root == NULL)
    {
        return ans;
    }

    // Node *current = root;
    // stack<Node *> st;
    // Node *temp;
    // while (current != NULL || !st.empty())
    // {
    //     if (current != NULL)                                      ############ 1 STACK APPROACH ##########
    //     {
    //         st.push(current);
    //         current = current->left;
    //     }

    //     else
    //         temp = st.top()->right;
    //     if (temp == NULL)
    //     {
    //         temp = st.top();
    //         st.pop();
    //         ans.push_back(temp->data);

    //         while (!st.empty() || temp == st.top()->right)
    //         {
    //             temp = st.top();
    //             st.pop();
    //             ans.push_back(temp->data);
    //         }
    //     }

    //     else
    //         current = temp;
    // }

    // ######### 2 STACK APPROACH  #############
    Node *temp = root;
    stack<Node *> st1;
    st1.push(root);
    stack<Node *> st2;

    while (!st1.empty() && temp != NULL)
    {
        temp = st1.top();
        st1.pop();

        st2.push(temp);
        if (temp->left)
            st1.push(temp->left);

        if (temp->right)
            st1.push(temp->right);
    }

    while (!st2.empty())
    {
        Node *t1 = st2.top();
        ans.push_back(t1->data);
        st2.pop();
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
    t1->left->right->right = new Node(6);

    // cout << "Preorder" << endl;
    // vector<int> ans = Preorder(t1);
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i] << " ";
    // }
    // cout << endl
    //      << "Inorder" << endl;
    vector<int> res = Inorder(t1);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    // cout << endl
    //      << "PostOrder" << endl;
    // vector<int> result = PostOrder(t1);
    // for (int i = 0; i < result.size(); i++)
    // {
    //     cout << result[i] << " ";
    // }

    return 0;
}