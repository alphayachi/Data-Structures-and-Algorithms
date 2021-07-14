// { Driver Code Starts
#include <iostream>
#include <cstdio>
using namespace std;

/* a node of the singly linked list */
struct node
{
    int data;
    struct node *next;

    node(int x)
    {
        data = x;
        next = NULL;
    }
};

/* A utility function to insert a node at the beginning of linked list */
void push(struct node **head_ref, int new_data)
{
    /* allocate node */
    struct node *new_node = new node(new_data);

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

/* A utility function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
void quickSort(struct node **headRef);
int main()
{
    int t, n, x;
    cin >> t;
    while (t--)
    {

        cin >> n;
        n = n - 1;
        cin >> x;
        node *temp, *head = new node(x);
        temp = head;
        while (n--)
        {
            cin >> x;
            temp->next = new node(x);
            temp = temp->next;
        }

        quickSort(&head);

        printList(head);
        while (head != NULL)
        {
            temp = head;
            head = head->next;
            free(temp);
        }
    }
    return 0;
} // } Driver Code Ends

/* a node of the singly linked list 
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
}; */

struct node *partition(struct node *head, struct node *tail)
{
    node *prev = head, *cur = head->next;
    node *pivot = head;
    while (cur != tail->next)
    {
        if (cur->data < pivot->data)
        {
            swap(prev->next->data, cur->data);
            prev = prev->next;
        }
        cur = cur->next;
    }
    swap(pivot->data, prev->data);
    return prev;
}

void quickSortRec(struct node *head, struct node *tail)
{
    if (head == tail || tail == NULL || head == NULL)
        return;
    // To find the pivot element
    struct node *pivot = partition(head, tail);

    // Recursive calls to quickSortRec procedure
    quickSortRec(head, pivot);
    quickSortRec(pivot->next, tail);
}

void quickSort(struct node **headRef)
{
    node *tail = *headRef;
    //To find the tail
    while (tail->next != NULL)
        tail = tail->next;
    quickSortRec(*headRef, tail);
}