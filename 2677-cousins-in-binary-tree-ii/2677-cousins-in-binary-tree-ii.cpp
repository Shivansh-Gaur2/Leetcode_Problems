class Solution {
public:
TreeNode* helper(TreeNode* root, vector<int>& levelSum){
    int level = 0;
    queue<TreeNode*>q;
    q.push(root);

    while(!q.empty()){
        int n = q.size();
        for(int i = 0 ;i < n; i++){
            TreeNode* curr = q.front();
            q.pop();
            int sibSum = (curr->left ? curr->left->val : 0)+ (curr->right ? curr->right->val : 0);
            if(level == 0) curr->val = 0;

            if(curr->left){
                q.push(curr->left);
                curr->left->val = levelSum[level+1] - sibSum;
            }
            if(curr->right){
                q.push(curr->right);
                curr->right->val = levelSum[level+1] - sibSum;
            }
        }
        level++;
    }
    return root;
}
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (!root) return nullptr;

        queue<TreeNode*> q;
        q.push(root);
        vector<int>levelSum;
        
        while (!q.empty()) {
            int n = q.size(); 
            int sum = 0;
            for (int i = 0; i < n; i++) {
                TreeNode* front = q.front();
                q.pop();
                
                sum += front->val;
                
                if (front->left) {
                    q.push(front->left);
                }
                if (front->right) {
                    q.push(front->right);
                }
            }
            
            levelSum.push_back(sum);  
        }

        for(int i = 0 ; i < levelSum.size(); i++){
            cout << levelSum[i] << " ";
        }


        return helper(root, levelSum);
    }
};
