class Solution {
public:

    vector<vector<int>> ans;
    vector<int> path;

    void fun(TreeNode* root, int targetSum, int sum) {

        if(root == NULL){
            return;
        }

        sum += root->val;
        path.push_back(root->val);

        if(root->left == NULL && root->right == NULL){

            if(sum == targetSum){
                ans.push_back(path);
            }

            path.pop_back();
            return;
        }

        fun(root->left, targetSum, sum);
        fun(root->right, targetSum, sum);

        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        fun(root, targetSum, 0);

        return ans;
    }
};