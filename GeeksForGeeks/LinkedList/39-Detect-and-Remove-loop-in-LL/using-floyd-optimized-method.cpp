// C++ program to remove the loop in a linked list

/* Idea: Here, we first use floyd's algorithm to detect the loop and
 detect the meeting node of slow and fast pointers in the loop.

 Now, we move the slow pointer to head of linked list and move both
 the slow and fast pointers at the same pace (by one node).we loop till
 they meet at the starting of the node. This can be detected by checking
 if fast points to slow at some point. When it happens, slow is at the starting
 of node of loop and fast is at end node of loop. Loop can be removed by setting
 fast to point to NULL.

 This is possible because of the following property:

 the distance between head to start point of loop = distance between meeting node in loop to start point of loop

 For more detailed explaination,

 Refer:http://javabypatel.blogspot.in/2015/12/detect-loop-in-linked-list.html

 */

#include <bits/stdc++.h>

struct node{
    int data;
    struct node* next;
};

void detectAndRemove(struct node* head)
{
    struct node* slow=head;
    struct node* fast=head->next;

    while(slow && fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast)
            break;
    }

    if(slow==fast)          // if loop is found
    {
        slow=head;          // move slow to head

        while(slow!=fast->next)
        {
            slow=slow->next;
            fast=fast->next;
        }

        fast->next=NULL;       // set the end node of loop to point to NULL
    }
}

struct node *newNode(int val)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data=val;
    newnode->next=NULL;

    return newnode;
};

void printList(struct node* head)
{
    struct node* temp=head;

    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }

    printf("NULL");
}

int main()
{
    struct node* head=newNode(2);

    head->next=newNode(4);
    head->next->next = newNode(5);
    head->next->next->next = newNode(6);

    // create loop between 4th node and 2nd node
    head->next->next->next->next = head->next;

    detectAndRemove(head);

    printf("Linked list after removing the loop is\n");

    printList(head);

    return 0;

}
