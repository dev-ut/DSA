class Solution {
public:
    vector<vector<int>> generateMatrix(int n) 
    {
       vector<vector<int>>mat(n,vector<int>(n,0));  // built khali matrix
       int top=0;
       int bot=n-1;
       int left=0;
       int right=n-1;
       int no=1;

       while(top<=bot && left<=right)
       {

        // left to right
        for(int i=left;i<=right;i++)
        {
            mat[top][i]=no++;
        }
        top++;

        // tp to bottom 
        for(int i=top;i<=bot;i++)
        {
             mat[i][right]=no++;
        }
        right--;
        // right to left
        if(top<=bot)
        {
            for(int i=right;i>=left;i--)
            {
                mat[bot][i]=no++;
            }
        }
        bot--;
        // bottom to top
        if(left<=right)
        {
          for(int i=bot;i>=top;i--)
            {
                mat[i][left]=no++;
            }   
        }
        left++;
       }
       return mat;    
    }
};