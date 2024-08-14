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
    vector<string> res;
    void dfs(TreeNode* node, const string& curr = "")
    {
        if(!node) return;
        string new_curr{curr}; 

        if(!curr.empty())
            new_curr+= "->";

        new_curr +=  to_string(node->val);
        
        if(!node->left && !node->right)
        {
            res.push_back(new_curr);
            return;
        }

        dfs(node->left, new_curr);
        dfs(node->right, new_curr);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        dfs(root);
        return res; 
    }
};
