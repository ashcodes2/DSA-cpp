class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if (nums.empty()) return 0;
        
        int left=0;
        int right=left+1;
        int unique=1;
        while(right<nums.size()){
            if(nums[left]==nums[right]){

                  right++;
            }

            else{
                left++;
                nums[left]=nums[right];
                right++;
                unique++;
            
            }
            }

            return unique ;
        }
    
};