class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
      if(root==NULL){
        return false;
      }
      stack<TreeNode*>s1;
      stack<TreeNode*>s2;

      TreeNode* temp=root;
      while(temp!=NULL){
        s1.push(temp);
        temp=temp->left;
      }

      temp=root;
      while(temp!=NULL){
        s2.push(temp);
        temp=temp->right;
      }

      while(!s1.empty() && !s2.empty()){
        TreeNode* left=s1.top();
        TreeNode* right=s2.top();
        
        if(left==right){
            break;
        }

        int sum=left->val+right->val;
        if(sum==k){
            return true;
        }

        if(sum<k){
            s1.pop();
            temp=left->right;
            while(temp!=NULL){
                s1.push(temp);
                temp=temp->left;
            }
        }

         else{
            s2.pop();
            temp=right->left;
            while(temp!=NULL){
                s2.push(temp);
                temp=temp->right;
            }
        }
      }
      return false;

    }
};