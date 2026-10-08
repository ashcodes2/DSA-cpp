class Solution {
public:

    bool solve(TreeNode* root, int targetSum, int sum) {

        if(root == NULL){
            return false;
        }

        sum += root->val;

        if(root->left == NULL && root->right == NULL){
            if(sum == targetSum){
                return true;
            }
            return false;
        }

        if(solve(root->left, targetSum, sum)){
            return true;
        }

        if(solve(root->right, targetSum, sum)){
            return true;
        }

        return false;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root, targetSum, 0);
    }
};