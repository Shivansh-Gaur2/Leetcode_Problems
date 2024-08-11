class Solution {
public:
    pair<bool, TreeNode*> dfs(TreeNode* root) {
        if (!root) {
            return {false, nullptr}; 
        }
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        
        if (!left.first) root->left = nullptr;
        if (!right.first) root->right = nullptr;
        
        bool containsOne = (root->val == 1) || left.first || right.first;
        
        return {containsOne, containsOne ? root : nullptr};
    }

    TreeNode* pruneTree(TreeNode* root) {
        return dfs(root).second;
    }
};
