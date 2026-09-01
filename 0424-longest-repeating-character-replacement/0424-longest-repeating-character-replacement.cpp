class Solution {
public:
    int characterReplacement(string s, int k) {

        unordered_map<char, int> mp;

        int left = 0;
        int maxFreq = 0;
        int ans = 0;

        for(int right = 0; right < s.size(); right++) {

            // Frequency increase
            mp[s[right]]++;

            // Maximum frequency in current window
            maxFreq = max(maxFreq, mp[s[right]]);

            // Window invalid
            while((right - left + 1) - maxFreq > k) {

                mp[s[left]]--;
                left++;
            }

            // Valid window
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};