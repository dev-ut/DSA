class Solution {
public:
vector<vector<string>>fans;

bool isSafe(vector<string> &board,int row,int col,int n)
{
    // giving i nad j alg alg coz we cantd ierctly manipuldate the row and colm 
    int i=row-1;
    int j=col;
    // cjecking the overgread is quen is present in upper colm return false
    while(i>=0)
    {
        if(board[i][j]=='Q')return false;
        i--;
    }
    // checaking left diognal queen nhi honi chaiye 
    i=row-1;
    j=col-1;
    while(i>=0 && j>=0)
    {
        if(board[i][j]=='Q')return false;
        i--;
        j--;
    }
    //checking left digonal quuen nhi honi chaiye 
    i=row-1;
    j=col+1;
    while(i>=0 && j<n)
    {
        if(board[i][j]=='Q')return false;
        i--;
        j++;
    }
    return true ;
}

void solve(vector<string> &board,int row,int n)
{
    if(row==n)  // abse case ki last row main reach ho gya to ise vector main dalo
    {
        fans.push_back(board);
        return ;
    }
    // now we r going to traverse and place our queen in each colm and test it whterr it is possible it to place 
    // considering rules of chess baord ie no queen should be present overhead, left diognal and right diognal 
    for(int col=0;col<n;col++)
    {
        if(isSafe(board,row,col,n)==true)
        {
            // to bhiya is row col pr queen baitha do 
            board[row][col]='Q';
            solve(board,row+1,n);

            // when we cover all row and find false we backtrack 
             board[row][col]='.';
        }
    }
}
    vector<vector<string>> solveNQueens(int n) 
    {
        // constructing the board 
        vector<string>board(n,string(n,'.'));
        solve(board,0,n);
        return fans;
    }
};