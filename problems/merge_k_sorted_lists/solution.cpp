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
    ListNode* merge2Lists(ListNode* head1, ListNode* head2){
        ListNode new_head(-1);
        ListNode* curr = &new_head;
        while(true){
            if(head1 == nullptr){
                curr->next = head2;
                break;
            }
            else if(head2 == nullptr){
                curr->next = head1;
                break;
            }

            if(head1->val <= head2->val){
                curr->next = head1;
                head1 = head1->next; 
            }
            else{
                curr->next = head2;
                head2 = head2->next;
            }

            curr = curr->next;
        }

        return new_head.next;
    }

    void helper(vector<ListNode*>& lists){
        auto size = lists.size();
        if(size <= 1){
            return;
        }

        lists[size - 2] = merge2Lists(lists[size - 2], lists[size - 1]);
        lists.pop_back();
        helper(lists);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        helper(lists);
        return lists.empty() ? nullptr : lists[0];
    }
};