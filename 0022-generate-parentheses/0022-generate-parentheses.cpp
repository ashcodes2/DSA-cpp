class Solution {
public:
    void backtrack(int open, int close, int n, string& temp, vector<string>& result) {
        // Base case
        if (open == n && close == n) {
            result.push_back(temp);
            return;
        }

        // Open 
        if (open < n) {
            temp.push_back('(');
            backtrack(open + 1, close, n, temp, result);
            temp.pop_back(); // Backtrack
        }

        // Close
        if (close < open) {
            temp.push_back(')');
            backtrack(open, close + 1, n, temp, result);
            temp.pop_back(); // Backtrack
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string temp = "";
        backtrack(0, 0, n, temp, result);
        return result;
    }
};