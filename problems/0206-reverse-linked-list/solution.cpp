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
    ListNode* reverseList(ListNode* curr) {
        ListNode* init = new ListNode{-1, curr};
        while(curr  && curr->next){
           auto tmp = init->next;
           init->next = curr->next;
           curr->next = curr->next->next;
           init->next->next = tmp;
        }

        return init->next;
    }
};
