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
    ListNode* removeElements(ListNode* head, int val) 
    {
        ListNode new_head;
        auto curr = &new_head;
        while(head)
        {
            if(head->val != val)
            {
                curr->next = head;
                curr = curr->next;
            }

            head = head->next;
        }

        curr->next = nullptr;
        return new_head.next;
    }
};
