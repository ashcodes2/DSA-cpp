class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // Pehli window ka sum nikala
        double sum = 0;
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }

        double maxSum = sum;

        //Window aage badhayi: naya add, purana minus
        for (int i = k; i < nums.size(); i++) {
            sum=sum+nums[i]-nums[i-k];
            maxSum = max(maxSum, sum);
        }

        //Last me average nikala
        return maxSum / k;
    }
};