class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        for(int i = 0; i < 9; i++) {
            unordered_set<char> s;

            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') {
                    continue;
                }

                if(s.count(board[i][j])) {
                    return false;
                }

                s.insert(board[i][j]);
            }
        }

        for(int j = 0; j < 9; j++) {
            unordered_set<char> s;

            for(int i = 0; i < 9; i++) {
                if(board[i][j] == '.') {
                    continue;
                }

                if(s.count(board[i][j])) {
                    return false;
                }

                s.insert(board[i][j]);
            }
        }

        for(int r = 0; r < 9; r += 3) {
            for(int c = 0; c < 9; c += 3) {
                unordered_set<char> s;

                for(int i = r; i < r + 3; i++) {
                    for(int j = c; j < c + 3; j++) {
                        if(board[i][j] == '.') {
                            continue;
                        }

                        if(s.count(board[i][j])) {
                            return false;
                        }

                        s.insert(board[i][j]);
                    }
                }
            }
        }

        return true;
    }
};