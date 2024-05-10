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
private:
    ListNode* merge(ListNode* left, ListNode* right)
    {
        ListNode head(0);
        ListNode* node = &head;
        while(left && right)
        {
            if(left->val < right->val)
            {
                node->next = left;
                left = left->next;
            }
            else
            {
                node->next = right;
                right = right->next;
            }

            node = node->next;
        }

        node->next = left ? left : right;
        return head.next;
    }

public:
    ListNode* sortList(ListNode* head) 
    {
        if(!head || !head->next) return head;
        ListNode* mid = head;
        ListNode* fast = head->next;
        while(fast && fast->next)
        {
            mid = mid->next;
            fast = fast->next->next;
        }
        
        fast = mid->next;
        mid->next = nullptr;
        return merge(sortList(head),  sortList(fast));
    }
};
