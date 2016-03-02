// C++ program to delete a node from linked list where a key is given

/* Idea: While deleting a node given a key, 4 cases arise:

1) key is found at head node -
    two subcases arise here: if (head is the only node is linked list) or (there are some nodes after head node)
2) key is found in between
3) key is found at the last node
4) key is not found at all

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
    struct node* cur;

    cur=head;

    while(cur != NULL)
    {
        printf("%d->",cur->data);
        cur = cur->next;
    }

    printf("NULL\n");
}

void deleteNode(int key)
{
    if(head->data==key)     // if key is found at head itself
    {
        if(head->next == NULL)          // if only head is present in the linked list
        {
            head=NULL;
        }
        else
        {
            head=head->next;        // if some node is present after head
        }
    }
    else
    {
        struct node* cur;
        struct node* prev;

        cur = head;

        while(cur->data != key && cur->next!=NULL)
        {
            prev=cur;
            cur=cur->next;
        }

        if(cur->next==NULL)
        {
            if(cur->data==key)
            {
                cur=NULL;
                prev->next=NULL;
            }
            else
                printf("key not found in the linked list\n");
        }
        else
        {
            prev->next=cur->next;
        }
    }
}

int main()
{
    append(1);
    append(2);
    append(5);
    append(6);

    deleteNode(6);

    printList();
    return 0;
}


