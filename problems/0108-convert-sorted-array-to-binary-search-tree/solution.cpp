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
class Solution 
{
private:
    TreeNode* helper(vector<int>& nums, int start, int end)
    {
        if( end <= start) return nullptr;
        int mid = start + (end - start) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = helper(nums, start, mid);
        node->right = helper(nums, mid + 1, end);
        return node;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
       return helper(nums, 0, nums.size()); 
    }
};
