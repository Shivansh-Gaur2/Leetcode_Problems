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
TreeNode* helper(int start, int end,  vector<int>& nums){
if(start > end){
    return NULL;
}
int i = max_element(nums.begin() + start, nums.begin() + end + 1) - nums.begin();
TreeNode* root= new TreeNode(nums[i]);
root->left = helper(start , i-1, nums);
root->right = helper(i+1, end ,nums);
return root;
}
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(0, nums.size()-1, nums);
    }
};