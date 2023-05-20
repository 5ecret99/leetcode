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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode new_head(-1);
        auto* curr = &new_head;
        
        while(true){
            if(!list1){
                curr->next = list2;
                break;
            }
            else if(!list2){
                curr->next = list1;
                break;
            }

            if(list1->val <= list2->val){
                curr->next = list1;
                list1 = list1->next; 
            }
            else{
                curr->next = list2;
                list2 = list2->next;
            }

            curr = curr->next;
        }

        return new_head.next;
    }
};