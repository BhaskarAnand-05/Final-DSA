#include "Headerfile.h"

// Top VIEW OF THE Tree
vector<int> Top_View(Node *root)
{
    vector<int> res;
    // edge case
    if (!root)
        return res;

    map<int, int> ans;
    queue<pair<int, Node *>> q;
    q.push({0, root});

    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();
        Node* node = temp.second;
        int x = temp.first;

        if (ans.find(x) == ans.end())
            ans[x] = node->data;
        if (temp.second->left)
            q.push({temp.first - 1, temp.second->left});
        if (temp.second->right)
            q.push({temp.first + 1, temp.second->right});
    }
    for (auto i : ans)
    {
        res.push_back(i.second);
    }

    return res;
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
    tree->left->right->right = new Node(8);

    vector<int> res = Top_View(tree);
    for (auto vertical : res)
    {
        cout << vertical << " ";
    }
    cout << endl;

    return 0;
}