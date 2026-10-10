class Solution{
    public: 
    vector<int>ans;
    vector<int>preorderTraversal(TreeNode* root){
        fun(root);
        return ans;
    }
    void fun(TreeNode* root){
        if(root==NULL){
            return;
        }
        ans.push_back(root->val);
        fun(root->left);
        fun(root->right);
    }

};