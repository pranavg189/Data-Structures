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
    bool hasCycle(ListNode *head) {             /* Floyd's Cycle Detection Algorithm */
        
        ListNode *slowpointer=head;
        ListNode *fastpointer=head;
        
        while(fastpointer && fastpointer->next)
        {
            slowpointer=slowpointer->next;
            fastpointer=fastpointer->next->next;
            
            if(slowpointer==fastpointer)
            {
                return true;
            }
        }
        
        return false;
        
    }
};