// C++ program to delete a node from linked list where a key is given

/* Idea: While deleting a node given a key, 4 cases arise:

1) key is found at head node
2) key is found in between
4) key is not found at all

we simply traverse the linked list searching for given key and deleting it appropriately
*/

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node *head;

/* Function to append a key to linked list */
void append(int key)
{
    struct node *cur;

    if(head == NULL)
    {
        head = (struct node*)malloc(sizeof(struct node));

        head->data=key;
        head->next=NULL;
    }
    else
    {
        cur=head;

        while(cur->next != NULL)
        {
            cur=cur->next;
        }

        struct node* newnode = (struct node*)malloc(sizeof(struct node));

        newnode->data=key;
        newnode->next=NULL;

        cur->next=newnode;

    }
}

void printList()
{
    struct node* temp=head;

    while(temp != NULL)
    {
        printf("%d->",temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

/* Function to delete a node from LL given a key */
void deleteNode(int key)
{
    struct node* temp = head;   // variable to traverse the LL
    struct node* prev;          // variable to keep track of previous node

    if(head==NULL)                  // linked list is empty
    {
        printf("Linked list empty.\n");
        return;
    }

    if(temp!=NULL && temp->data==key) // key is found at head itself
    {
        head = temp->next;
        free(temp);
        return;
    }

    while(temp!=NULL && temp->data!=key)  // else traverse linked list until key is found
    {
        prev=temp;
        temp=temp->next;
    }

    if(temp==NULL)                     // we reached end of LL but still did'nt find the key
    {
        printf("key not found in linked list.\n");
        return;
    }

    prev->next=temp->next;

    free(temp);

}

int main()
{
    /* create linked list : 1->2->5->6->NULL */
    append(1);
    append(2);
    append(5);
    append(6);

    printf("Linked list before deletion:\n");
    printList();

    deleteNode(2);

    printf("Linked list after deletion:\n");
    printList();
    return 0;
}



