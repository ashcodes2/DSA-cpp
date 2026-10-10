class Solution{
    public:
    vector<vector<int>>res;
    vector<vector<int>>levelOrder(TreeNode* root){
        if(root==NULL){
            return res;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int levelsize=q.size();
            vector<int>temp;
            while(levelsize--){
                TreeNode* t=q.front();
                q.pop();
                temp.push_back(t->val);
                if(t->left!=NULL){
                    q.push(t->left);
                } 
                if(t->right!=NULL){
                    q.push(t->right);
                }

            }

            res.push_back(temp);
      
      
        }
        
            return res;


    }

};