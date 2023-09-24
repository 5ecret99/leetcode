/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void rightSideView(TreeNode* node, vector<int>& view, int level = 0) {
        if(!node) return;
        
        if(view.size() == level)
          view.push_back(node->val);

        rightSideView(node->right, view, level + 1); 
        rightSideView(node->left, view, level + 1); 
    }

public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> view{};
        rightSideView(root, view);
        return view;
    }
};