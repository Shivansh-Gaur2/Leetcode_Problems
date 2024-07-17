/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, int> deleteMap;
    TreeNode* processTree(TreeNode* root, vector<TreeNode*>& result) {
        if (root == nullptr) {
            return nullptr;
        }
        if (deleteMap[root->val] > 0) {
            if (root->left != nullptr && deleteMap[root->left->val] == 0) {
                result.push_back(root->left);
            }
            if (root->right != nullptr && deleteMap[root->right->val] == 0) {
                result.push_back(root->right);
            }
            deleteMap[root->val] = 0;
            processTree(root->left, result);
            processTree(root->right, result);
            return nullptr;
        }
        root->left = processTree(root->left, result);
        root->right = processTree(root->right, result);

        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& toDelete) {
        vector<TreeNode*> result;
        int n = toDelete.size();
        for (int i = 0; i < n; i++) {
            deleteMap[toDelete[i]]++;
        }
        if (deleteMap[root->val] == 0) {
            result.push_back(root);
        }
        processTree(root, result);

        return result;
    }
};