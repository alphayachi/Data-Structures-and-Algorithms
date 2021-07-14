#include <bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    Node *next;
    Node *prev;
    // Node(char d)
    // {
    //     data = d;
    //     next = NULL;
    //     prev = NULL;
    // }
};

void rotate(Node **headRef, int N)
{
    if (N == 0)
        return;
    Node *head = *headRef;
    if (head == NULL || head->next == NULL)
        return;
    while (head->next)
        head = head->next;
    Node *tail = head;
    head = *headRef;
    Node *prev = tail;
    Node *curr = head;
    Node *next = head->next;
    tail->next = head;
    head->prev = tail;
    Node *head_temp = head;
    Node *tail_temp = tail;
    for (int i = 0; i < N; i++)
    {
        head_temp = head_temp->prev;
        tail_temp = tail_temp->prev;
    }
    tail_temp->next = NULL;
    tail = tail_temp;
    head_temp->prev = NULL;
    *headRef = head_temp;
    return;
}
void push(struct Node **head_ref, int new_data)
{
    struct Node *new_node = new Node;
    new_node->data = new_data;
    new_node->prev = NULL;
    new_node->next = (*head_ref);
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
    *head_ref = new_node;
}

/* Function to print linked list */
void printList(struct Node *node)
{
    while (node->next != NULL)
    {
        cout << node->data << " "
             << "<=>"
             << " ";
        node = node->next;
    }
    cout << node->data;
}

// Driver's Code
int main(void)
{
    /* Start with the empty list */
    struct Node *head = NULL;

    /* Let us create the doubly
      linked list a<->b<->c<->d<->e */
    push(&head, 'e');
    push(&head, 'd');
    push(&head, 'c');
    push(&head, 'b');
    push(&head, 'a');

    int N = 2;

    cout << "Given linked list \n";
    printList(head);
    rotate(&head, N);

    cout << "\nRotated Linked list \n";
    printList(head);

    return 0;
}