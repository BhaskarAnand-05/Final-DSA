#include "Headerfile.h"

vector<int> Bottom_View(Node *root)
{
    vector<int> result;
    // edge case 
    if(!root)
    return result;
    
    map<int,int> ans;
    queue <pair<Node*,int>> q;
    q.push({root,0});

    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();

        int x = temp.second;
        Node* node = temp.first;

        ans[x] = node->data;
        if (temp.first->left)
        {
            q.push({temp.first->left,temp.second -1});
        }
        if (temp.first->right)
        {
            q.push({temp.first->right, temp.second + 1});
        }
    }

    for(auto i : ans)
    {
        result.push_back(i.second);
    }

    return result;

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

    vector<int> result = Bottom_View(tree);
    for (auto i : result)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}