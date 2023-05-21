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
    ListNode* helper(ListNode* head) {
        if(head == nullptr){
            return nullptr;
        }
        else if(head->next == nullptr){
            return head;
        }

        auto* prev_a = head;
        auto* prev_c = head->next->next;
        head = head->next;
        head->next = prev_a;
        prev_a->next = helper(prev_c);
        return head;
    }
    ListNode* swapPairs(ListNode* head) {
        return helper(head);
    }
};