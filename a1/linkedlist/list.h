#ifndef LIST_H   
#define LIST_H

typedef struct nodeStruct {
    int item;
    struct nodeStruct *next;
} ListNode;

struct nodeStruct* List_createNode(int item);

void List_insertHead (struct nodeStruct **headRef, struct nodeStruct *node);

void List_insertTail (struct nodeStruct **headRef, struct nodeStruct *node);

int List_countNodes (struct nodeStruct *head);

struct nodeStruct* List_findNode(struct nodeStruct *head, int item);

void List_deleteNode (struct nodeStruct **headRef, struct nodeStruct *node);

void List_sort (struct nodeStruct **headRef);

struct nodeStruct *SortedMerge(struct nodeStruct *a, struct nodeStruct *b);

void FrontBackSplit(struct nodeStruct *source,
                    struct nodeStruct **frontRef, 
                    struct nodeStruct **backRef);

void push(struct nodeStruct **head_ref, int new_data);
void printList(struct nodeStruct *node);

#endif