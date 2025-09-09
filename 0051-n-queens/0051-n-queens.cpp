class Solution {
public:
    vector<vector<string>> ans;

    bool isSafe(vector<string> &board,int row,int col,int n)
    {
        // ab 3 condition spr it will be checked 

        // 1st upper colms m nhi hona chaiye koi queen 
        int i=row-1,j=col;
        while(i>=0)
        {
            if(board[i][j]=='Q') return false;
            i--;
        }

        // left diagonal m nhi hona chaiye koi queen 
        i=row-1,j=col-1;
        while(i>=0 && j>=0)
        {
            if(board[i][j]=='Q') return false;
            i--;
            j--;
        }

        // right diagonal m nhi hona chaiye koi queen 
        i=row-1,j=col+1;
        while(i>=0 && j<n)
        {
            if(board[i][j]=='Q') return false;
            i--;
            j++;
        }

        return true;
    }

    void solve(vector<string> &board,int row,int n)
    {
        if(row==n)
        {
            ans.push_back(board);
            return ;
        }

        // we will come and place q at every colmn and check whter it is safe or not 
        for(int col=0;col<n;col++)
        {
            if(isSafe(board,row,col,n)==true)
            {
                board[row][col]='Q';
                solve(board,row+1,n);

                // backtarck kre to wapas unmark kr do dot 
                board[row][col]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) 
    {
        // craeting board of char first 
        vector<string> board(n, string(n, '.')); 
        solve(board,0,n);
        return ans;
    }
};
