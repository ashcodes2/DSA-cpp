class Solution {
public:

    bool check(TreeNode* p, TreeNode* q) {

        if (p == NULL && q == NULL) {
            return true;
        }

        if (p == NULL || q == NULL) {
            return false;
        }

        if (p->val != q->val) {
            return false;
        }

        bool r1 = check(p->left, q->right);
        bool r2 = check(p->right, q->left);

        if (r1 == true && r2 == true) {
            return true;
        }

        return false;
    }

    bool isSymmetric(TreeNode* root) {

        if (root == NULL) {
            return true;
        }

        return check(root->left, root->right);
    }
}; 