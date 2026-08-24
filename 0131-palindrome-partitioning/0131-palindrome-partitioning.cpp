#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // Helper function to verify palindrome
    bool isPalindrome(const string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

    // Pure recursive function returning partitions of s[start...]
    vector<vector<string>> partitionFrom(int start, const string& s) {
        // Base case: empty remaining string has 1 valid partition (the empty list)
        if (start == s.length()) {
            return {{}};
        }

        vector<vector<string>> result;

        for (int end = start; end < s.length(); ++end) {
            if (isPalindrome(s, start, end)) {
                string prefix = s.substr(start, end - start + 1);

                // Recursively get partitions for the rest of the string
                vector<vector<string>> subPartitions = partitionFrom(end + 1, s);

                // Prepend current palindrome prefix to each sub-partition result
                for (auto& sub : subPartitions) {
                    sub.insert(sub.begin(), prefix);
                    result.push_back(sub);
                }
            }
        }

        return result;
    }

    vector<vector<string>> partition(string s) {
        return partitionFrom(0, s);
    }
};