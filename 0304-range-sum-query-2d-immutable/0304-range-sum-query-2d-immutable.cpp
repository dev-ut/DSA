class NumMatrix {
public:
   int ans[205][205];  // just to store ans;
    NumMatrix(vector<vector<int>>& matrix) 
    {
        // calculating prefix sum
        ans[0][0] = matrix[0][0];
        for (int i = 1; i < matrix[0].size(); i++) ans[0][i] = ans[0][i - 1] + matrix[0][i]; // pehle row ki sum precompute
        for (int j = 1; j < matrix.size(); j++) ans[j][0] = ans[j - 1][0] + matrix[j][0]; // pehle colm ki sum  precompute
        // ab bche hue space matrix ka sum calculate krenge
        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[0].size(); j++) {
                ans[i][j] = matrix[i][j] + ans[i - 1][j] + ans[i][j - 1] - ans[i - 1][j - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) 
    {
        int del = 0;
        if (row1 != 0) del += ans[row1 - 1][col2];
        if (col1 != 0) del += ans[row2][col1 - 1];
        if (row1 != 0 && col1 != 0) del -= ans[row1 - 1][col1 - 1];
        return ans[row2][col2] - del;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */