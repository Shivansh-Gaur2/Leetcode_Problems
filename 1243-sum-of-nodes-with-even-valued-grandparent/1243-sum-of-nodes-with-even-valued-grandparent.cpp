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
public:
    int helper(TreeNode* node, TreeNode* parent, TreeNode* grandparent) {
        if (node == NULL) {
            return 0;
        }

        int sum = 0;
        if (grandparent && grandparent->val % 2 == 0) {
            sum += node->val;
        }
        sum += helper(node->left, node, parent);
        sum += helper(node->right, node, parent);

        return sum;
    }

    int sumEvenGrandparent(TreeNode* root) {
        return helper(root, NULL, NULL);
    }
};