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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(!head || !head->next) return head;
        ListNode* curr = head;
        int i = 1;
        while(curr->next)
        {
            curr = curr->next;
            ++i;
        }

        curr->next = head;
        i-=  k % i;
        curr = head;
        while(--i)
            curr = curr->next;
        
        head = curr->next;
        curr->next = nullptr;

        return head; 
    }
};
