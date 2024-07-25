class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> ans;

        if (n == 1) {
            ans.push_back(new TreeNode());
            return ans;
        }

        if (n % 2 == 0) {
            return ans;
        }

        for (int i = 1; i < n; i += 2) {
            vector<TreeNode*> leftSubtree = allPossibleFBT(i);
            vector<TreeNode*> rightSubtree = allPossibleFBT(n - i - 1);

            for (int j = 0; j < leftSubtree.size(); j++) {
                for (int k = 0; k < rightSubtree.size(); k++) {
                    TreeNode* root = new TreeNode();
                    root->left = leftSubtree[j];
                    root->right = rightSubtree[k];
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
};