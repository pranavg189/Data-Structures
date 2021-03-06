// C++ Program to find the length of linked list - Iterative version

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

int length(struct node* head)
{
    int len=0;

    struct node* temp = head;

    while(temp!=NULL)
    {
        len++;
        temp = temp->next;
    }

    return len;

}

struct node *newNode(int val)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data=val;
    newnode->next=NULL;

    return newnode;
};

int main()
{
    struct node* head = newNode(1);

    head->next=newNode(2);
    head->next->next=newNode(3);

    printf("Length of linked list is %d\n",length(head));
    return 0;
}
