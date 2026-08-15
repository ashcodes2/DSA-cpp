class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int max_prod = nums[0];
        int min_prod = nums[0];
        int result = nums[0];
        
        for (size_t i = 1; i < nums.size(); ++i) {
            int curr = nums[i];
            
            // If the current element is negative, multiplying by it 
            // swaps the largest product and the smallest product.
            if (curr < 0) {
                swap(max_prod, min_prod);
            }
            
            // The choices for the new max and min are:
            // 1. Start a new subarray at the current element
            // 2. Multiply the current element with the previous max/min
            max_prod = max(curr, max_prod * curr);
            min_prod = min(curr, min_prod * curr);
            
            // Keep track of the overall maximum product seen so far
            result = max(result, max_prod);
        }
        
        return result;
    }
};