#include"Headerfile.h"

// class Node
// {
//     public:
//     int data;
//     Node *left = NULL;
//     Node *right = NULL;

//     Node(int val)
//     {
//         data = val;
//     }
// };
void Traversal(Node * root)
{
    vector<vector<int>> ans;
    vector<int> preorder ,inorder, postorder;
    int num = 1;

    stack<pair<Node *,int>>st;
    
    Node *curr = root;
    
    st.push({curr,1});
    

    while (!st.empty() && curr != NULL)
    {
        
        auto temp = st.top();
        st.pop();
        if (temp.second == 1)  // Case Of Preorder
        {
            preorder.push_back(temp.first->data);
            temp.second++;
            st.push(temp);
            
            if (temp.first->left)
            {
                st.push({temp.first->left,1});
            }
            
        }

        else if (temp.second == 2) // Case of inorder
        {
            inorder.push_back(temp.first->data);
            temp.second++;
            st.push(temp);

            if (temp.first->right)
            {
                st.push({temp.first->right, 1});
            }
        }

        else if (temp.second == 3)
        {
            postorder.push_back(temp.first->data);
        }
        
    }
    
    ans.push_back(preorder);
    ans.push_back(inorder);
    ans.push_back(postorder);

    // cout<<"Preorder = "<<endl;
    // printvector(preorder);
    // cout<<"Inorder ="<<endl;
    // printvector(inorder);
    // cout<<"Postorder = "<<endl;
    // printvector(postorder);
    
}

int main()
{
    
    Node *tree = new Node(1);
    tree->left = new Node(2);
    tree->left->left = new Node(3);
    tree->left->left->left = new Node(4);
    tree->left->left->left->left = new Node(5);
    tree->right = new Node(6);
    tree->right->right = new Node(7);

    Traversal(tree);

    return 0;
}
 /*                                      1
                                        /  \ 
                                       2    6                          PreOrder - 1 2 3 4 5 6 7
                                      /      \                         InOrder  - 5 4 3 2 1 6 7 
                                     3        7                        Postorder- 5 4 3 2 7 6 1
                                    /
                                   4
                                  /
                                 5       */