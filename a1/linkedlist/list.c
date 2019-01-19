#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct nodeStruct *List_createNode(int item)
{
    ListNode *head = NULL;
    head = malloc(sizeof(ListNode));
    head->item = item;
    return head;
}

void List_insertHead(struct nodeStruct **headRef, struct nodeStruct *node)
{
    if (*headRef == NULL)
    {
        node->next = NULL;
        *headRef = node;
        return;
    }
        
    node->next = *headRef;
    *headRef = node;
    printf("Insert head value is : %d \n", node->item);
}

void List_insertTail(struct nodeStruct **headRef, struct nodeStruct *node)
{
    ListNode *current = *headRef;

    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = node;
    printf("Insert tail value is : %d \n", node->item);
}

int List_countNodes(struct nodeStruct *head)
{
    int count = 0;
    ListNode *current = head;
    while (current != NULL)
    {
        
        printf("Current value = %d \n", current->item);
        current = current->next;
        count++;
        
    }
    return count;
}

struct nodeStruct *List_findNode(struct nodeStruct *head, int item)
{

    ListNode *current = head;
    while (current != NULL)
    {
        if (current->item == item)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void List_deleteNode(struct nodeStruct **headRef, struct nodeStruct *node)
{
    ListNode *pre = NULL;
    pre = malloc(sizeof(ListNode));
    pre->item = -100000;
    pre->next = *headRef;
    ListNode *current = *headRef;
    while (current != NULL)
    {
        if (current->item == node->item)
        {
            pre->next = node->next;
            return;
        }

        pre = current;
        current = current->next;
    }
}


void List_sort(struct nodeStruct **headRef)
{
    ListNode *head = *headRef;
    ListNode *a;
    ListNode *b;

    if ((head == NULL) || (head->next == NULL))
    {
        return;
    }

    FrontBackSplit(head, &a, &b);

    List_sort(&a);
    List_sort(&b);

    *headRef = SortedMerge(a, b);
}

struct nodeStruct *SortedMerge(struct nodeStruct *a, struct nodeStruct *b)
{
    ListNode *result = NULL;

    /* Base cases */
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);

    /* Pick either a or b, and recur */
    if (a->item <= b->item)
    {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return (result);
}

void FrontBackSplit(struct nodeStruct *source,
                    struct nodeStruct **frontRef, 
                    struct nodeStruct **backRef)
{
    ListNode *fast;
    ListNode *slow;
    slow = source;
    fast = source->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

/* Function to print nodes in a given linked list */
void printList(struct nodeStruct *node)
{
    while (node != NULL)
    {
        printf("%d ", node->item);
        node = node->next;
    }
}

/* Function to insert a node at the beginging of the linked list */
void push(struct nodeStruct **head_ref, int new_data)
{
    /* allocate node */
    ListNode *new_node =
        (ListNode *)malloc(sizeof(ListNode));

    /* put in the data */
    new_node->item = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}
