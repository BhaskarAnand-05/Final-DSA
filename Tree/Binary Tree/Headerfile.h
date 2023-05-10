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

void Print_Tree(Node *root)
{
    vector<int> arr;
    // edge case
    if(!root)
    return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        
        Node* temp = q.front();
        q.pop();

        if(temp->left)
        q.push(temp->left);
        if(temp->right)
        q.push(temp->right);

        arr.push_back(temp->data);
        }
        
     for (int i = 0; i < arr.size(); i++)
    {
        cout<< arr[i]<<" ";
    }   
    cout<<endl;
                
    }

    
        

