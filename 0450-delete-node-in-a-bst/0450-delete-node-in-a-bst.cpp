class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL)
            return NULL;
        if (root->val == key)
            return deleteThis(root);
        TreeNode* ans = root;
        while (root != NULL) {
            if (root->val > key) {
                if (root->left != NULL && root->left->val == key) {
                    root->left = deleteThis(root->left);
                    break;
                } else
                    root = root->left;
            } else {
                if (root->right != NULL && root->right->val == key) {
                    root->right = deleteThis(root->right);
                    break;
                } else
                    root = root->right;
            }
        }
        return ans;
    }

    TreeNode* deleteThis(TreeNode* root) {
        if (root->left == NULL)
            return root->right;
        else if (root->right == NULL)
            return root->left;
        TreeNode* rightChild = root->right;
        TreeNode* lastRight = findLastRight(root->left);
        lastRight->right = rightChild;
        return root->left;
    }

    TreeNode* findLastRight(TreeNode* root) {
        if (root->right == NULL)
            return root;
        return findLastRight(root->right);
    }
};
