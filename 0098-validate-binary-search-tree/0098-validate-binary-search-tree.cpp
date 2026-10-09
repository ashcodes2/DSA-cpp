
class Solution {
public:
    TreeNode* prev = NULL;
    bool ans = true;

    void fun(TreeNode* root) {
        if (root == NULL) {
            return;
        }

        fun(root->left);

        if (prev != NULL && root->val <= prev->val) {
            ans = false;
            return;
        }

        prev = root;

        fun(root->right);
    }

    bool isValidBST(TreeNode* root) {
        fun(root);
        return ans;
    }
};
