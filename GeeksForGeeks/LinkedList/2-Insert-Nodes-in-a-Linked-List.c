/* A C program to insert a new node in a linked list for three conditions:

1) At the front of the linked list
2) After a given node
3) At the end of the linked list

This is a global head version.

*/

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node* head = NULL;


/* function to insert at the front of the linked list */
void push(int val)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));

    newNode->data=val;
    newNode->next=head;

    head=newNode;
}

/* function to insert a new node after a given node */
void insertAfter(struct node *prevnode, int newNodeValue)
{
    if(prevnode == NULL)
    {
        printf("previous node cannot be null");
        return;
    }

    struct node *newNode = (struct node*) malloc(sizeof(struct node));

    newNode->data = newNodeValue;
    newNode->next = prevnode->next;

    prevnode->next=newNode;

}

/* function to insert new node at the end of linked list */
void append(int val)
{
    struct node* ptr = head;

    struct node* newNode = (struct node*)malloc(sizeof(struct node));

    newNode->data = val;
    newNode->next = NULL;

    if(head == NULL)
    {
        head = newNode;
        return;
    }

    while(ptr->next)
        ptr = ptr->next;

    ptr->next = newNode;
}

/* function to the print the contents of linked list */
void printList()
{
    struct node *ptr = head;

    while(ptr)
    {
        printf("%d->",ptr->data);
        ptr = ptr->next;
    }

    printf("NULL\n");

}

int main()
{
    /* insert at end */
    append(3);
    append(4);
    append(5);
    append(9);

    printList();

    /* insert after a node 4 */
    insertAfter(head->next->next,0);

    printList();

    /* insert at the end */
    push(13);
    push(12);

    printList();
}

