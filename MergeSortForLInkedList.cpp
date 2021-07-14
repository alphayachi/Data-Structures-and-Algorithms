// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/
void divideList(Node *head, Node **a, Node **b)
{
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }

    *a = head;
    *b = slow->next;
    slow->next = NULL;
}

Node *merge(Node *firstHalf, Node *secondHalf)
{
    Node *net_head = NULL;

    if (firstHalf == NULL)
        return secondHalf;
    else if (secondHalf == NULL)
        return firstHalf;

    if (firstHalf->data <= secondHalf->data)
    {
        net_head = firstHalf;
        net_head->next = merge(firstHalf->next, secondHalf);
    }
    else
    {
        net_head = secondHalf;
        net_head->next = merge(firstHalf, secondHalf->next);
    }
    return net_head;
}

class Solution
{
public:
    //Function to sort the given linked list using Merge Sort.
    Node *mergeSort(Node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        Node *a;
        Node *b;

        divideList(head, &a, &b);

        Node *firstHalf;
        Node *secondHalf;

        firstHalf = mergeSort(a);
        secondHalf = mergeSort(b);

        Node *net_head = merge(firstHalf, secondHalf);

        return net_head;
    }
};

// { Driver Code Starts.

void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node **head_ref, int new_data)
{
    Node *new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main()
{
    long test;
    cin >> test;
    while (test--)
    {
        struct Node *a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
} // } Driver Code Ends