class Solution {
public:
    int directions[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    bool dfs(vector<vector<char>>& board, string& word,
             int r, int c, int i) {

        if(i == word.size())
            return true;

        int rows = board.size();
        int cols = board[0].size();

        if(r < 0 || r >= rows || c < 0 || c >= cols ||
           board[r][c] != word[i])
            return false;

        char temp = board[r][c];
        board[r][c] = '#';  // mark visited

        for(auto& d : directions) {
            int nr = r + d[0];
            int nc = c + d[1];

            if(dfs(board, word, nr, nc, i + 1))
                return true;
        }

        board[r][c] = temp; // backtrack
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                if(dfs(board, word, r, c, 0))
                    return true;
            }
        }

        return false;
    }
};