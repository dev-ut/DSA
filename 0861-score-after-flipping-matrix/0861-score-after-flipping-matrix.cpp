class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) 
    {
     int r=grid.size();
     int c=grid[0].size();
     // if the very starting cell is 0 
     for(int i=0;i<r;i++)
     {
        if(grid[i][0]==0) // cange all the 1to 0 0 to 1
        {
            for(int j=0;j<c;j++)
           {
            grid[i][j]=(grid[i][j]==0)? 1 :0;
           }
        }
        
     } 
     // if the no of 0 is more in any colum then to it will sum to less so chng eit too
     for(int j=0;j<c;j++)
     {
       int nz=0;
       int no=0;
       for(int i=0;i<r;i++)
       {
        if(grid[i][j]==0) nz++;
        else no++;
       }
       if(nz>no)
       {
        for(int i=0;i<r;i++)
       {
        if(grid[i][j]==0) grid[i][j]=1;
        else grid[i][j]=0;
       }
       }
     }

     // now binary form maximum sum 
     int sum=0;
     for(int i=0;i<r;i++)
     {
        int x=1;
        for(int j=c-1;j>=0;j--)
        {
            sum+=grid[i][j]*x;
            x=x*2;
        }
     }
     return sum;

    }
};