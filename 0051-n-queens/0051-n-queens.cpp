class Solution {
public:
    vector<vector<string>> ans;

    // Check karo ki (row, col) par queen rakhna safe hai ya nahi
    bool isSafe(vector<string>& board, int row, int col, int n) 
    {
        // Same column ke upar check
        for (int i = 0; i < row; i++) 
        {
            if (board[i][col] == 'Q') return false;
        }

        // Upper left diagonal
        int i = row - 1, j = col - 1;
        while (i >= 0 && j >= 0) {
            if (board[i][j] == 'Q') return false;
            i--;
            j--;
        }

        // Upper right diagonal
        i = row - 1, j = col + 1;
        while (i >= 0 && j < n) {
            if (board[i][j] == 'Q') return false;
            i--;
            j++;
        }

        return true;
    }

    void solve(vector<string>& board, int row, int n) {
        // Base case: agar n queens place ho gayi
        if (row == n) {
            ans.push_back(board);
            return;
        }

        // Har column try karo is row ke liye
        for (int col = 0; col < n; col++) 
        {
            if (isSafe(board, row, col, n)==true) 
            {
                board[row][col] = 'Q';      // Queen rakh di
                solve(board, row + 1, n);   // Next row pe jao
                board[row][col] = '.';      // Backtrack
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.')); // n x n board with '.'
        solve(board, 0, n);
        return ans;
    }
};
