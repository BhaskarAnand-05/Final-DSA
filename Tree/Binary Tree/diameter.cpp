#include "Headerfile.h"

int solve(Node* root, int & ans)
{
    // edge case
    if(!root)
    return 0;

    int left = solve(root->left,ans);
    int right = solve(root->right,ans);
    
    ans = max(ans, left+right+1);

    return max(left,right)+1;

}
int finddiameter(Node* root)
{
    int ans = 0;

    solve(root,ans);

    return ans;
}

int main()
{
    ofstream file;
    file.open("Diameter.txt");
    if(!file)
    {
        cout<<"ERROR$$$"<<endl;
        return 0;
    }

    Node *tree = new Node(1);
    tree->left = new Node(2);
    tree->right = new Node(3);
    tree->left->left = new Node(4);
    tree->left->right = new Node(5);
    tree->right->left = new Node(6);
    tree->right->right = new Node(7);

    int ans = finddiameter(tree);

    file<<"Diameter of the Binary Tree = "<<ans;

    return 0;
}