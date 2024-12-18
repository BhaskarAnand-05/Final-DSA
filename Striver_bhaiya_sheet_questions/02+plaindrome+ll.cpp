#include "Headerfile.h"
/****************************************************************

    Following is the class structure of the LinkedListNode class:




*****************************************************************/
template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void print(LinkedListNode<int> *head)
{
    LinkedListNode<int> *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return;
}

LinkedListNode<int> *reverse(LinkedListNode<int> *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    LinkedListNode<int> *new_head = reverse(head->next);
    head->next->next = head;
    head->next = NULL;

    return new_head;
}
bool solve(LinkedListNode<int> *head, LinkedListNode<int> *head2)
{
    if (head == NULL && head2 == NULL)
    {
        return true;
    }

    if (head->data == head2->data)
        return true;

    if (head->data != head2->data)
        return false;

    return solve(head->next, head2->next);
}

bool isPalindrome(LinkedListNode<int> *head)
{
    // USING TWO PINTER APPROACH

    // base case
    if (!head)
        return true;

    LinkedListNode<int> *temp = reverse(head);
    cout << endl;
    print(temp);

    return solve(head, temp);
}

int main()
{
    LinkedListNode<int> *head = new LinkedListNode<int>(1);
    head->next = new LinkedListNode<int>(2);
    head->next->next = new LinkedListNode<int>(3);
    head->next->next->next = new LinkedListNode<int>(2);
    head->next->next->next->next = new LinkedListNode<int>(1);

    print(head);

    cout << endl
         << isPalindrome(head) << endl;

    return 0;
}