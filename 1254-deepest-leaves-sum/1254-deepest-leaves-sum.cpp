class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        if (!root) return 0;
        
        queue<TreeNode*> q;
        q.push(root);
        int deepestSum = 0;
        
        while (!q.empty()) {
            int levelSize = q.size();
            deepestSum = 0;
            
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                
                deepestSum += node->val;
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        
        return deepestSum;
    }
};
