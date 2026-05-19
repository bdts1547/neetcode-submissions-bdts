class Solution {
public:
    int ROW, COL, res = false;
    bool exist(vector<vector<char>>& board, string word) {
        ROW = board.size();
        COL = board[0].size();
        vector<vector<bool>> visited(ROW, vector<bool> (COL, false));
        for (int r = 0; r < ROW; r++) {
            for (int c = 0; c < COL; c++) {
                if (board[r][c] == word[0]) {
                    backtracking(board, word, 1, r, c, visited);
                    if (res) return res;
                }
            }
        }
        return false;
    }

    void backtracking( vector<vector<char>>& board, string word, int i, int r, int c,
    vector<vector<bool>>& visited) {
        if (i == word.size()) {
            res = true;
            return;
        }
        char temp = board[r][c];
        board[r][c] = '?'; // mark visited  

        if (i < word.size() && c + 1 < COL && board[r][c+1] == word[i] && !visited[r][c+1]) {
            backtracking(board, word, i+1, r, c+1, visited);
        }

        // right
        if (i < word.size() &&  c - 1 >= 0 && board[r][c-1] == word[i] && !visited[r][c-1]) {
            backtracking(board, word, i+1, r, c-1, visited);

        }

        // top
        if (i < word.size() &&  r-1 >= 0 && board[r-1][c] == word[i] && !visited[r-1][c]) {
            backtracking(board, word, i+1, r-1, c, visited);

        }

        // down
        if (i < word.size() &&  r+1 < ROW && board[r+1][c] == word[i] && !visited[r+1][c]) {
            backtracking(board, word, i+1, r+1, c, visited);
        }

        board[r][c] = temp;

    }
};