class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char, int> need, window;

        for(char c : t) {
            need[c]++;
        }

        int left = 0;
        int formed = 0;

        int start = 0;
        int minLen = INT_MAX;

        for(int right = 0; right < s.size(); right++) {

            window[s[right]]++;

            if(need.count(s[right]) &&
               window[s[right]] == need[s[right]]) {
                formed++;
            }

            while(formed == need.size()) {

                if(right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                if(need.count(s[left]) &&
                   window[s[left]] == need[s[left]]) {
                    formed--;
                }

                window[s[left]]--;
                left++;
            }
        }

        if(minLen == INT_MAX)
            return "";

        return s.substr(start, minLen);
    }
};