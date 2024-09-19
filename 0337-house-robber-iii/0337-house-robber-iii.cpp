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
    int doingRobbery(TreeNode *curr, unordered_map<TreeNode *, int> &ump){
        if(curr == nullptr) return 0;
        if(ump.find(curr) != ump.end()) return ump[curr];

        int robbed = curr->val + 
                     ((curr->left) ? (doingRobbery(curr->left->left, ump) + doingRobbery(curr->left->right, ump)) : 0) + 
                     ((curr->right) ? (doingRobbery(curr->right->left, ump) + doingRobbery(curr->right->right, ump)) : 0);

        int notRobbed = doingRobbery(curr->left, ump) + doingRobbery(curr->right, ump);

        return ump[curr] = max(robbed, notRobbed);
    }

public:
    int rob(TreeNode* root) {
        unordered_map<TreeNode *, int> ump;
        return doingRobbery(root, ump);
    }
};