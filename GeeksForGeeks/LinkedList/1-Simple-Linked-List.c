// A simple c program to create a linked list with three nodes

#include <stdio.h>
#include <stdlib.h>

/* Linked list structure definition */
struct node {
    int data;
    struct node* next;
};

int main()
{
    struct node* head = NULL;
    struct node* second = NULL;
    struct node* third = NULL;

    // allocate three nodes in the heap
    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));

    head->data=1;
    head->next=second;

    second->data=2;
    second->next=third;

    third->data=3;
    third->next=NULL;

    return 0;
}

