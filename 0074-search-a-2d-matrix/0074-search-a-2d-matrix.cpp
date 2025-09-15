class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
      int r=matrix.size();
      int c=matrix[0].size();
      // we willtry to give the negative index for every erlemnt and we  are goingto just acess it using row and col just see
      int lo=0;
      int hi=(r*c)-1;

      while(lo<=hi)
      {
        int mid=lo+(hi-lo)/2;
        int row=mid/c;
        int col=mid%c;
        if(matrix[row][col]==target) return true;
        else if(matrix[row][col]<target)
        {
            lo=mid+1;
        }
        else
        {
            hi=mid-1;
        }
      }
      return false;  
    }
};