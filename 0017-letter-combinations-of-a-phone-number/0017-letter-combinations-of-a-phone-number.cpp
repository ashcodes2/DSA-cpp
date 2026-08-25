class Solution {
public:
    vector<string> ans;
    
    unordered_map<char, string> mp = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    void solve(string &digits, int idx, string &temp) {
        
        // Base case
        if (idx == digits.size()) {
            ans.push_back(temp);
            return;
        }

        string letters = mp[digits[idx]];

        
        for (char ch : letters) {
            
            // Choose
            temp.push_back(ch);

            // Recursion
            solve(digits, idx + 1, temp);

            // Backtrack
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        
        if (digits.empty())
            return {};

        string temp = "";

        solve(digits, 0, temp);

        return ans;
    }
};