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
    ListNode *detectCycle(ListNode *head) {
        
        ListNode *slow=head;
        ListNode *fast=head;
        int cycle=0;
        
        while(fast!=NULL && fast->next!=NULL)
            {
            fast=fast->next->next;
            slow=slow->next;
            
            if (fast==slow)
                {
                do{
                    slow=slow->next;cycle++;
                }while(slow!=fast);
                
                break;
                }
            }
        
        if(cycle==0) return NULL;
        
        slow=head;
        while(cycle--) fast=fast->next;
        
        while(slow!=fast)
            {
            slow=slow->next;
            fast=fast->next;
            }
        return slow;
    }
};