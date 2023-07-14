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
    

    void reorderList(ListNode* head) {
        vector<ListNode*> nodes{};
        while(head){
            nodes.push_back(head);
            head = head->next;
        }

        auto start = nodes.begin();
        auto end = nodes.end() - 1;
        while(start < end){
            (*(end - 1))->next = nullptr;
            (*end)->next = (*start)->next;
            (*start)->next = *end;
            end--;
            start++;
        }

        head = *nodes.begin();
    }
};