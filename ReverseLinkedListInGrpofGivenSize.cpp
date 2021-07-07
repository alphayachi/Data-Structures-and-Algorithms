// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

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

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
public:
    struct node *reverse(struct node *head, int k)
    {
        if (head == NULL || head->next == NULL)
            return head;

        node *prev_tail = NULL;
        node *curr_head = NULL;
        node *temp_tail = head;
        int cnt = 0;

        node *prev = NULL;
        node *curr = head;
        node *next = head->next;

        int set_counter = 0;
        node *mod_head = NULL;

        while (curr != NULL)
        {
            if (cnt == 0)
                temp_tail = curr;
            curr->next = prev;
            cnt++;
            if (cnt == k || next == NULL)
            {
                if (set_counter == 0)
                    mod_head = curr;
                curr_head = curr;
                if (prev_tail != NULL)
                    prev_tail->next = curr_head;
                prev_tail = temp_tail;
                cnt = 0;
                set_counter++;
            }
            prev = curr;
            curr = next;
            if (curr != NULL)
                next = curr->next;
        }
        prev_tail->next = NULL;
        return mod_head;
    }
};

// { Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin >> t;

    while (t--)
    {
        struct node *head = NULL;
        struct node *temp = NULL;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            int value;
            cin >> value;
            if (i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }

        int k;
        cin >> k;

        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }

    return (0);
}

// } Driver Code Ends