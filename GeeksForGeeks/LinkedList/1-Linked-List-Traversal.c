// A Simple C program to traverse a linked list
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

/* function to traverse and print the nodes of the linked list */
void printList(struct node* n)
{
    while(n != NULL)
    {
        printf("%d ",n->data);
        n = n->next;
    }
}

int main()
{
    struct node* head = NULL;
    struct node* second = NULL;
    struct node* third = NULL;

    head=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));

    head->data=1;
    head->next=second;

    second->data=2;
    second->next=third;

    third->data=3;
    third->next=NULL;

    printList(head);

    return 0;
}
