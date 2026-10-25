class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minending=nums[0];
        int maxending=nums[0];
        int ans=nums[0];

        for(int i=1;i<nums.size();i++){
            int v1=nums[i];
            int v2=nums[i]*minending;
            int v3=nums[i]*maxending;

            minending=min(v1,min(v2,v3));
            maxending=max(v1,max(v2,v3));

            ans=max(ans,max(minending,maxending));
        }
        return ans;
    }
};