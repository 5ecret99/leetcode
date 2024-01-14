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
 #include <span>
class Solution {
    TreeNode* tree_builder(span<int> preorder, span<int> inorder)
    {
        if(preorder.empty() || inorder.empty()) return nullptr;
        auto mid = distance(inorder.begin(), find(inorder.begin(), inorder.end(), preorder[0]));
        auto node = new TreeNode { preorder[0]
                            ,tree_builder(preorder.subspan(1, mid + 1), inorder.subspan(0, mid))
                            ,tree_builder(preorder.subspan(mid + 1), inorder.subspan(mid + 1))};
        return node;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return tree_builder(span<int>(preorder.data(), preorder.size()), span<int>(inorder.data(), inorder.size()));
    }
};
