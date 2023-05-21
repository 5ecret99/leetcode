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
    ListNode* helper(stack<ListNode*>& nodes_stack){
        if(nodes_stack.empty()){
            return nullptr;
        }

        auto* node = nodes_stack.top();
        nodes_stack.pop();
        node->next = helper(nodes_stack);
        return node;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        const auto knum = k;
        auto* prev_head = head;
        stack<ListNode*> nodes_stack;

        while(k--){
            if(head == nullptr){
                return prev_head;
            }
            nodes_stack.push(head);
            head = head->next;
        }

        auto* prev_next = nodes_stack.top()->next;
        auto* new_head = helper(nodes_stack);
        prev_head->next = reverseKGroup(prev_next, knum);
        return new_head;
    }
};
