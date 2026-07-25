class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int low = 1, high = *max_element(candies.begin(), candies.end());
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long childrenCount = 0;

            for (int candy : candies) {
                childrenCount += candy / mid;
            }

            if (childrenCount >= k) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};