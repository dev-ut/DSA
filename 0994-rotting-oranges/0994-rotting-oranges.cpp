class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int r=grid.size();
        int c=grid[0].size();
        queue<pair<int,int>>q;
        int time=0;
        
        // serach for first rotten orange
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==2) // if its rooten
                {
                    q.push({i,j});
                }
            }
        }
      // from that cell move in all direction 

      while(q.size()>0)
      {
        int size=q.size();
        bool have_rotten=false;
        // we can move in four direction

        for(int i=0;i<size;i++)
        {
           auto [row,col]=q.front();
           q.pop();

           // up 
           if(row-1>=0 && grid[row-1][col]==1)
           {
             q.push({row-1,col});
             grid[row-1][col]=2;
             have_rotten=true;
           }

            // down
           if(row+1<r && grid[row+1][col]==1)
           {
             q.push({row+1,col});
             grid[row+1][col]=2;
             have_rotten=true;
           }

            // left
           if(col-1 >=0 && grid[row][col-1]==1)
           {
             q.push({row,col-1});
             grid[row][col-1]=2;
             have_rotten=true;
           }

            // right
            if(col + 1 < c && grid[row][col + 1] == 1) 
            {
                    q.push({row, col + 1});
                    grid[row][col + 1] = 2;
                    have_rotten = true;
                }
        }
        if(have_rotten==true) time++ ;  // ie if in nay direction even a single orange is trndformed it is counted 
      }
    // ifa any orange is reamining return -1

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(grid[i][j]==1) return -1;
        }
    }

     return time; // taken to make entire grid roteen    

    }
};