// Problem statement: Reverse a linked list

/* Idea:
    Here, my main idea is to partition the linked list
    into two parts. one the old linked list. other the new reversed
    linked list. here we push the "prev" node into the reversed linked
    list until we have finished the traversal of entire linked list.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
            struct ListNode* prev;
            struct ListNode* temp=head;

            head=NULL;

            while(temp!=NULL)
            {
                prev=temp;
                temp=temp->next;

                if(head==NULL)
                {
                 head=prev;
                 prev->next=NULL;
                }
                else
                 {
                     prev->next=head;
                     head=prev;
                 }
            }

            return head;
    }
};