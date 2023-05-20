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
   ListNode* removeNthFromEnd(ListNode* head, int n) {
      if(!head){
         return nullptr;
      }

      ListNode new_head(-1);
      new_head.next = head;
      auto *slow = &new_head;
      auto *fast = &new_head;
      while(n--){
         fast = fast->next;
      }

      while(fast->next){
         fast = fast->next;
         slow = slow->next;
      }

      auto* temp = slow->next;
      slow->next = slow->next->next;
      delete temp;

      return new_head.next;
   }
};