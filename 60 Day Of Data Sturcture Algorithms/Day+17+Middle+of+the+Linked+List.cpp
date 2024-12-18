#include "Headerfile.h"

// CREATING A LINKED LIST
class llnode
{
public:
    int data;
    llnode *next;

    llnode(int value)
    {
        data = value;
        next = NULL;
    }
};

// ITERATIVE WAY
llnode *itr_middle_linked_list(llnode *head)
{
    // base case
    if (!head)
        return NULL;

    int count = 0, start = 0;
    llnode *temp = head;
    while (temp)
    {
        count++;
        temp = temp->next;
    }

    while (start != count / 2)
    {
        start++;
        head = head->next;
    }

    return head;
}

// RECURSIVE WAY
int find_mid_index(llnode *head)
{
    int count = 0;
    llnode *temp = head;
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    return count / 2;
}
llnode *solve(llnode *head, int start, int mid)
{
    // base case
    if (start == mid - 1)
        return head->next;

    llnode *ans = solve(head->next, start + 1, mid);
    // cout << ans->data << endl;
    return ans;
}

llnode *rec_middle_linked_list(llnode *head)
{
    // base case
    if (!head)
        return NULL;

    int mid = find_mid_index(head);
    // cout << mid << endl;

    return solve(head, 0, mid);
}

// TWO POINTER APPROACH
llnode *middle_linked_list(llnode *head)
{
    llnode *slow = head;
    llnode *fast = head;

    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

int main()
{
    llnode *node = new llnode(1);
    node->next = new llnode(2);
    node->next->next = new llnode(3);
    node->next->next->next = new llnode(4);
    node->next->next->next->next = new llnode(5);
    node->next->next->next->next->next = new llnode(6);
    node->next->next->next->next->next->next = new llnode(7);

    cout << middle_linked_list(node)->data << endl;

    cout << itr_middle_linked_list(node)->data << endl;

    cout << rec_middle_linked_list(node)->data << endl;

    return 0;
}