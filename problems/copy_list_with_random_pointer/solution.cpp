/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        unordered_map<Node*, Node*> mp;
        Node* cpy_head = new Node{*head};
        Node* curr = cpy_head;
        mp[head] = curr;

        while(head->next){
            curr->next = new Node{*head->next};
            curr = curr->next;
            head = head->next;
            mp[head] = curr;
        }

        curr = cpy_head;
        while(curr){
            if (curr->random) 
                curr->random = mp[curr->random];
            
            curr = curr->next;
        }

        return cpy_head;
    }
};