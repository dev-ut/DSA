class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int r=matrix.size();
        int c=matrix[0].size();
        int lmp=c-1;
        int dmp=0;
        while(dmp<r && lmp>=0)
        {
            if(matrix[dmp][lmp]==target) return true;
            else if(matrix[dmp][lmp]>target) lmp--;
            else dmp++;
        }
        return false;
    }
};