#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

Node *getNode(int data)
{
    // allocate space
    Node *new_node = (Node *)malloc(sizeof(Node));

    // put in the data
    new_node->data = data;
    new_node->next = new_node->prev = NULL;
    return new_node;
}

// function to insert a node at the beginging
// of the Doubly Linked List
void push(Node **head_ref, Node *new_node)
{
    // since we are adding at the beginning,
    // prev is always NULL
    new_node->prev = NULL;

    // link the old list off the new node
    new_node->next = (*head_ref);

    // change prev of head node to new node
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;

    // move the head to point to the new node
    (*head_ref) = new_node;
}

Node *revListInGroupOfGivenSize(Node *head, int k)
{
    int setcount = 0;
    Node *curr = head;
    if (head == NULL || head->next == NULL)
        return head;
    Node *prev_tail = NULL;
    Node *curr_head = NULL;
    int cnt = 0;
    Node *temp_tail = NULL;
    Node *mod_head = NULL;
    while (curr != NULL)
    {
        if (cnt == 0)
            temp_tail = curr;

        Node *temp = curr->next;
        curr->next = curr->prev;
        curr->prev = temp;
        cnt++;
        if (cnt == k || temp == NULL)
        {
            curr_head = curr;
            if (prev_tail != NULL)
            {
                prev_tail->next = curr_head;
                curr_head->prev = prev_tail;
                prev_tail = temp_tail;
            }
            else
            {
                prev_tail = temp_tail;
            }
            if (setcount == 0)
            {
                mod_head = curr_head;
            }
            setcount++;
            cnt = 0;
        }
        curr = temp;
    }

    prev_tail->next = NULL;

    return mod_head;
}

void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

// Driver program to test above
int main()
{
    // Start with the empty list
    Node *head = NULL;

    // Create doubly linked: 10<->8<->4<->2
    push(&head, getNode(2));
    push(&head, getNode(4));
    push(&head, getNode(8));
    push(&head, getNode(10));

    int k = 2;

    cout << "Original list: ";
    printList(head);

    // Reverse doubly linked list in groups of
    // size 'k'
    head = revListInGroupOfGivenSize(head, k);

    cout << "\nModified list: ";
    printList(head);

    return 0;
}