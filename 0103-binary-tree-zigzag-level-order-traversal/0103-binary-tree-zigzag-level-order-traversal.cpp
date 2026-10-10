
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

       vector<vector<int>>res;
        bool leftToright=true;
       queue<TreeNode*>q;
       if(root==NULL){
        return res;
       }
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

        if(leftToright==false){
            reverse(temp.begin(),temp.end());
        }
        leftToright=!leftToright;
        res.push_back(temp);


       }
       return res;
    }
};