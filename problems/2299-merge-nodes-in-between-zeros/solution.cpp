/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeNodes(ListNode* head)
    {
        ListNode* curr;
        ListNode* new_head;
        curr = head;
        new_head = curr;
        head = head->next;
        
        while(head)
        {
            if(head->val)
            {
                curr->val += head->val;
            }
            else if(head->next)
            {
                curr->next = head;
                curr = curr->next;
            }
                
            head = head->next;
        }

        curr->next = nullptr;
        return new_head;
    }
};
