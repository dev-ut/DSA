class NumMatrix {
public:
    vector<vector<int>> psum;

    NumMatrix(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        int m = matrix[0].size();

        psum = vector<vector<int>>(n, vector<int>(m, 0)); // resize

        // 1st: add all row individually and store cumulative row sum
        for(int i = 0; i < n; i++)
        {
            psum[i][0] = matrix[i][0];
            for(int j = 1; j < m; j++)
            {
                psum[i][j] = psum[i][j - 1] + matrix[i][j];
            }
        }

        // 2nd: add all columns on top of existing row sums
        for(int j = 0; j < m; j++)
        {
            for(int i = 1; i < n; i++)
            {
                psum[i][j] = psum[i - 1][j] + psum[i][j];
            }
        }

        // Now prefix sum matrix is ready
    }

    int sumRegion(int row1, int col1, int row2, int col2) 
    {
        int matrixans = psum[row2][col2];

        if(row1 > 0) matrixans -= psum[row1 - 1][col2];
        if(col1 > 0) matrixans -= psum[row2][col1 - 1];
        if(row1 > 0 && col1 > 0) matrixans += psum[row1 - 1][col1 - 1]; // diagonal overlap add back

        return matrixans;  // direct if r1,c1 == 0
    }
};


/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */