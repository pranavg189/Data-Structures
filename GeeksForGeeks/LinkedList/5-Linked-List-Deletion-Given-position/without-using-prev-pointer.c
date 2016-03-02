// C++ program to delete a node from linked list where a key is given

/* Idea: While deleting a node given a key, 4 cases arise:

1) key is found at head node
2) key is found in between
4) key is not found at all

we simply traverse the linked list upto the given position and deleting it appropriately
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

/* Function to delete a node from LL given a node position (position starts from zero)
   Here we do not use "prev" pointer.
*/
void deleteNode(int position)
{
    struct node* temp=head;

    //struct node* prev;        // we dont use the prev pointer here

    if(head==NULL) return;      // linked list empty

    if(position==0)             // node to be deleted is head
    {
        head=temp->next;
        free(temp);
        return;
    }

    // loop until position-1 times and traverse upto the previous of the node to be deleted
    for(int i=1;temp!=NULL && i<position;i++)
    {
        temp=temp->next;
    }

    if(temp==NULL)
    {
        printf("position exceeds size of linked list.\n");
        return;
    }

    if(temp->next==NULL)
    {
        printf("node to be deleted is NULL or does not exist.\n");
        return;
    }

    /* Here , temp->next denotes the node to be deleted
              temp is the node previous to the node to be deleted
              temp->next->next is the node after the node to be deleted
    */

    struct node* nextNode=temp->next->next;

    // free the unlinked node
    // It is necessary free memory before linking the previous and next nodes

    free(temp->next);

    temp->next=nextNode;
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

    deleteNode(1);

    printf("Linked list after deletion:\n");
    printList();
    return 0;
}
