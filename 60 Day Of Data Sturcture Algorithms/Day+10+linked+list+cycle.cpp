#include "Headerfile.h"

class llnode
{
public:
    int data;
    llnode *next;

    llnode(int val)
    {
        data = val;
        next = NULL;
    }
};

bool linkedlistcycle(llnode *root)
{
    // base case
    // if (!root)
    //     return false;

    llnode *slow = root;
    llnode *fast = root;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            cout << "cycle detected" << endl;
            return 1;
        }
    }

    return 0;
}

// 1->2->3->4->5->6->7-> NULL
//          |     |
//          <-<-<-<

void print(llnode *head)
{
    while (head->next != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << head->data << "->NULL" << endl;
}

int main()
{
    llnode *head = new llnode(1);
    head->next = new llnode(2);
    head->next->next = new llnode(3);
    head->next->next->next = new llnode(4);
    head->next->next->next->next = new llnode(5);
    head->next->next->next->next->next = new llnode(6);
    head->next->next->next->next->next->next = new llnode(7);
    head->next->next->next->next->next->next = head->next->next->next;

    // Detect a cycle in a linked list
    cout << linkedlistcycle(head) << endl;

    print(head);

    return 0;
}