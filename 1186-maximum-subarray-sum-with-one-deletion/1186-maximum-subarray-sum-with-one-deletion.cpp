class Solution {
public:
    int maximumSum(vector<int>& nums) {
       int nodelete=nums[0];
       int onedelete=INT_MIN;
       int ans=nums[0];

       for(int i=1;i<nums.size();i++){

        int prevnodelete=nodelete;
        int prevonedelete=onedelete;
           nodelete=max(nums[i],nums[i]+nodelete);

           int v2;
           if(prevonedelete==INT_MIN){
            v2=nums[i];
           }
           else{
            v2=prevonedelete+nums[i];
           }

           onedelete=max(v2,prevnodelete);

           ans=max(ans,max(nodelete,onedelete));




       }
       return ans;
    }
};