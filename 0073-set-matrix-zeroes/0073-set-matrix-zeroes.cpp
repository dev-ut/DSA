class Solution {
public:
void setZeroes(vector<vector<int>>& matrix) 
{
    int r = matrix.size();
    int c = matrix[0].size();

    bool firstCol = false;

    // Step 1: mark rows and columns
    for (int i = 0; i < r; i++) {
        if (matrix[i][0] == 0) firstCol = true;

        for (int j = 1; j < c; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;   // mark row
                matrix[0][j] = 0;   // mark column
            }
        }
    }

    // Step 2: fill inner matrix using markers
    for (int i = 1; i < r; i++) {
        for (int j = 1; j < c; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    // Step 3: handle first row
    if (matrix[0][0] == 0) {
        for (int j = 0; j < c; j++) {
            matrix[0][j] = 0;
        }
    }

    // Step 4: handle first column
    if (firstCol) {
        for (int i = 0; i < r; i++) {
            matrix[i][0] = 0;
        }
    }
}
};
// tc:O(m*n)
//sc:O(1)