class Solution{
    public:
    vector<int>ans;
    
    vector<int>inorderTraversal(TreeNode* root){
        fun(root);
        return ans;
    }
    void fun(TreeNode* root){
        if(root==NULL){
            return;
        }
        fun(root->left);
        ans.push_back(root->val);
        fun(root->right);

    }

};