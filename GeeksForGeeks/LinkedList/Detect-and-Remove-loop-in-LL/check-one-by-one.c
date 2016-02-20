// C program to detect and and remove a loop in linked list
// we check here every node from the loop node to see if is the next pointer of loop node

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void removeloop(struct node *loop_node,struct node *head);

/* function to detect cycle using floyd's algorithms */
int detectAndRemoveLoop(struct node *head)
{
    struct node* slowpointer=head;
    struct node* fastpointer=head;

    while(fastpointer && fastpointer->next)
    {
        slowpointer=slowpointer->next;
        fastpointer=fastpointer->next->next;

        if(slowpointer == fastpointer)
        {
            removeloop(slowpointer,head);
            return 1;
        }
    }

    return 0;
}

/* function which actually removes the loop */
void removeloop(struct node *loopnode,struct node* head)
{
    struct node *ptr1;
    struct node *ptr2;

    ptr1=head;
    ptr2=loopnode;

    while(1)
    {
        ptr2=loopnode;
        while(ptr2->next!=loopnode && ptr2->next!=ptr1)
            ptr2=ptr2->next;

        if(ptr2->next==ptr1)
            break;

        ptr1=ptr1->next;
    }

    ptr2->next=NULL;
}

/* function to print the list */
void printList(struct node *head)
{
    struct node *ptr=head;

    while(ptr)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}

/* function to create a new node */
struct node *newNode(int val)
{
    struct node * newnode=(struct node*)malloc(sizeof(struct node));

    newnode->data=val;
    newnode->next=NULL;
}

int main()
{
    struct node *head=NULL;

    head=newNode(1);
    head->next=newNode(2);
    head->next->next=newNode(3);
    head->next->next->next=newNode(4);

    /* 1->2->3->4 */

    /* create loop for testing */
    head->next->next->next->next=head->next;

    /* 1->2->3->4
          |_____|  */

    detectAndRemoveLoop(head);

    printList(head);

    return 0;
}


