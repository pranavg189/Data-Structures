// C program to detect loop in a linked list (Global head version)
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

/* head declared as global variable */
struct node* head = NULL;

/* function to insert a node at the front of linked list */

void push(int new_node_val)  // we change value of head, that is why double pointer to head is required
{
    struct node* new_node=(struct node*)malloc(sizeof(struct node));

    new_node->data = new_node_val;
    new_node->next = head;

    head=new_node;
}

/* function to detect a loop in a linked list using floyds algorithm */
void detectLoop()
{
    int loopfound=0;
    struct node* slowpointer=head;
    struct node* fastpointer=head;

    while(fastpointer && fastpointer->next)
    {
        slowpointer=slowpointer->next;
        fastpointer=fastpointer->next->next;

        if(slowpointer==fastpointer)
        {
            printf("loop found in the linked list.\n");
            loopfound=1;
            break;
        }

    }

    if(loopfound==0)
        printf("no loop found in the linked list.\n");

}


int main()
{

    /* create initial linked list as:

    4->3->2->1

    */

    push(1);
    push(2);
    push(3);
    push(4);



    /* create a loop in linked list for test

    4->3->2->1
    |________|

    */

    head->next->next->next->next=head;

    detectLoop();

    return 0;
}
