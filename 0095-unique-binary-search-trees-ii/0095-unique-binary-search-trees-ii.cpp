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
    vector<TreeNode*> subTree(int start, int end){
        vector<TreeNode*> ans;

        if(end < start){
            ans.push_back(NULL);
            return ans;
        }

        for(int i = start; i <= end; i++){
            vector<TreeNode*> leftTree = subTree(start , i -1);
            vector<TreeNode*> rightTree = subTree(i+1, end);

            for(auto left : leftTree){
                for(auto right : rightTree){
                    TreeNode* root = new TreeNode(i);
                    root-> left = left;
                    root->right = right;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0){
            return {};
        }

        return subTree(1, n);
    }
};