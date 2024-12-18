#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <process.h>
#include <iomanip>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <fstream>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
    ~Node();
};

void printvector(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << "    ";
    inorder(root->right);
}
void Print_Tree(Node *root)
{
    vector<int> arr;
    // edge case
    if(!root)
    return;

    inorder(root);
                
    }

    
        

