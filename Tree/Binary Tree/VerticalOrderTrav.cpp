#include "Headerfile.h"

// Vertical Order Traversal
vector<vector<int>> Vertical_Order(Node *root)
{

    vector<vector<int>> res;
    // edge case
    if (!root)
    {
        return res;
    }
    map<int, map<int, multiset<int>>> ans;
    queue<pair<Node *, pair<int, int>>> q;

    q.push({root, {0, 0}});

    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();
        Node *node = temp.first;
        int x = temp.second.first;
        int y = temp.second.second;
        ans[x][y].insert(node->data);
        if (temp.first->left)
            q.push({temp.first->left, {temp.second.first - 1, temp.second.second + 1}});
        if (temp.first->right)
            q.push({temp.first->right, {temp.second.first + 1, temp.second.second + 1}});
    }
    for (auto p : ans)
    {
        vector<int> col;
        for (auto q : p.second)
        {
            // col.insert(col.end(), p.second.begin(), p.second.end());
            for(auto i : q.second)
                col.push_back(i);
        }
        res.push_back(col);
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

    vector<vector<int>> res = Vertical_Order(tree);
    for (auto vertical : res)
    {
        for (auto nodeVal : vertical)
        {
            cout << nodeVal << " ";
        }
        cout << endl;
    }

    return 0;
}