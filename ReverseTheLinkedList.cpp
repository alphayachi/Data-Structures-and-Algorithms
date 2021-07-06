#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int new_data) : next(NULL)
    {
        data = new_data;
    }
};

node *reversell(node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    node *prev = NULL;
    node *curr = head;
    node *next = head->next;
    while (curr != NULL)
    {
        curr->next = prev;
        prev = curr;
        curr = next;
        if (curr != NULL)
            next = curr->next;
    }
    head = prev;
    return head;
}

node *reverserecll(node *curr, node *head)
{
    if (head == NULL)
        return curr;

    node *temp = head->next;
    head->next = curr;
    curr = head;
    head = temp;
    return reverserecll(curr, head);
}

void printll(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

void insertatEndll(node *&head, int data)
{
    if (head == NULL)
    {
        node *n = new node(data);
        head = n;
    }
    else
    {
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        node *n = new node(data);
        temp->next = n;
    }
}

int main()
{
    node *head = NULL;
    insertatEndll(head, 0);
    insertatEndll(head, 1);
    insertatEndll(head, 2);
    insertatEndll(head, 3);
    insertatEndll(head, 4);

    printll(head);

    cout << endl;
    node *curr = NULL;
    node *head1 = reverserecll(curr, head);
    printll(head1);

    return 0;
}